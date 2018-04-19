package com.example.sl.testjniapp.jniTestOne;

/**
 * Created by Administrator on 2018/4/19 0019.
 */
public class JniMethodC {
    static{
        System.loadLibrary("JniMethodTwo");
    }
    //native方法
    public static native String getNativeCString(String s);

    public static native String getNativeCNextString(String s);

    public static native String getNativeCNextInt(int one,String str,int two,String strNext);
}
