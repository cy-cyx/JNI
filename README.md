[官方文档](https://developer.android.google.cn/ndk/guides/cmake)

[工作手册](https://www.zybuluo.com/khan-lau/note/254724)

**1、何如生成头文件**

javah -classpath <路径> -d <输出路径> 类

例如：javah -classpath F:\JNI\app\build\intermediates\javac\debug\compileDebugJavaWithJavac\classes -d F:\JNI\app\src\main\cpp com.example.jni.CTransferJava

注意：

（1）class的路径，只需到包名之前 

（2）类，需要是.class文件 而不是.java文件 包名.类名

**2、从头文件就可以确定方法名**

注意：

（1）java方法转成C方法存在一定规则变化 例如：1 会变成 11

（2）使用extend"C"的作用，因为C++由于重载，编译后方法名会将参数一起进去，

加上extend"C",声明该方法名用C编辑，以保证在java代码去可以正确找到对应的方法名

**3、newObject 和 AllocObject 区别**

(1)AllocObject这是给对象分配了内存空间，并没有变量的初始化、构造方法的调用， 

newObject有对变量进行初始化，并调用指定的构造方法

(2)方法签名的获取 使用命令 Javap 

例如：javap -classpath F:\JNI\app\build\intermediates\javac\debug\compileDebugJavaWithJavac\classes -s com.example.jni.CTransferJava

(3)GetMethodID 获取构造函数 使用\<init\>代替 

**4、使用CMake要注意版本号 externalNativeBuild{}**


*以下为工程内的例子：*

TextCMake.cpp包含了最简单的Cmake例子

CTransferJava.cpp包含了C调Java的方法（包含几种情况）

（1）非静态native方法调用本对象中的方法

（2）调用java有基础类型返回值的情况

（3）调用java有类对象返回值的情况

（4）非静态native方法调用本对象中的静态方法

（5）非静态native方法调非本对象内的方法 使用NewObject构造

（6）非静态native方法调非本对象内的方法 使用AllocObject构造（区别就是否有初始化）

（7）静态native方法调本对象内方法（跟调非对象内的方法一样，都需要在底层构造出相应的对象）