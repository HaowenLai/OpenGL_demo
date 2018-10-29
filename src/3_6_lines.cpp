#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

const float PI = 3.1415926;

// the values are 1/2 of the real window width and height
GLfloat windowWidthDiv2 = 200.0f;
GLfloat windowHeightDiv2 = 200.0f;

GLfloat zRot = .0f;

void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    // glRotatef(60, 1.0, 1.0, 0); // The unit is degree! not rad
    // glRotatef(zRot, 0, 0, 1);

    // draw lines  -> *
    glLineWidth(1);
    glColor3f(1.0f, 0.5f, .0f); // 绘制前设置下颜色
    glBegin(GL_LINES);
    const float z = 0;
    for (float angle = 0; angle < PI ; angle += PI/20.0f)
    {
        // upper part
        float x = 50.0f * cos(angle);
        float y = 50.0f * sin(angle);
        glVertex3f(x, y, z);

        x = 50.0f * cos(angle + PI);
        y = 50.0f * sin(angle + PI);
        glVertex3f(x, y, z);
    }
    glEnd();

    // draw lines strip  -> |_|
    glBegin(GL_LINE_STRIP);
    {
        glVertex3f(-60, 0, z);
        glVertex3f(-60, -60, z);
        glVertex3f(60, -60, z);
        glVertex3f(60, 0, z);
    }
    glEnd();

    // draw lines loop  -> 口
    glColor3f(.0f, 0.6f, .0f);
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
    {
        glVertex3f(-65, 65, z);
        glVertex3f(-65, -65, z);
        glVertex3f(65, -65, z);
        glVertex3f(65, 65, z);
    }
    glEnd();

    // draw stipple lines -> 口
    glColor3f(0.9f, 0.2f, .0f);
    glLineWidth(2);
    const GLushort pattern = 0x11ff;
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(3, pattern);
    //
    glBegin(GL_LINES);
    {
        glVertex2f(-70, 65);
        glVertex2f(-70, -65);
        glVertex2f(70, 65);
        glVertex2f(70, -65);
    }
    glEnd();
    glDisable(GL_LINE_STIPPLE);

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
    glutCreateWindow("Lines");                                    // 窗口标题

    // 开始渲染
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    // glutTimerFunc(33, TimeFunction, 0);

    SetupRC();

    // 通知开始GLUT的内部循环
    glutMainLoop();

    return 0;
}

