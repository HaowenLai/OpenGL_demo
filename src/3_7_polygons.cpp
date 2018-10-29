#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

const float PI = 3.1415926;

// the values are 1/2 of the real window width and height
const GLfloat windowWidthDiv2 = 200.0f;
const GLfloat windowHeightDiv2 = 200.0f;


void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    // glRotatef(60, 1.0, 1.0, 0); // The unit is degree! not rad
    // glRotatef(zRot, 0, 0, 1);

    // draw triangles
    glBegin(GL_TRIANGLES);
    {
        glColor3f(1.0f, 0.5f, .0f); // 绘制前设置下颜色
        glVertex2f(-35, 0);
        glVertex2f(-5, 0);
        glVertex2f(-20, 30);
        
        glColor3f(0.0f, 0.5f, .0f); // 绘制前设置下颜色
        glVertex2f(5, 0);
        glVertex2f(35, 0);
        glVertex2f(20, -30);
    }
    glEnd();

    // draw triangles strip
    glShadeModel(GL_FLAT);     // 单调着色, before glBegin()
    glBegin(GL_TRIANGLE_STRIP);
    {
        glVertex2f(40, 0);
        glVertex2f(60, 0);
        glVertex2f(50,15);

        glColor3f(1.0f, .0f, .0f); // 绘制前设置下颜色
        glVertex2f(70,15);

        glColor3f(0.0f, 0.5f, .0f);
        glVertex2f(60,30);
    }
    glEnd();

    glPopMatrix();

    glutSwapBuffers();
}

void ChangeSize(GLsizei w, GLsizei h)
{
    if (h == 0)
        h = 1;

    const GLfloat nRange = 100.0f;
    const GLfloat aspectRatio = (GLfloat)w / (GLfloat)h;
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h)
    {
        GLfloat adjY = nRange / aspectRatio;
        glOrtho(-nRange, nRange, -adjY, adjY, -nRange, nRange);
    }
    else
    {
        GLfloat adjX = nRange * aspectRatio;
        glOrtho(-adjX, adjX, -nRange, nRange, -nRange, nRange);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// void TimeFunction(int value)
// {
//     zRot += 1;

//     glutPostRedisplay();
//     glutTimerFunc(33, TimeFunction, 0);
// }

void SetupRC()
{
    glClearColor(.0f, 0.2f, 0.5f, 1.0f);
}

int main(int argc, char **argv)
{

    // 初始化GLUT
    glutInit(&argc, argv);

    // 显示模式：双缓冲、RGBA
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // 窗口设置, create window must be the last
    glutInitWindowPosition(200, 100);                              // 窗口位置
    glutInitWindowSize(2 * windowWidthDiv2, 2 * windowHeightDiv2); // 窗口尺寸
    glutCreateWindow("polygons");                                    // 窗口标题

    // 开始渲染
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    // glutTimerFunc(33, TimeFunction, 0);

    SetupRC();

    // 通知开始GLUT的内部循环
    glutMainLoop();

    return 0;
}

