#include <jni.h>

//
// Created by Administrator on 2020/1/15 0015.
//
jint getNumberDynamic() {
    return 1;
}

int registerNativeMethods(JNIEnv *env) {

    JNINativeMethod methods[] = {
            {"getNumber", "()I", (void *) getNumberDynamic},
    };

    const char *className = "com/example/jni/DynamicRegistered";

    jclass clazz;

    clazz = env->FindClass(className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }

    if (env->RegisterNatives(clazz, methods, sizeof(methods) / sizeof(methods[0])) < 0) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}

// System.loadLibrary 调用后的回调
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = NULL;

    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }

    if (env == NULL) {
        return -1;
    }

    // 动态注册
    if (!registerNativeMethods(env)) {
        return -1;
    }

    return JNI_VERSION_1_6;
}

