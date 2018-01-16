//
// Created by anna on 2017/11/8.
//

#include <android/log.h>
#include <jni.h>
#include "../jni/com_ndk_demo_Two.h"


#define LOG_TAG "Two"

#ifdef __cplusplus
extern "C" {

#include "two/headers/file1.h"
#endif
/*
 * Class:     com_ndk_demo_Two
 * Method:    stringFromOneLibrary
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_ndk_demo_Two_stringFromOneLibrary
        (JNIEnv *, jobject) {
    __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "JNI");

    const char *charData = "file1.c";
    printfString(charData);

}

#ifdef __cplusplus
}
#endif