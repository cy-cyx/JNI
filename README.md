[官方文档](https://developer.android.google.cn/ndk/guides/cmake)

[工作手册](https://www.zybuluo.com/khan-lau/note/254724)

1、何如生成头文件

javah -classpath <路径> -d <输出路径> 类

注意：

（1）class的路径，只需到包名之前 

（2）类，需要是.class文件 而不是.java文件 包名.类名

2、从头文件就可以确定方法名