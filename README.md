[官方文档](https://developer.android.google.cn/ndk/guides/cmake)

[工作手册](https://www.zybuluo.com/khan-lau/note/254724)

**1、何如生成头文件**

javah -classpath <路径> -d <输出路径> 类

注意：

（1）class的路径，只需到包名之前 

（2）类，需要是.class文件 而不是.java文件 包名.类名

**2、从头文件就可以确定方法名**

**3、newObject 和 AllocObject 区别**

(1)AllocObject这是给对象分配了内存空间，并没有变量的初始化、构造方法的调用， 

newObject有对变量进行初始化，并调用指定的构造方法

(2)方法签名的获取 使用命令 Javap 

(3)GetMethodID 获取构造函数 使用<init>代替 

**4、使用CMake要注意版本号 externalNativeBuild{}**


*以下为工程内的例子：*

TextCMake.cpp包含了最简单的Cmake例子

CTransferJava.cpp包含了C调Java的方法