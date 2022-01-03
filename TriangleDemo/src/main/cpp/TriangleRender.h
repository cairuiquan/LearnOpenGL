//
// Created by CaiRuiQin on 22/1/3.
//

#ifndef LEARN_OPENGL_TRIANGLERENDER_H
#define LEARN_OPENGL_TRIANGLERENDER_H

#include <jni.h>

namespace chn {
class TriangleRender {
public:
    TriangleRender() {}
    ~TriangleRender() {}

    void onSurfaceCreated();
    void onSurfaceChanged(int width, int height);
    void onDrawFrame();
};
} // namespace chn

#endif //LEARN_OPENGL_TRIANGLERENDER_H
