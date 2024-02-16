#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <cmath>

void drawCircle(float x, float y, float radius, int numSegments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void drawTriangle(float x1, float x2, float x3, float y1, float y2, float y3) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    //first flower
    

    //stem
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0);  // Yellow
    glVertex2f(-0.65f, -0.8f);
    glVertex2f(-0.55f, -0.8f);
    glVertex2f(-0.55f, -0.45f);
    glVertex2f(-0.65f, -0.45f);

    glEnd();

    //upper
    glColor3f(0.50f, 0.1f, 0.98f);  // purple
    drawCircle(-0.7f, -0.02f, 0.1f, 100);
    drawCircle(-0.5f, -0.02f, 0.1f, 100);

    //center
    glColor3f(1.0f, 0.65f, 0.34f);  // Orange
    drawCircle(-0.6f, -0.2f, 0.1f, 100);
    glColor3f(0.50f, 0.1f, 0.98f);  // purple
    drawCircle(-0.8f, -0.2f, 0.1f, 100);
    drawCircle(-0.4f, -0.2f, 0.1f, 100);

    //lower
    glColor3f(0.50f, 0.1f, 0.98f);  // purple
    drawCircle(-0.7f, -0.38f, 0.1f, 100);
    drawCircle(-0.5f, -0.38f, 0.1f, 100);

    

    float x1 = -0.8f;
    float x2 = -0.6f;
    //
    // Second Triangle
    for (int i = 0; i < 8; i++)
    {
        float x3 = (x1 + x2) / 2;
        glColor3f(0.22f, 0.5f, 0.02f);  // Green
        drawTriangle(x1, x2, x3, -0.8f, -0.8f, -0.6f);

        x1 += 0.2f;
        x2 += 0.2f;
    }
    
   

    glFlush();  // Render now
}



/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);                 // Initialize GLUT
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
    glutInitWindowSize(1080,720);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}