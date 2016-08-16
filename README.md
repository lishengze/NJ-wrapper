## 项目背景

该工程的目的是将SysUserApi作为Nodejs的模块封装起来。

## 相关技术

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

### 5. libsysuserapi.so

	这个文件是sysuserapi的linux下的动态库文件，在封装编译时用到。


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

	封装CShfeFtdcSysUserApi这个类, 封装请求的api.
	使用Nan::ObjectWrap,将请求的字段封装，用于C++后台请求。
	JS -> Nan::ObjectWrap, V8-data -> C++


### 5. sysuserspi.h, sysuserspi.cpp

	继承自CShfeFtdcSysUserSpi类，在封装的内部作为实际回调处理类。
	sysuserspi.h, sysuserspi.cpp，运行在后台的线程环境中，无法直接将回调的数据进行V8封装，因此必须新建专门用于转换的V8线程用于转换。
	所以 sysuserspi 主要负责回调数据的收集，并将其传输到V8转换线程中。

6. SpiCFunc.h, SpiCFunc.cc

	SysUserSpi这个回调类中的函数调用时并不是
	在v8的主线程中调用，为了将回调的数据传送到
	js环境中，需要将线程切换到v8的主线程。
	这两个文件的作用就是定义uv_async_t对象和对应的
	处理函数。

7. SysUserApiStruct_JS.js

	FtdcSysUserApiStruct.h中定义的结构体需要
	在js中有相应的定义，这样js中发起服务请求时
	就可以填充请求内容。

8. test.js

	测试文件，在js中测试封装好的接口。


### 如何编译
参考[node-gyp](https://github.com/nodejs/node-gyp)
命令行进入项目的根目录，执行以下命令：

<pre><code>
	npm install --verbose --arch=ia32 >compile-info.txt
</code></pre>
或是
<pre><code>
	node-gyp build --verbose >compile-info.txt
</code></pre>

<pre><code>
	npm install --verbose --arch=ia32 >info.txt
</code></pre>

## 一些参考文档：
* [V8概况](https://developers.google.com/v8/intro)，因为GFW的原因，这个
链接需要翻墙查看，这个链接里可以学习到V8的基本设计元素和如何使用。
* [V8 API](http://v8.paulfryzel.com/docs/master/)，这个API里需要重点
关注的是各种数据类型和它们之间的转换。
* [nan](https://github.com/nodejs/nan)，nan的API可以在这个链接里找到，
nan源码里有个doc目录，可以下载后离线查看。
