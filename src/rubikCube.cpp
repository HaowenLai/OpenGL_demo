#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

const float PI = 3.1415926;

// the values are 1/2 of the real window width and height
const GLfloat windowWidthDiv2 = 200.0f;
const GLfloat windowHeightDiv2 = 200.0f;
GLfloat xyzRot = 0;

void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //some flags
    glEnable(GL_CULL_FACE);   // 背面剔除
    glEnable(GL_DEPTH_TEST);
    // glPolygonMode(GL_BACK, GL_LINE);
    // glPolygonMode(GL_BACK, GL_FILL);

    // glPushMatrix();
    // glRotatef(yRot, 0, 1.0, 0); // The unit is degree! not rad

    //green,orange,blue,red,white,yellow
    const float colorList[][3]{{.0f, 0.80f, .0f}, {0.93f, 0.70f, 0.13f},
                                {.0f, .0f, 0.5f},  {0.86f, 0.078f, 0.24f},
                                {0.97f,0.97f,1.0f},{0.93f, 0.93f, .0f}};
    
    glPushMatrix();
    glRotatef(xyzRot, 1.0, 1.0, 1.0);

    for (int faceIndex = 0; faceIndex < 6; faceIndex++)
    {
        // turn around to draw another face
        glPushMatrix();
        if(faceIndex < 4 && faceIndex > 0)
        {
            glRotatef(90*faceIndex, 1.0, 0, 0);
        }
        else if(faceIndex == 4)
        {
            glRotatef(-90, 0.0, 1.0, 0);
        }
        else if(faceIndex == 5)
        {
            glRotatef(90, 0.0, 1.0, 0);
        }

        // draw black edges
        glLineWidth(3);
        glColor3f(.0f, .0f, .0f);
        glBegin(GL_LINES);
        {
            for (int i = 0; i < 4; i++)
            {
                // vertical line
                glVertex3f(-36.0 + i * 24, 36 , 36 + 0.01);
                glVertex3f(-36.0 + i * 24, -36, 36 + 0.01);
                // horizontal line
                glVertex3f(36, -36.0 + i * 24 , 36 + 0.01);
                glVertex3f(-36, -36.0 + i * 24, 36 + 0.01);
            }
        }
        glEnd();

        // draw the color quadrilateral
        float x, y;
        glColor3f(colorList[faceIndex][0], colorList[faceIndex][1], colorList[faceIndex][2]);
        glBegin(GL_QUADS);
        {
            for (int i = 0; i < 9; i++)
            {
                x = -36 + (i % 3) * 24;
                y = 36 - (i / 3) * 24;
                glVertex3f(x, y,      36);
                glVertex3f(x, y - 24, 36);
                glVertex3f(x+24, y-24,36);
                glVertex3f(x+24, y,   36);
            }
        }
        glEnd();

        if(faceIndex > 0)
            glPopMatrix();

    }
    
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

void TimeFunction(int value)
{
    xyzRot += 1;

    glutPostRedisplay();
    glutTimerFunc(33, TimeFunction, 0);
}

void SetupRC()
{
    glClearColor(0.63f, 0.80f, 0.35f, 1.0f);

    glShadeModel(GL_FLAT); //flat coloring

    glFrontFace(GLU_CCW);  //counter-clockwise is front face
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
    glutCreateWindow("Rubik's cube");                              // 窗口标题

    // 开始渲染
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutTimerFunc(33, TimeFunction, 0);

    SetupRC();

    // 通知开始GLUT的内部循环
    glutMainLoop();

    return 0;
}

