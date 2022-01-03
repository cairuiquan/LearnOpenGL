package com.chn.opengl

import android.opengl.GLSurfaceView
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle

/*
 * Description :
 * Attention:
 *
 * Created by CaiRuiQin on 22/1/3
 */
class MainActivity : AppCompatActivity() {
    lateinit var surfaceView: GLSurfaceView
    lateinit var triangleRender: TriangleRender

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        surfaceView = GLSurfaceView(this)
        triangleRender = TriangleRender()
        surfaceView.setRenderer(triangleRender)
        setContentView(surfaceView)
    }

    override fun onDestroy() {
        super.onDestroy()
    }
}