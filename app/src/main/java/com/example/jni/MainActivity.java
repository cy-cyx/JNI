package com.example.jni;

import android.os.Bundle;
import android.util.Log;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.d("xx", "onCreate: " + TextCMake.getJniString());

        CTransferJava cTransferJava = new CTransferJava();
        cTransferJava.transferJavaFun();
        cTransferJava.transferJavaStatic();
        cTransferJava.transferJavaFunOutside();
    }
}
