package com.example.sl.testjniapp.JSHtmlDemo;

import android.annotation.SuppressLint;
import android.app.AlertDialog;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.webkit.JavascriptInterface;
import android.webkit.WebView;
import android.widget.Toast;

import com.example.sl.testjniapp.R;

/**
 * https://www.cnblogs.com/galibujianbusana/p/6511249.html
 * 附带的链接地址
 * 其中还需要学习的是android 中动态在html中注入js
 * https://www.aliyun.com/jiaocheng/48686.html  同类的还有很多
 */
public class HtmlAndroidActivtiy extends AppCompatActivity {
    WebView contentWebView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.html_android_activtiy);
        initView();
        initData();
    }

    private void initData() {

    }

    @SuppressLint("JavascriptInterface")
    private void initView() {
        contentWebView = (WebView) findViewById(R.id.webview);
        // 启用javascript
        contentWebView.getSettings().setJavaScriptEnabled(true);
        // 从assets目录下面的加载html
        contentWebView.loadUrl("file:///android_asset/android_html_demo.html");
        contentWebView.addJavascriptInterface(HtmlAndroidActivtiy.this,"android");


        //无参调用Js点击
        findViewById(R.id.button1).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 无参数调用
                contentWebView.loadUrl("javascript:javacalljs()");

            }
        });
        //有参调用Js点击
        findViewById(R.id.button2).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 传递参数调用
                contentWebView.loadUrl("javascript:javacalljswith(" + "'这里是调用js方法'" + ")");
            }
        });

    }

    @JavascriptInterface
    public void startFunction(){
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                Toast.makeText(HtmlAndroidActivtiy.this,"Toast",Toast.LENGTH_SHORT).show();
            }
        });
    }

    @JavascriptInterface
    public void startFunction(final String str){
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                new AlertDialog.Builder(HtmlAndroidActivtiy.this).setMessage("oooooooo").show();
            }
        });
    }

}
