#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

const float PI = 3.1415926;

// the values are 1/2 of the real window width and height
GLfloat windowWidthDiv2 = 100.0f;
GLfloat windowHeightDiv2 = 100.0f;

void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(3); // 绘制前设置下点的大小和颜色
    glColor3f(1.0f, 0.5f, .0f);

    glPushMatrix();
    glRotatef(30, 1.0, 0, 0); // The unit is degree! not rad
    glRotatef(15, 0, 1.0, 0);

    glBegin(GL_POINTS);
    float z = -100;
    for (float angle = 0; angle < 2 * PI * 3.0f;angle+=0.1f)
    {
        float x = 50.0f * cos(angle);
        float y = 50.0f * sin(angle);

        glVertex3f(x, y, z);
        z += 1.0f;
    }
    glEnd();

    glPopMatrix();

    glutSwapBuffers();
}


void SetupRC()
{
    glClearColor(.0f, 0.2f, 0.5f, 1.0f);
}

void ChangeSize(GLsizei w, GLsizei h)
{
    windowWidthDiv2  = w/2;
    windowHeightDiv2 = h/2;
    
    if(h==0)
        h = 1;
    
    const GLfloat nRange = 100.0f;
    const GLfloat aspectRatio = (GLfloat)w / (GLfloat)h;
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(w <= h)
    {
        windowWidthDiv2 = nRange;
        windowHeightDiv2 = nRange / aspectRatio;
        glOrtho(-nRange, nRange, -windowHeightDiv2, windowHeightDiv2, -nRange, nRange);
    }
    else
    {
        windowHeightDiv2 = nRange;
        windowWidthDiv2 = nRange * aspectRatio;
        glOrtho(-windowWidthDiv2, windowWidthDiv2, -nRange, nRange, -nRange, nRange);
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
    glutInitWindowSize(2 * windowWidthDiv2, 2 * windowHeightDiv2); // 窗口尺寸
    glutCreateWindow("Tutorial 03");  // 窗口标题

    // 开始渲染
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);

    SetupRC();

    // 通知开始GLUT的内部循环
    glutMainLoop();

    return 0;
}
