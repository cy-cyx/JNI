#include <jni.h>

extern "C" JNIEXPORT jstring JNICALL Java_com_example_jni_TextCMake_getJniString
        (JNIEnv *env, jclass clazz) {
    return env->NewStringUTF("java");
};
