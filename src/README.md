项目背景
------------
该工程的目的是将SysUserApi作为Nodejs的模块封装起来。

相关技术
----------
Nodejs native模块的编写需要学习V8引擎和nan。

一些参考文档：
* [V8概况](https://developers.google.com/v8/intro)，因为GFW的原因，这个
链接需要翻墙查看，这个链接里可以学习到V8的基本设计元素和如何使用。
* [V8 API](http://v8.paulfryzel.com/docs/master/)，这个API里需要重点
关注的是各种数据类型和它们之间的转换。
* [nan](https://github.com/nodejs/nan)，nan的API可以在这个链接里找到，
nan源码里有个doc目录，可以下载后离线查看。


SysUserApi相关的文件
---------
1. FtdcSysUserApi.h

	该文件包含两个类：
	
	CShfeFtdcSysUserApi：用于向服务器发起请求
	
	CShfeFtdcSysUserSpi：在接收到服务器的返回数据后，该类中的回调函数
	会被调用
	
2. FtdcSysUserApiStruct.h

	结构体定义文件，这些结构体会在FtdcSysUserApi.h中用到。

3. FtdcSysUserApiDataType.h
	
	类型定义文件，这些类型会在FtdcSysUserApiStruct.h中用到。

4. ccRYPTO.h, CDes.h, Cdes.cpp

	这几个文件的作用是在登录的时候加密用户密码

5. sysuserapi.dll, sysuserapi.lib

	这两个文件分别是sysuserapi的动态和静态库，在封装编译时会将这静态库
	编译进最终的结果。
	
	
封装相关的文件
----------
1. addon.cc
	该文件初始化nodejs模块

2. binding.gyp
	
	JSON格式的配置文件,node-gyp会读取该文件
	然后生成相应的工程并编译。

3. package.json
	
	在编写nodejs模块时需要这个文件来指定一些
	模块相关的信息，比如：模块名称、版本号、
	依赖项等等。
	
4. FtdcSysUserApi_Wrapper.h, FtdcSysUserApi_Wrapper.cc

	封装CShfeFtdcSysUserApi这个类
	
5. SysUserSpi.h, SysUserSpi.cc
	
	继承自CShfeFtdcSysUserSpi类，在封装的内部作为
	实际回调处理类。
	
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
	
	
如何编译
----------
命令行进入项目的根目录，执行以下命令：

<pre><code>
	npm install --verbose --arch=ia32 >info.txt
</code></pre>