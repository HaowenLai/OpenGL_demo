#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

const float PI = 3.1415926;

// the values are 1/2 of the real window width and height
const GLfloat windowWidthDiv2 = 200.0f;
const GLfloat windowHeightDiv2 = 200.0f;
GLfloat yRot = 0;

void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //some flags
    glEnable(GL_CULL_FACE);   // 背面剔除
    glEnable(GL_DEPTH_TEST);
    // glPolygonMode(GL_BACK, GL_LINE);
    // glPolygonMode(GL_BACK, GL_FILL);

    glPushMatrix();
    glRotatef(yRot, 0, 1.0, 0); // The unit is degree! not rad

    // draw triangle fan for side face
    glBegin(GL_TRIANGLE_FAN);
    {
        glVertex3f(.0f, .0f, 75.0f); //顶点

        int iPivot = 0; //control triangle color
        for (int i = 0; i <= 16; i++)
        {
            float x = 50.0f * cos(PI / 8 * i);
            float y = 50.0f * sin(PI / 8 * i);

            if(iPivot % 2 == 0)
                glColor3f(1.0f, .0f, .0f);
            else
                glColor3f(.0f, 1.0f, .0f);

            iPivot++;
            glVertex2f(x, y);
        }
    }
    glEnd();

    // draw triangle fan for bottum face
    glBegin(GL_TRIANGLE_FAN);
    {
        glVertex3f(.0f, .0f, .0f); //顶点

        int iPivot = 0; //control triangle color
        for (int i = 0; i <= 16; i++)
        {
            float x = -50.0f * cos(PI / 8 * i);
            float y =  50.0f * sin(PI / 8 * i);

            if (iPivot % 2 == 0)
                glColor3f(1.0f, .0f, .0f);
            else
                glColor3f(.0f, 1.0f, .0f);

            iPivot++;
            glVertex2f(x, y);
        }
    }
    glEnd();

    glPopMatrix();

    // this circle does not rotate along with the former one
    glBegin(GL_TRIANGLE_FAN);
    {
        glVertex3f(80.0f, 20.0f, .0f); //顶点

        int iPivot = 0; //control triangle color
        for (int i = 0; i <= 16; i++)
        {
            float x = 10.0f * cos(PI / 8 * i);
            float y = 10.0f * sin(PI / 8 * i);

            if(iPivot % 2 == 0)
                glColor3f(1.0f, .0f, .0f);
            else
                glColor3f(.0f, 1.0f, .0f);

            iPivot++;
            glVertex2f(x + 80.0f, y + 20.0f);
        }
    }
    glEnd();


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

void TimeFunction(int value)
{
    yRot += 1;

    glutPostRedisplay();
    glutTimerFunc(33, TimeFunction, 0);
}

void SetupRC()
{
    glClearColor(.0f, 0.2f, 0.5f, 1.0f);

    glShadeModel(GL_FLAT); //flat coloring

    glFrontFace(GLU_CW);  //counter-clockwise is front face
}

int main(int argc, char **argv)
{

    // 初始化GLUT
    glutInit(&argc, argv);

    // 显示模式：双缓冲、RGB、深度测试
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // 窗口设置, create window must be the last
    glutInitWindowPosition(200, 100);                              // 窗口位置
    glutInitWindowSize(2 * windowWidthDiv2, 2 * windowHeightDiv2); // 窗口尺寸
    glutCreateWindow("solid object");                              // 窗口标题

    // 开始渲染
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutTimerFunc(33, TimeFunction, 0);

    SetupRC();

    // 通知开始GLUT的内部循环
    glutMainLoop();

    return 0;
}

