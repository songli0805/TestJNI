//
// Created by Administrator on 2018/4/19 0019.
//

# include "com_example_sl_testjniapp_jniTestOne_JniMethod.h"
# include <stdio.h>
# include <string.h>

JNIEXPORT jstring JNICALL Java_com_example_sl_testjniapp_jniTestOne_JniMethod_getNativeString
        (JNIEnv *env, jclass, jstring){
    return env->NewStringUTF((char *)"Hello JNI !");
}

JNIEXPORT jstring JNICALL Java_com_example_sl_testjniapp_jniTestOne_JniMethod_getNativeNextString
        (JNIEnv *env, jclass, jstring str){
    //将jstring转换成const char*指针，使用const修饰符表示其内容不可被修改
//    const char* c1=env->GetStringUTFChars(str, false);
//    const char* c2=env->GetStringUTFChars((char*)"这是另外的尝试",false);
//    //计算西字符串长度
//    int size=strlen(c1)+strlen(c2);
//    //创建一个新的字符串，这里长度+1是为了使字符串有结尾标记'\0'
//    char * n_char=new char[size+1];
//    //利用C标准库提供的字符串操作方法对字符串进行连接，这里需要include"string.h"头文件
//    strcpy(n_char, c1);
//    strcat(n_char, c2);
//    //将生成的新字符串转换成UTF的jstring
//    jstring rs=env->NewStringUTF(n_char);
//    //删除刚刚分配的内存 避免引起内存泄漏
//    delete[] n_char;
//
//    //释放指针
//    env->ReleaseStringUTFChars(str, c1);
//    return rs;

//
//    char*   rtn   ;
//
//    jclass   clsstring   =   env1->FindClass("java/lang/String");
//    jstring   strencode   =   env1->NewStringUTF("GB2312");
//    jmethodID   mid   =   env1->GetMethodID(clsstring,   "getBytes",   "(Ljava/lang/String;)[B");
//    jbyteArray   barr=   (jbyteArray)env1->CallObjectMethod(jstr,mid,strencode);
//    jsize   alen   =   env1->GetArrayLength(barr);
//    jbyte*   ba   =   env1->GetByteArrayElements(barr,JNI_FALSE);
//    if(alen   >   0)
//    {
//        rtn   =   (char*)malloc(alen+1);
//        memcpy(rtn,ba,alen);
//        rtn[alen]=0;
//    }
//    env1->ReleaseByteArrayElements(barr,ba,0);
//    std::string stemp(rtn);
//    free(rtn);
//    return   "stemp";

}

JNIEXPORT jstring JNICALL Java_com_example_sl_testjniapp_jniTestOne_JniMethod_getNativeNextInt
        (JNIEnv *env, jclass, jint, jstring, jint, jstring){
    return env->NewStringUTF((char *)"Hello JNI !dddddd");
}