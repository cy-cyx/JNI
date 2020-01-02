package com.example.jni;

import android.os.Bundle;
import android.util.Log;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // 1、测试最基本的使用
        Log.d("xx", "onCreate: " + TextCMake.getJniString());

        // 2、测试C语言调用java方法 有以下几种情况
        CTransferJava cTransferJava = new CTransferJava();

        /*
         *非静态native方法调用本对象中的方法
         */
        cTransferJava.transferJavaFun();

        /*
         *有返回值的情况
         */
        int i = cTransferJava.transferJavaFunReturnInt();
        Log.d("xx", "onCreate: 测试有返回值" + i);

        /*
         *返回值为类
         */
        CTransferTextClass cTransferTextClass = cTransferJava.transferJavaFunReturnObject();
        Log.d("xx", "onCreate: 测试有返回值，且为类" + cTransferTextClass.getString());

        /*
         *非静态native方法调用本对象中的静态方法
         */
        cTransferJava.transferJavaStatic();
        /*
         *非静态native方法调非本对象内的方法 使用NewObject构造
         */
        cTransferJava.transferJavaFunOutside();
        /*
         *非静态native方法调非本对象内的方法 使用AllocObject构造（区别就是否有初始化）
         */
        cTransferJava.transferJavaFunOutside_1();

        /*
         * 静态native方法调本对象内方法（跟调非对象内的方法一样，都需要在底层构造出相应的对象）
         */
        Log.d("xx", "onCreate: 静态native方法调用java方法");
        CTransferJava.staticTransferJavaFun();
    }
}
