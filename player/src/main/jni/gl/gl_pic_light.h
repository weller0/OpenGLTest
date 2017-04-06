#ifndef GL_PIC_LIGHT_H
#define GL_PIC_LIGHT_H

#include <GLES3/gl3.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gl/gl_base.h"
#include "bean/bean_base.h"
#include "log.h"


const char gCubeVertexShader[] =
        "#version 300 es                                                    \n"
        "layout (location = "STRV(SHADER_IN_POSITION)") in vec3 position;   \n"
        "layout (location = "STRV(SHADER_IN_TEX_COORDS)") in vec2 texCoord; \n"
        "out vec2 TexCoord;                                                 \n"
        "uniform mat4 projection;                                           \n"
        "uniform mat4 camera;                                               \n"
        "uniform mat4 transform;                                            \n"
        "void main() {                                                      \n"
        "  gl_Position = projection*camera*transform*vec4(position, 1.0);   \n"
        "  TexCoord = vec2(texCoord.s, 1.0-texCoord.t);                     \n"
        "}\n";

const char gCubeFragmentShader[] =
        "#version 300 es                        \n"
        "precision mediump float;               \n"
        "in vec2 TexCoord;                      \n"
        "uniform sampler2D tTexture;            \n"
        "out vec4 color;                        \n"
        "void main() {                          \n"
        "  color = texture(tTexture, TexCoord); \n"
        "}\n";
/*
const Point3 A = {-0.5, 0.5, 0.5};
const Point3 B = {-0.5, -0.5, 0.5};
const Point3 C = {0.5, -0.5, 0.5};
const Point3 D = {0.5, 0.5, 0.5};
const Point3 E = {-0.5, 0.5, -0.5};
const Point3 F = {-0.5, -0.5, -0.5};
const Point3 G = {0.5, -0.5, -0.5};
const Point3 H = {0.5, 0.5, -0.5};
const GLfloat cubeVertex[][12] = {
        {// 左
                F.x, F.y, F.z,
                E.x, E.y, E.z,
                B.x, B.y, B.z,
                A.x, A.y, A.z,
        },
        {// 前
                B.x, B.y, B.z,
                A.x, A.y, A.z,
                C.x, C.y, C.z,
                D.x, D.y, D.z,
        },
        {// 上
                A.x, A.y, A.z,
                E.x, E.y, E.z,
                D.x, D.y, D.z,
                H.x, H.y, H.z,
        },
        {// 下
                F.x, F.y, F.z,
                B.x, B.y, B.z,
                G.x, G.y, G.z,
                C.x, C.y, C.z,
        },
        {//右
                C.x, C.y, C.z,
                D.x, D.y, D.z,
                G.x, G.y, G.z,
                H.x, H.y, H.z,
        },
        {// 后
                G.x, G.y, G.z,
                H.x, H.y, H.z,
                F.x, F.y, F.z,
                E.x, E.y, E.z,
        },
};
const GLfloat cubeTexCoords[][8] = {
        {
                0.0, 0.0,
                0.0, 1.0,
                1.0, 0.0,
                1.0, 1.0,
        },
        {
                0.0, 0.0,
                0.0, 1.0,
                1.0, 0.0,
                1.0, 1.0,
        },
        {
                0.0, 0.0,
                0.0, 1.0,
                1.0, 0.0,
                1.0, 1.0,
        },
        {
                0.0, 0.0,
                0.0, 1.0,
                1.0, 0.0,
                1.0, 1.0,
        },
        {
                0.0, 0.0,
                0.0, 1.0,
                1.0, 0.0,
                1.0, 1.0,
        },
        {
                0.0, 0.0,
                0.0, 1.0,
                1.0, 0.0,
                1.0, 1.0,
        },
};*/

const GLfloat positions[][3] = {
        {
                0, 0, -2,
        },
        {
                3,  0, -8,
        },
        {
                -3,  0, -8,
        },
        {
                0,  3, -8,
        },
        {
                0,  -3, -8,
        },
        {
                -1, 1, -4,
        },
        {
                -1, -1, -4,
        },
        {
                1, 1, -4,
        },
        {
                1, -1, -4,
        },
};

class PicLight : public GLBase {
public:
    PicLight(TransformBean *transformBean);

    ~PicLight();

protected:
    void updateFrame(Bitmap *bmp);

    void createTexture();

    void updateVertex();

    void updateTexCoord();

    GLuint loadShader();

private:
    GLboolean bFirstFrame;
};

#endif //GL_PIC_LIGHT_H