//
// Created by Administrator on 2018/4/19 0019.
//

# include "com_example_sl_testjniapp_jniTestOne_JniMethodC.h"
# include <stdio.h>
# include <string.h>

JNIEXPORT jstring JNICALL Java_com_example_sl_testjniapp_jniTestOne_JniMethodC_getNativeCString
        (JNIEnv *env, jobject obj, jstring str){
    return (*env)->NewStringUTF(env, "Hello from JNI !");;
};

/*
 * Class:     com_example_sl_testjniapp_jniTestOne_JniMethodC
 * Method:    getNativeCNextString
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_sl_testjniapp_jniTestOne_JniMethodC_getNativeCNextString
        (JNIEnv *env, jobject obj, jstring str){
    return (*env)->NewStringUTF(env, "Hello from JNI !");;
};

/*
 * Class:     com_example_sl_testjniapp_jniTestOne_JniMethodC
 * Method:    getNativeCNextInt
 * Signature: (ILjava/lang/String;ILjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_sl_testjniapp_jniTestOne_JniMethodC_getNativeCNextInt
        (JNIEnv *env, jobject obj, jint b, jstring jstr, jint a, jstring str1){

    char*   rtn   =   NULL;
    jclass   clsstring   =   (*env)->FindClass(env,"java/lang/String");
    jstring   strencode   =   (*env)->NewStringUTF(env,"GB2312");
    jmethodID   mid   =   (*env)->GetMethodID(env,clsstring,   "getBytes",   "(Ljava/lang/String;)[B");
    jbyteArray   barr=   (jbyteArray)(*env)->CallObjectMethod(env,jstr,mid,strencode); // String .getByte("GB2312");
    jsize   alen   =   (*env)->GetArrayLength(env,barr);
    jbyte*   ba   =   (*env)->GetByteArrayElements(env,barr,JNI_FALSE);
    if(alen   >   0)
    {
        rtn   =   (char*)malloc(alen+1);         //"\0"
        memcpy(rtn,ba,alen);
        rtn[alen]=0;
    }
    (*env)->ReleaseByteArrayElements(env,barr,ba,0);  //
//    char* p =  Jstring2CStr(env,str);
    char* newstr = "--ccccc";

//    strcat(rtn, newstr);    // 把newstr字符串添加到p字符串的后面

    return (*env)->NewStringUTF(env, strcat(rtn,newstr));
//    return (*env)->NewStringUTF(env, "Hello from JNI !11111");;
};


//把java的字符串转换成c的字符串
char*   Jstring2CStr(JNIEnv*   env,   jstring   jstr)
{
    char*   rtn   =   NULL;
    jclass   clsstring   =   (*env)->FindClass(env,"java/lang/String");
    jstring   strencode   =   (*env)->NewStringUTF(env,"GB2312");
    jmethodID   mid   =   (*env)->GetMethodID(env,clsstring,   "getBytes",   "(Ljava/lang/String;)[B");
    jbyteArray   barr=   (jbyteArray)(*env)->CallObjectMethod(env,jstr,mid,strencode); // String .getByte("GB2312");
    jsize   alen   =   (*env)->GetArrayLength(env,barr);
    jbyte*   ba   =   (*env)->GetByteArrayElements(env,barr,JNI_FALSE);
    if(alen   >   0)
    {
        rtn   =   (char*)malloc(alen+1);         //"\0"
        memcpy(rtn,ba,alen);
        rtn[alen]=0;
    }
    (*env)->ReleaseByteArrayElements(env,barr,ba,0);  //
    return rtn;
}
