#include "glblurfunctions.h"

static const Vertex sg_vertexes[] =
{
  Vertex( QVector3D( 1.0f,  1.0f, 1.0f)),
  Vertex( QVector3D(-1.0f,  1.0f, 1.0f)),
  Vertex( QVector3D(-1.0f, -1.0f, 1.0f)),
  Vertex( QVector3D( 1.0f, -1.0f, 1.0f))
};

GLBlurFunctions::GLBlurFunctions()
{
    m_Context = new QOpenGLContext();
    m_Context->setFormat(QSurfaceFormat::defaultFormat());
    m_Context->create();

    m_Surface = new QOffscreenSurface();
    m_Surface->create();
    m_Surface->setFormat(m_Context->format());

    m_Context->makeCurrent(m_Surface);

    initializeOpenGLFunctions();

    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);

    m_ShaderProgram = new QOpenGLShaderProgram();
    m_ShaderProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/simple.vert");
    m_ShaderProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/simple.frag");
    m_ShaderProgram->link();
    m_ShaderProgram->bind();

    m_Buffer.create();
    m_Buffer.bind();
    m_Buffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_Buffer.allocate(sg_vertexes, sizeof(sg_vertexes));

    m_VertexArrayObject.create();
    m_VertexArrayObject.bind();

    m_ShaderProgram->enableAttributeArray(0);
    m_ShaderProgram->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());

    m_Texture = new QOpenGLTexture(QImage());

    m_FrameBufferObject1 = new QOpenGLFramebufferObject(QSize(1, 1), QOpenGLFramebufferObject::CombinedDepthStencil, GL_TEXTURE_2D);
    m_FrameBufferObject2 = new QOpenGLFramebufferObject(QSize(1, 1), QOpenGLFramebufferObject::CombinedDepthStencil, GL_TEXTURE_2D);
}

GLBlurFunctions::~GLBlurFunctions()
{
    delete m_ShaderProgram;
    delete m_FrameBufferObject1;
    delete m_FrameBufferObject2;
    delete m_Texture;
}

QImage GLBlurFunctions::blurImage(QImage imageToBlur, int radius, int blurType)
{
    delete m_FrameBufferObject1;
    delete m_FrameBufferObject2;
    delete m_Texture;

    m_FrameBufferObject1 = new QOpenGLFramebufferObject(imageToBlur.size(), QOpenGLFramebufferObject::CombinedDepthStencil, GL_TEXTURE_2D);
    m_FrameBufferObject2 = new QOpenGLFramebufferObject(imageToBlur.size(), QOpenGLFramebufferObject::CombinedDepthStencil, GL_TEXTURE_2D);

    m_Texture = new QOpenGLTexture(imageToBlur.mirrored());
    m_Texture->setWrapMode(QOpenGLTexture::ClampToEdge);
    m_Texture->setMinMagFilters(QOpenGLTexture::Linear, QOpenGLTexture::Linear);

    //Set up to copy the image FROM the m_Texture texture (original image) TO the buffer1 texture
    m_FrameBufferObject1->bind();
    m_Texture->bind();

    m_ShaderProgram->setUniformValue("blurType", blurType);
    m_ShaderProgram->setUniformValue("direction", QVector2D(0.0, 0.0));
    m_ShaderProgram->setUniformValue("iResolution", QVector2D(imageToBlur.width(), imageToBlur.height()));

    //Copy the image to the buffer1 texture
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLE_FAN, 0, sizeof(sg_vertexes) / sizeof(sg_vertexes[0]));

    while (radius > 0)
    {
        //Blurring horizontally ------------------------------------------------------------

        m_ShaderProgram->setUniformValue("direction", QVector2D(radius, 0.0));      
        
        //Set up to copy the image FROM the buffer2 texture TO the buffer1 texture
        //while blurring it horizontally
        m_FrameBufferObject2->bind();
        QOpenGLFunctions::glBindTexture(GL_TEXTURE_2D, m_FrameBufferObject1->texture());        

        //Do the rendering
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLE_FAN, 0, sizeof(sg_vertexes) / sizeof(sg_vertexes[0]));


        //Blurring vertically --------------------------------------------------------------

        m_ShaderProgram->setUniformValue("direction", QVector2D(0.0, radius));
      
        //Set up to copy the image FROM the buffer1 texture TO the buffer2 texture
        //while blurring it vertically
        m_FrameBufferObject1->bind();
        QOpenGLFunctions::glBindTexture(GL_TEXTURE_2D, m_FrameBufferObject2->texture());

        //Do the rendering
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLE_FAN, 0, sizeof(sg_vertexes) / sizeof(sg_vertexes[0]));


        //Decrease our blur radius and start the blurring again
        radius--;
    }

    return m_FrameBufferObject1->toImage();
}
