package com.example.sl.testjniapp.TestJniProject;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.example.sl.testjniapp.R;

import static com.example.sl.testjniapp.jniTestOne.JniMethodC.getNativeCNextInt;
import static com.example.sl.testjniapp.jniTestOne.JniMethodC.getNativeCString;

/**
 * Created by Administrator on 2018/4/19 0019.
 */
public class TestJniMainActivity extends Activity {
    TextView jni_method_tv;
    TextView getJnimethod_tv;
    TextView jni_method_tv1;
    TextView getJnimethod_tv1;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.testjnimain_activity);
        initView();
        initData();
    }

    private void initData() {
    }

    private void initView() {
//        jni_method_tv= (TextView) findViewById(R.id.jni_method_tv);
//        getJnimethod_tv= (TextView) findViewById(R.id.getJnimethod_tv);
//        jni_method_tv.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                getJnimethod_tv.setText(getNativeString("tishi"));
//            }
//        });
//
//        jni_method_tv1= (TextView) findViewById(R.id.jni_method_tv1);
//        getJnimethod_tv1= (TextView) findViewById(R.id.getJnimethod_tv1);
//        jni_method_tv1.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
////                getJnimethod_tv.setText(getNativeNextString("tishi"));
//                getJnimethod_tv.setText(getNativeNextInt(1,"tishi",2,"ddd"));
//            }
//        });


        jni_method_tv= (TextView) findViewById(R.id.jni_method_tv);
        getJnimethod_tv= (TextView) findViewById(R.id.getJnimethod_tv);
        jni_method_tv.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                getJnimethod_tv.setText(getNativeCString("tishi"));
            }
        });

        jni_method_tv1= (TextView) findViewById(R.id.jni_method_tv1);
        getJnimethod_tv1= (TextView) findViewById(R.id.getJnimethod_tv1);
        jni_method_tv1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
//                getJnimethod_tv.setText(getNativeNextString("tishi"));
                getJnimethod_tv.setText(getNativeCNextInt(1,"aaaaaa",2,"ddd"));
            }
        });
    }
}
