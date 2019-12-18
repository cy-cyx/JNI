package com.example.jni;

/**
 * create by cy
 * time : 2019/12/18
 * version : 1.0
 * Features :
 */
public class TextCMake {

    static {
        System.loadLibrary("TextCMake");
    }

    public static native String getJniString();
}
