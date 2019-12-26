package com.example.jni;

import android.util.Log;

/**
 * create by cy
 * time : 2019/12/26
 * version : 1.0
 * Features :
 */
public class CTransferJava {

    static {
        System.loadLibrary("CTransferJava");
    }

    public native void transferJavaFun();

    public native void transferJavaFunOutside();

    public native void transferJavaStatic();

    public static void callStaticFun() {
        Log.d("xx", "staticFun: 调用静态方法");
    }

    public void callFun() {
        Log.d("xx", "callFun: 调用本对象中的方法");
    }
}
