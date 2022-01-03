package com.chn.opengl

import android.app.Application

/*
 * Description :
 * Attention:
 *
 * Created by CaiRuiQin on 22/1/3
 */
class MyApp: Application() {
    override fun onCreate() {
        super.onCreate()
        System.loadLibrary("learn-opengl")
    }
}