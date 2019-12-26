package com.example.jni;

import android.util.Log;

/**
 * create by cy
 * time : 2019/12/26
 * version : 1.0
 * Features :
 */
public class CTransferJavaOutside {

    int a = 1;

    public CTransferJavaOutside(int a) {
        this.a = a;
    }

    public void callFun() {
        Log.d("xx", "callFun: 调用外类的方法" + a);
    }
}
