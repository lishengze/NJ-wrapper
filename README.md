# 项目背景

该工程的目的是将SysUserApi作为Nodejs的模块封装起来。

# 相关技术

Nodejs native模块的编写需要学习V8引擎和nan。


## SysUserApi相关文件及其说明

### 1. FtdcSysUserApi.h

	该文件包含两个类：CShfeFtdcSysUserApi：请求api; CShfeFtdcSysUserSpi：回调api.

1. API中，从CreateFtdcSysUserApi到SubscribePartAccount的9个请求，都是用于初始化与后台的链接。这些请求与其对应的回调无法从源文件xml中获取其函数名和参数信息，需要手动封装。

2. 除了需要手动封装的api.其余的api都可以从源文件xml中获取api的核心信息名kernalFuncName, 对应的函数名、返回值、参数都是以同样的规律由kernalFuncName扩展而来。
	* 请求API：
		 virtual int ReqQry+kernalFuncName+Topic  (CShfeFtdcReqQry+kernalFuncName+Field * pReqQry+kernalFuncName, int nRequestID);
	* 实时回调API:
		 virtual void OnRtn+kernalFuncName+Topic (CShfeFtdcRtn+kernalFuncName+Field* pRtn+kernalFuncName);
	* 非实时回调API:
		 virtual void OnRsp+kernalFuncName+Topic (CShfeFtdcRspQry+kernalFuncName+Field* pRspQry+kernalFuncName,  CShfeFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

3. 请求api的函数参数包含两个部分，一个是请求相关的字段，一个是RequsetID. RequsetID被用来标记针对使用同一个请求接口的不同请求，nRequestID会在回调中被返回。这样使用同一个请求接口的不同请求只要RequestID不同，就可以得到相对应的回调信息。

4. 一个请求函数ReqFunction 对应一个非实时回调函数(RspFunction)和实时回调函数(RtnFunction)。
	* 实时回调API: 提出请求后，后台会不断的推送实时消息。
	* 非实时回调API: 提出请求后，后台将某一段时间的数据发送过来，这个时间段由请求字段指定，若是不指定时间段，后台会将所有的数据都发过来。回调中的pRspQry+kernalFuncName为有效字段信息。pRspInfo 为错误信息字段，若是回调信息出错则有效信息为	null，错误代码和错误信息会在pRspInfo中。nRequestID为请求时填入的nRequestID，用于标记不同的请求。bIsLast 标记是否是当前回调的最后一个数据字段，某些回调的信息很多需要分多次发送。

	与后台通讯的交互逻辑便是以这三类API接口为基础，基本没有改变。


### 2. FtdcSysUserApiStruct.h

	结构体定义文件。定义了请求，实时回调，非实时回调的信息字段。
* 请求字段:     	CShfeFtdcReqQry+kernalFuncName+Field;
* 实时回调字段:  	 CShfeFtdcRtn+kernalFuncName+Field;
* 非实时回调字段:  CShfeFtdcRspQry+kernalFuncName+Field;

### 3. FtdcSysUserApiDataType.h

	类型定义文件，这些类型被用于FtdcSysUserApiStruct.h。

### 4. ccRYPTO.h, CDes.h, Cdes.cpp

	这几个文件的作用是在登录的时候加密用户密码

### 5. sysuserapi.dll sysuserapi.lib

	这两个文件是FtdcSysUserApi.h对应的动态链接库，由后台人员提供，动态链接库的位数必须与封装平台对应的系统位数相同。


## 封装说明及其相关文件
	主要使用 nan 的api, 实现将C++ api与 JS api的互通使用。封装的最终结果为addon.node二进制文件。
	使用的逻辑是：JS(请求) -> addon.node -> C++(回调) -> addon.node -> JS

### 1. addon.cpp
	初始化一些用于封装的数据结构。
* 封装CShfeFtdcSysUserApi::CreateFtdcSysUserApi, CreateFtdcSysUserApi是CShfeFtdcSysUserApi中的静态方法，必须单独封装。
* 建立封装过程的日志文件，文件句柄为g_RunningResult_File, 文件名为 "log.txt"。
* 初始化用于回调时多线程间传递与存储的数据结构。

	编译后的结果输出于: ./build/Release/addon.node

### 2. binding.gyp
  参考[node-gyp](https://github.com/nodejs/node-gyp)
	JSON格式的配置文件, 主要是编译用到的源文件，库。node-gyp会读取该文件然后生成相应的工程并编译。

### 3. package.json

	在编写nodejs模块时需要这个文件来指定一些模块相关的信息，比如：模块名称、版本号、依赖项等等。

### 4. ftdcsysuserapi-wrapper.h, ftdcsysuserapi-wrapper.cpp

* 封装CShfeFtdcSysUserApi这个类, 封装用于请求的api.
* 使用Nan::ObjectWrap,将请求的字段封装，用于向C++后台发出请求。
* 封装好后，用js脚本向后台请求的内部逻辑就变成：JS -> [Nan::ObjectWrap, V8-data] -> C++
	
### 5. sysuserspi.h,sysuserspi.cpp; v8-transform-func.h, v8-transform-func.cpp.
* 基本结构
    1. sysuserspi.h ,sysuserspi.cpp 继承自CShfeFtdcSysUserSpi类，在封装的内部作为实际回调处理类。
	2. v8-transform-func.h, v8-transform-func.cpp, 对回调的数据进行封装完成与js的回调交互。
	    
* 线程间数据传输
	 1. sysuserspi.h, sysuserspi.cpp，运行在后台的线程环境中，无法直接将回调的数据进行V8封装，因此必须新建专门用于转换的V8线程用于转换。
	所以 sysuserspi 主要负责回调数据的收集，并将其传输到V8转换线程中。
	 2. sysuserspi线程与V8线程间依靠[libuv](http://docs.libuv.org/en/v1.x/)进行进程间的通信，libuv是nodejs底层的线程通信库，包含在nan中可以直接使用。libuv进程间通信是异步进行的，保证不会阻塞。而且使用libuv,sysuserspi线程只能唤醒v8线程中对应的转换api,不能传递数据,因为libuv只保证唤醒消息一定传送到，但消息附带的数据可能会丢失。这里我们将数据存储在全局性的变量中，用于线程间的传递。

	
* 回调中的多线程编程设计：
	 1. 客户端在和后台每建立一个连接(RegisterFront())， 后台便会创建一个回调线程。这样如果多个客户端连接到后台便会产生多个sysuserapi线程，但是V8转换线程是唯一的，多个sysuserapi线程的回调api对应着V8线程中唯一的api，而且很多请求的回调需要多次相应才能将数据传输完全，如果不做区分，V8线程会将不同线程的回调数据弄混，导致传输错误。所以在设计用于传输数据全局变量时，为每一个回调接口创建线程相关的存储区域。sysuserspi线程在传入数据到全局变量时也是传输到自己线程相关的区域中。
	
	 2. 具体多线程编程设计:
	    1. 在与后台建立连接(RegisterFront)，创建front-session时，获取一个全局性的线程id。并将其作为回调对象m_spi的一部分传送到后台。
	    2. sysuserspi线程被后台调用时，因为直接回调的数据在回调结束后会被销毁，所以创建新的空间将后台回调数据存储下来，再将其内存的句柄存储到id相关的空间中，并将线程id也存储到全局空间中，令v8对应api知晓有哪个线程进行了回调，最后唤醒v8线程中对应的转换api.
	    3. v8线程中的api被唤醒后，从全局id空间中获取有哪些线程进行了回调，然后根据id将对应的回调数据句柄地址从全局的变量中拷贝到本地新建的数据句柄空间中，再进行一一的转化。因为对全局句柄空间的访问时互斥的，将其内容拷贝到本地再转化就减少sysuserapi中对应api的等待时间。数据转化完后，边将本地申请的句柄空间和里面句柄所指向的内存空间都释放掉。
	    4. 所有全局变量的存储访问都是由一一对应的锁控制，防止造成空间污染。
	  

### 6. id-func.cpp, id-func.h

	通过一个全局queue维护id, 可以手动设置队列中id的数目，并使用全局锁来控制对队列的存储访问。

### 7. v8-transform-data.cpp, v8-transform-data.h
*  定义了sysuserspi线程用于唤醒v8线程api的全局异步消息，类型为uv_async_t.
*  定义了用于存储线程相关的回调数据的结构，使用的是map<id, queue<void**>>, 存储回调数据内存句柄的是queue<void** >, 使用map将其相关联。
*  定义了存储线程id的数据结构， 类型为 vector<id>。对vectcr<id>的访问和对map<id, queue<void**>>的访问时顺序的，先记录id到vector<id>，再将id相关的数据存储到map<id, queue<void**>>。
*  定义了访问全局变量的锁,类型为 uv_mutex_t。
*  上面的每一个变量都是api相关的，每一个api都有对应的一套数据结构。
*  InitV8Transformdata(), DeInitV8Transformdata()分别是对异步消息和全局锁的初始化以及析构。InitV8Transformdata() 在addon.cpp 被调用, DeInitV8Transformdata() 在SysUserSpi的析构函数中被调用。

### 8. charset-convert-windows.h, charset-convert-windows.cpp.
    字符串转换函数，回调函数中的数据时gb2312编码，后台无法直接显示，转换成utf-8编码。
    
### 9. tool-funciton.h, tool-function.cpp
    自定义的工具函数
    
### 10. SysUserApiStruct.js

	FtdcSysUserApiStruct.h中定义的结构体需要在js中有相应的定义，这样js中发起服务请求时
	就可以填充请求内容。

### 11. test.js, test-spi.js

	测试文件，在js中测试封装好的接口。

## 自动生成编译代码
	由于需要转换的接口过多，所以转换的代码基本都是在确定了转换逻辑后，用脚本文件自动生成的，脚本文件存放在file-generator中。
	请求与回调信息的来源为后台提供的xml文件。其中apps-xmltojson.js就是将xml转换成易于js文件访问的json文件。
	每次源文件xml发生变动，需要重新生成所有文件。执行auto.js 便可自动执行所有剩下的脚本文件，自动生成所有的编译文件。新生成的文件存放在new-file文件夹中。

### 如何编译
参考[node-gyp](https://github.com/nodejs/node-gyp)

命令行进入项目的根目录，执行以下命令:

```
npm install --verbose --arch=ia32 >compile-info.txt
```

或是

```
node-gyp build --verbose >compile-info.txt
```

编译给atom 或 electron 平台使用时，也就是我们项目的使用平台，需要指定编译平台为对应的electron版本。
可以参考这个[链接](http://www.jianshu.com/p/9ce7a9ccdc78) 或官方的 [Using Native Node Modules](https://electron.atom.io/docs/tutorial/using-native-node-modules/)

编译后的结果存放在build文件夹内。

## 一些参考文档：
* [V8概况](https://developers.google.com/v8/intro)，因为GFW的原因，这个
链接需要翻墙查看，这个链接里可以学习到V8的基本设计元素和如何使用。

* [V8 API](http://v8.paulfryzel.com/docs/master/)，这个API里需要重点
关注的是各种数据类型和它们之间的转换。
* [nan](https://github.com/nodejs/nan)，nan的API可以在这个链接里找到，
nan源码里有个doc目录，可以下载后离线查看。
