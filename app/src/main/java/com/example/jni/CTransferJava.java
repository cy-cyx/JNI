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

    public native int transferJavaFunReturnInt();

    public native CTransferTextClass transferJavaFunReturnObject();

    public native void transferJavaFunOutside();

    public native void transferJavaFunOutside_1();

    public native void transferJavaStatic();

    public native static void staticTransferJavaFun();

    public static void callStaticFun() {
        Log.d("xx", "staticFun: 调用静态方法");
    }

    /**
     * 用于测试返回值为基础类型的情况
     */
    public int callFunReturnInt() {
        return 2020;
    }

    /**
     * 用于测试返回为类的情况
     */
    public CTransferTextClass callFunReturnObject() {
        return new CTransferTextClass();
    }

    public void callFun() {
        Log.d("xx", "callFun: 调用本对象中的方法");
    }
}
