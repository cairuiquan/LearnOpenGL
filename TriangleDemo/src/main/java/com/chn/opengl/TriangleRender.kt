package com.chn.opengl

import android.opengl.GLSurfaceView
import javax.microedition.khronos.egl.EGLConfig
import javax.microedition.khronos.opengles.GL10

/*
 * Description : 
 * Attention:
 *
 * Created by CaiRuiQin on 22/1/3
 */
class TriangleRender: GLSurfaceView.Renderer {
    private var mInstanceId: Long

    init {
        mInstanceId = nativeCreateInstance()
    }

    override fun onSurfaceCreated(p0: GL10?, p1: EGLConfig?) {
        nativeOnSurfaceCreated(mInstanceId)
    }

    override fun onSurfaceChanged(p0: GL10?, width: Int, height: Int) {
        nativeOnSurfaceChanged(mInstanceId, width, height)
    }

    override fun onDrawFrame(p0: GL10?) {
        nativeOnDrawFrame(mInstanceId)
    }

    fun destroy() {
        nativeDestroy(mInstanceId)
    }

    private external fun nativeCreateInstance():Long

    private external fun nativeDestroy(instance: Long)

    private external fun nativeOnSurfaceCreated(instance: Long)

    private external fun nativeOnSurfaceChanged(instance: Long, width: Int, height: Int)

    private external fun nativeOnDrawFrame(instance: Long)
}