#include <GL/glew.h>
#include <GL/freeglut.h>

void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, .0f, .0f);
    glRectf(-25.0f, 25.0f, 25.0f, -25.0f);
    
    // glFlush();
    glutSwapBuffers();
}

void SetupRC()
{
    glClearColor(.0f, .0f, 1.0f, 1.0f);
}

void ChangeSize(GLsizei w, GLsizei h)
{
    GLfloat aspectRatio;

    if(h==0)
        h = 1;
    
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    aspectRatio = (GLfloat)w / (GLfloat)h;
    if(w <= h)
        glOrtho(-100,100,-100/aspectRatio,100/aspectRatio,1,-1);
    else
        glOrtho(-100*aspectRatio,100*aspectRatio,-100,100,1,-1);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv)
{

    // 初始化GLUT
    glutInit(&argc, argv);

    // 显示模式：双缓冲、RGBA
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB);

    // 窗口设置, create window must be the last
    glutInitWindowPosition(400, 400); // 窗口位置
    glutInitWindowSize(100, 100);     // 窗口尺寸
    glutCreateWindow("Tutorial 03");  // 窗口标题

    // 开始渲染
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);

    SetupRC();

    // 通知开始GLUT的内部循环
    glutMainLoop();

    return 0;
}