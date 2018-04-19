package com.example.sl.testjniapp.jniTestOne;

/**
 * Created by Administrator on 2018/4/19 0019.
 */
public class JniMethod {
    static{
        System.loadLibrary("JniMethodOne");
    }
    //native方法
    public static native String getNativeString(String s);

    public static native String getNativeNextString(String s);

    public static native String getNativeNextInt(int one,String str,int two,String strNext);
}
