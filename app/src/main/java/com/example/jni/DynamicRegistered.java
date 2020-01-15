package com.example.jni;

public class DynamicRegistered {

    public void init() {
        System.loadLibrary("DynamicRegistered");
    }

    public native int getNumber();
}
