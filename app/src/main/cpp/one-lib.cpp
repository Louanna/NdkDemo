//
// Created by anna on 2017/11/8.
//

#include <android/log.h>
#include <jni.h>
#include "../jni/com_ndk_demo_One.h"


#define LOG_TAG "One"

#ifdef __cplusplus
extern "C" {

//#include "one/headers/file1.h"
#endif
/*
 * Class:     com_ndk_demo_One
 * Method:    stringFromOneLibrary
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_ndk_demo_One_stringFromOneLibrary
        (JNIEnv *, jobject) {
    __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "JNI");

    const char *charData = "file1.c";
//    printfString(charData);

}

#ifdef __cplusplus
}
#endif