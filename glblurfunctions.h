#ifndef GLBLURFUNCTIONS_H
#define GLBLURFUNCTIONS_H

#include <QDebug>
#include <QString>
#include <QOpenGLShaderProgram>

#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLContext>
#include <QOffscreenSurface>

#include <QOpenGLTexture>
#include <QOpenGLFramebufferObject>
#include <QVector2D>

#include "vertex.h"


class GLBlurFunctions : protected QOpenGLFunctions
{
public:
    GLBlurFunctions();
    ~GLBlurFunctions();

    QImage blurImage(QImage imageToBlur, int radius, int blurType);

private:
    QOpenGLVertexArrayObject m_VertexArrayObject;
    QOpenGLShaderProgram *m_ShaderProgram;

    QOpenGLFramebufferObject *m_FrameBufferObject1;
    QOpenGLFramebufferObject *m_FrameBufferObject2;
    QOpenGLBuffer m_Buffer;
    QOpenGLTexture *m_Texture;

    QOffscreenSurface *m_Surface;
    QOpenGLContext *m_Context;
};

#endif // GLBLURFUNCTIONS_H
