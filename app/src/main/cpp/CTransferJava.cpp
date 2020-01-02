#include <jni.h>

extern "C" JNIEXPORT void JNICALL
Java_com_example_jni_CTransferJava_transferJavaFun(JNIEnv *jniEnv, jobject object) {

    //注意：方法路劲要用 ”/“ 不能使用 ”.“
    jclass clazz = jniEnv->FindClass("com/example/jni/CTransferJava");

    // 第二个参数：方法名
    // 第三个参数：方法签名
    jmethodID jmethodId = jniEnv->GetMethodID(clazz, "callFun", "()V");
    jniEnv->CallVoidMethod(object, jmethodId);
}

extern "C" JNIEXPORT jint JNICALL
Java_com_example_jni_CTransferJava_transferJavaFunReturnInt(JNIEnv *jniEnv, jobject object) {
    //注意：方法路劲要用 ”/“ 不能使用 ”.“
    jclass clazz = jniEnv->FindClass("com/example/jni/CTransferJava");

    // 第二个参数：方法名
    // 第三个参数：方法签名
    jmethodID jmethodId = jniEnv->GetMethodID(clazz, "callFunReturnInt", "()I");
    // 使用有返回值的java方法
    return jniEnv->CallIntMethod(object, jmethodId);
}

extern "C" JNIEXPORT jobject JNICALL
Java_com_example_jni_CTransferJava_transferJavaFunReturnObject(JNIEnv *jniEnv, jobject object) {
    //注意：方法路劲要用 ”/“ 不能使用 ”.“
    jclass clazz = jniEnv->FindClass("com/example/jni/CTransferJava");

    // 第二个参数：方法名
    // 第三个参数：方法签名
    jmethodID jmethodId = jniEnv->GetMethodID(clazz, "callFunReturnObject",
                                              "()Lcom/example/jni/CTransferTextClass");
    // 使用有返回值的java方法
    return jniEnv->CallObjectMethod(object, jmethodId);
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_jni_CTransferJava_transferJavaFunOutside(JNIEnv *jniEnv, jobject object) {
    jclass clazz = jniEnv->FindClass("com/example/jni/CTransferJavaOutside");

    jmethodID jmethodId = jniEnv->GetMethodID(clazz, "callFun", "()V");

    // NewObject() 新建一个对象并且调用构造函数 和AllocObject() 仅仅是新建对象(即分配内存空间)
    // jobject clazzobj = jniEnv->AllocObject(clazz);
    // 见：同名方法_1

    jmethodID init = jniEnv->GetMethodID(clazz, "<init>", "(I)V");

    jobject clazzobj = jniEnv->NewObject(clazz, init, 2);

    jniEnv->CallVoidMethod(clazzobj, jmethodId);
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_jni_CTransferJava_transferJavaFunOutside_11(JNIEnv *jniEnv, jobject) {
    jclass clazz = jniEnv->FindClass("com/example/jni/CTransferJavaOutside");

    jmethodID jmethodId = jniEnv->GetMethodID(clazz, "callFun", "()V");
    jobject clazzobj = jniEnv->AllocObject(clazz);
    jniEnv->CallVoidMethod(clazzobj, jmethodId);
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_jni_CTransferJava_transferJavaStatic(JNIEnv *jniEnv, jobject) {
    jclass clazz = jniEnv->FindClass("com/example/jni/CTransferJava");

    // 找静态方法
    jmethodID jmethodId = jniEnv->GetStaticMethodID(clazz, "callStaticFun", "()V");
    jniEnv->CallStaticVoidMethod(clazz, jmethodId);
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_jni_CTransferJava_staticTransferJavaFun(JNIEnv *jniEnv, jclass clazz) {
    jmethodID jmethodId = jniEnv->GetMethodID(clazz, "callFun", "()V");
    jobject clazzobj = jniEnv->AllocObject(clazz);
    jniEnv->CallVoidMethod(clazzobj, jmethodId);
}