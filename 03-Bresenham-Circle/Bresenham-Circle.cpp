#include <GL/glut.h>
#include <cmath>

// Circle Center and Radius
int xc = 0, yc = 0;
int r = 120;

// Function to draw all 8 symmetric points
void drawCirclePoints(int xc, int yc, int x, int y)
{
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);

    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
}

// Bresenham Circle Algorithm
void bresenhamCircle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    glBegin(GL_POINTS);

    while (x <= y)
    {
        drawCirclePoints(xc, yc, x, y);

        if (d < 0)
            d = d + 4 * x + 6;
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }

        x++;
    }

    glEnd();
}

// Display Function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);   // Red Circle
    glPointSize(3);

    bresenhamCircle(xc, yc, r);

    glFlush();
}

// Initialize OpenGL
void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-300, 300, -300, 300);
}

// Main Function
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Circle Drawing Algorithm");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
