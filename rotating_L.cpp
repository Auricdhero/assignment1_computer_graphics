#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <cmath>

// Rotation angle
float rotationAngle = 0.0f;

// Function to draw the letter L
void drawLetterL()
{
    glBegin(GL_QUADS);

    // Vertical part of L
    glVertex2f(-0.3f, 0.5f);  // Top-left
    glVertex2f(-0.1f, 0.5f);  // Top-right
    glVertex2f(-0.1f, -0.5f); // Bottom-right
    glVertex2f(-0.3f, -0.5f); // Bottom-left

    // Horizontal part of L
    glVertex2f(-0.3f, -0.5f); // Top-left
    glVertex2f(0.3f, -0.5f);  // Top-right
    glVertex2f(0.3f, -0.3f);  // Bottom-right
    glVertex2f(-0.3f, -0.3f); // Bottom-left

    glEnd();
}

// Display callback function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Move back to see the object
    glTranslatef(0.0f, 0.0f, -3.0f);

    // Rotate around Y-axis
    glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);

    // Set color to blue
    glColor3f(0.2f, 0.5f, 1.0f);

    // Draw the letter L
    drawLetterL();

    glutSwapBuffers();
}

// Timer callback for animation
void timer(int value)
{
    rotationAngle += 3.0f; // Increment rotation angle
    if (rotationAngle > 360.0f)
    {
        rotationAngle -= 360.0f;
    }

    glutPostRedisplay();         // Request display update
    glutTimerFunc(16, timer, 0); // ~60 FPS
}

// Reshape callback function
void reshape(int width, int height)
{
    if (height == 0)
        height = 1;
    float aspect = (float)width / (float)height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

// Initialize OpenGL settings
void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    glEnable(GL_DEPTH_TEST);              // Enable depth testing
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

// Main function
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotating Letter L");

    initGL();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
