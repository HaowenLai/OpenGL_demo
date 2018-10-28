#include <GL/glew.h>
#include <GL/freeglut.h>

GLfloat x1 = .0f;
GLfloat y1 = .0f;
GLfloat rsize = 25;

GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;

// the values are 1/2 of the real window width and height
GLfloat windowWidthDiv2 = 100.0f;
GLfloat windowHeightDiv2 = 100.0f;

void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, .0f, .0f);
    glRectf(x1, y1, x1 + rsize, y1 - rsize);
    
    // glFlush();
    glutSwapBuffers();
}

void TimeFunction(int value)
{
    if(x1 > windowWidthDiv2 - rsize || x1 < -windowWidthDiv2)
        xstep = -xstep;
    
    if(y1 > windowHeightDiv2 || y1 < -windowHeightDiv2 + rsize)
        ystep = -ystep;

    x1 += xstep;
    y1 += ystep;

    if(x1 > (windowWidthDiv2-rsize+xstep))
        x1 = windowWidthDiv2-rsize-1;
    else if(x1<-(windowWidthDiv2+xstep))
        x1 = - windowWidthDiv2 - 1;

    if(y1>(windowHeightDiv2+ystep))
        y1 = windowHeightDiv2 - 1;
    else if(y1<-(windowHeightDiv2-rsize+ystep))
        y1 = -windowHeightDiv2 + rsize -1;
    
    glutPostRedisplay();
    glutTimerFunc(33,TimeFunction,0);
}



void SetupRC()
{
    glClearColor(.0f, .0f, 1.0f, 1.0f);
}

void ChangeSize(GLsizei w, GLsizei h)
{
    windowWidthDiv2  = w/2;
    windowHeightDiv2 = h/2;
    
    GLfloat aspectRatio;

    if(h==0)
        h = 1;
    
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    aspectRatio = (GLfloat)w / (GLfloat)h;
    if(w <= h)
    {
        windowWidthDiv2  = 100;
        windowHeightDiv2 = 100/aspectRatio;
        glOrtho(-100,100,-windowHeightDiv2, windowHeightDiv2,1,-1);
    }
    else
    {
        windowHeightDiv2 = 100;
        windowWidthDiv2  = 100*aspectRatio;
        glOrtho(-windowWidthDiv2, windowWidthDiv2,-100,100,1,-1);
    }

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
    glutInitWindowSize(2*windowWidthDiv2, 2*windowHeightDiv2);     // 窗口尺寸
    glutCreateWindow("Tutorial 03");  // 窗口标题

    // 开始渲染
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutTimerFunc(33,TimeFunction,0);


    SetupRC();

    // 通知开始GLUT的内部循环
    glutMainLoop();

    return 0;
}