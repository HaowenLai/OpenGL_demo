#include <GL/glut.h>

void draw()
{
    // glClearColor(1, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(300, 300);
    glutCreateWindow("My First OpenGL Program");
    
    glutDisplayFunc(draw);
    glClearColor(1, 0, 0, 1);
    glutMainLoop();
    
    return 0;
}
