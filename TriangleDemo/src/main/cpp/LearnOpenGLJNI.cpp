//
// Created by CaiRuiQin on 1/2/22.
//

#include <jni.h>
#include <MyLogger.h>
#include "TriangleRender.h"

namespace {
    inline jlong jptr(chn::TriangleRender *demo) {
        return reinterpret_cast<intptr_t>(demo);
    }

    inline chn::TriangleRender* native(jlong ptr) {
        return reinterpret_cast<chn::TriangleRender*>(ptr);
    }
} // anonymous namespace

extern "C" {
JNIEXPORT jlong JNICALL nativeCreateInstance(JNIEnv *env, jobject obj)
{
    LOGD("");
    return jptr(new chn::TriangleRender());
}

JNIEXPORT void JNICALL nativeDestroy(JNIEnv *env, jobject obj, jlong instance)
{
    LOGD("");
    delete native(instance);
}

JNIEXPORT void JNICALL nativeOnSurfaceCreated(JNIEnv *env, jobject obj, jlong instance)
{
    LOGD("");
    chn::TriangleRender *render = native(instance);
    render->onSurfaceCreated();
}

JNIEXPORT void JNICALL nativeOnSurfaceChanged(JNIEnv *env, jobject obj, jlong instance,
                                              jint width, jint height)
{
    LOGD("");
    chn::TriangleRender *render = native(instance);
    render->onSurfaceChanged(width, height);
}

JNIEXPORT void JNICALL nativeOnDrawFrame(JNIEnv *env, jobject obj, jlong instance)
{
    chn::TriangleRender *render = native(instance);
    render->onDrawFrame();
}

} // extern "C"

namespace {
static const char *gClassPathName = "com/chn/opengl/TriangleRender";
static JNINativeMethod gMethods[] = {
    {"nativeCreateInstance","()J", (void *)(nativeCreateInstance)},
    {"nativeDestroy", "(J)V",(void *)(nativeDestroy)},
    {"nativeOnSurfaceCreated", "(J)V", (void *)(nativeOnSurfaceCreated)},
    {"nativeOnSurfaceChanged", "(JII)V", (void *)(nativeOnSurfaceChanged)},
    {"nativeOnDrawFrame", "(J)V", (void *)(nativeOnDrawFrame)}
};

static int registerNativeMethods(JNIEnv *env, const char *className, JNINativeMethod *methods,
                                 int numMethods) {
    jclass clazz;
    clazz = env->FindClass(className);
    if (clazz == nullptr) {
        LOGE("FindClass fail");
        return JNI_FALSE;
    }
    if (env->RegisterNatives(clazz, methods, numMethods) < 0) {
        LOGE("RegisterNatives fail");
        return JNI_FALSE;
    }
    return JNI_TRUE;
}
static int unregisterNativeMethods(JNIEnv *env, const char *className) {
    jclass clazz;
    clazz = env->FindClass(className);
    if (clazz == nullptr) {
        LOGE("FindClass fail");
        return JNI_FALSE;
    }
    env->UnregisterNatives(clazz);
}

}

extern "C" {

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *p) {
    jint result = -1;
    JNIEnv *env = nullptr;
    if (vm->GetEnv((void**)&env, JNI_VERSION_1_4) != JNI_OK) {
        LOGE("GetEnv fail");
        goto finish;
    }
    if (registerNativeMethods(env, gClassPathName, gMethods, sizeof(gMethods) / sizeof(gMethods[0])) != JNI_TRUE) {
        LOGE("registerNativeMethods fail");
        goto finish;
    }
    result = JNI_VERSION_1_4;
finish:
    LOGD(" result:%d", result);
    return result;
}

void JNI_OnUnload(JavaVM *vm, void *p) {
    LOGD("");
    JNIEnv *env = nullptr;
    if (vm->GetEnv((void**)&env, JNI_VERSION_1_4) != JNI_OK) {
        LOGE("GetEnv fail");
        return;
    }
    unregisterNativeMethods(env, gClassPathName);
}

} // extern "C"
