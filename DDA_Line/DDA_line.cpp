#include <GL/glut.h>
#include <cmath>

// Function to plot a pixel
void putPixel(int x, int y)
{
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
}

// DDA Line Drawing Algorithm
void DDA(int x1, int y1, int x2, int y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    float steps;

    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);

    float Xinc = dx / steps;
    float Yinc = dy / steps;

    float X = x1;
    float Y = y1;

    for (int i = 0; i <= steps; i++)
    {
        putPixel(round(X), round(Y));
        X += Xinc;
        Y += Yinc;
    }
}

// Display Function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);   // Red Line

    DDA(100, 100, 400, 300);

    glFlush();
}

// Initialize OpenGL
void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background

    glColor3f(1.0, 0.0, 0.0);

    glPointSize(3.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing Algorithm");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
