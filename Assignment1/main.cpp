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

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    /*
    //first flower
    
    //stem
    glBegin(GL_QUADS);
    glColor3f(0.04f, 0.36f, 0.1f);  // Dark Green
    glVertex2f(-0.65f, -0.8f);
    glVertex2f(-0.55f, -0.8f);
    glVertex2f(-0.55f, -0.45f);
    glVertex2f(-0.65f, -0.45f);

    glEnd();

    //upper petal
    glColor3f(0.50f, 0.1f, 0.98f);  // purple
    drawCircle(-0.68f, -0.15f, 0.1f, 100);
    drawCircle(-0.52f, -0.15f, 0.1f, 100);

    //center petal
    
    glColor3f(0.50f, 0.1f, 0.98f);  // purple
    drawCircle(-0.77f, -0.3f, 0.1f, 100);
    drawCircle(-0.43f, -0.3f, 0.1f, 100);

    //lower petal
    glColor3f(0.50f, 0.1f, 0.98f);  // purple
    drawCircle(-0.68f, -0.45f, 0.1f, 100);
    drawCircle(-0.52f, -0.45f, 0.1f, 100);

    //center
    glColor3f(1.0f, 0.65f, 0.34f);  // Orange
    drawCircle(-0.6f, -0.3f, 0.1f, 100);

    float x1 = -0.8f;
    float x2 = -0.6f;
    //
    // Second Triangle
    for (int i = 0; i < 8; i++)
    {
        float x3 = (x1 + x2) / 2;
        glColor3f(0.22f, 0.5f, 0.02f);  // Green
        glBegin(GL_TRIANGLES);
        glVertex2f(x1, -0.8f);
        glVertex2f(x2, -0.8f);
        glVertex2f(x3, -0.6f);
        glEnd();

        x1 += 0.2f;
        x2 += 0.2f;
    }
    
   */

    //sky
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 235);  // Skyblue
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();

    //grass
    glBegin(GL_QUADS);
    glColor3ub(17, 124, 19);  // Grass green
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-0.9f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(17, 124, 19);  // Grass green
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(0.9f, -1.0f);
    glEnd();

    //brick red road tiles
    glColor3ub(188, 74, 60);  
    glBegin(GL_QUADS);
    glVertex2f(-0.89f, -1.0f);
    glVertex2f(-0.75f, -0.85f);
    glVertex2f(-0.67f, -0.85f);
    glVertex2f(-0.795f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.745f, -0.84f);
    glVertex2f(-0.485f, -0.55f);
    glVertex2f(-0.415f, -0.55f);
    glVertex2f(-0.665f, -0.84f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.475f, -0.54f);
    glVertex2f(-0.215f, -0.25f);
    glVertex2f(-0.165f, -0.25f);
    glVertex2f(-0.41f, -0.54f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.21f, -0.24f);
    glVertex2f(-0.08f, -0.1f);
    glVertex2f(-0.055f, -0.1f);
    glVertex2f(-0.16f, -0.24f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.075f, -0.09f);
    glVertex2f(-0.005f, -0.015f);
    glVertex2f(0.00f, -0.015f);
    glVertex2f(-0.05f, -0.09f);
    glEnd();

    //invert
    glBegin(GL_QUADS);
    glVertex2f(0.89f, -1.0f);
    glVertex2f(0.75f, -0.85f);
    glVertex2f(0.67f, -0.85f);
    glVertex2f(0.795f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.745f, -0.84f);
    glVertex2f(0.485f, -0.55f);
    glVertex2f(0.415f, -0.55f);
    glVertex2f(0.665f, -0.84f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.475f, -0.54f);
    glVertex2f(0.215f, -0.25f);
    glVertex2f(0.165f, -0.25f);
    glVertex2f(0.41f, -0.54f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.21f, -0.24f);
    glVertex2f(0.08f, -0.1f);
    glVertex2f(0.055f, -0.1f);
    glVertex2f(0.16f, -0.24f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.075f, -0.09f);
    glVertex2f(0.005f, -0.015f);
    glVertex2f(0.00f, -0.015f);
    glVertex2f(0.05f, -0.09f);
    glEnd();

    //white road tiles
    glColor3ub(225, 217, 209);

    glBegin(GL_QUADS);
    glVertex2f(-0.022f, -1.0f);
    glVertex2f(-0.022f, -0.85f);
    glVertex2f(0.022f, -0.85f);
    glVertex2f(0.022f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.02f, -0.81f);
    glVertex2f(-0.02f, -0.61f);
    glVertex2f(0.02f, -0.61f);
    glVertex2f(0.02f, -0.81f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.016f, -0.57f);
    glVertex2f(-0.016f, -0.42f);
    glVertex2f(0.016f, -0.42f);
    glVertex2f(0.016f, -0.57f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.013f, -0.39f);
    glVertex2f(-0.013f, -0.27f);
    glVertex2f(0.013f, -0.27f);
    glVertex2f(0.013f, -0.39f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.010f, -0.24f);
    glVertex2f(-0.010f, -0.15f);
    glVertex2f(0.011f, -0.15f);
    glVertex2f(0.011f, -0.24f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.008f, -0.13f);
    glVertex2f(-0.008f, -0.05f);
    glVertex2f(0.006f, -0.05f);
    glVertex2f(0.006f, -0.13f);
    glEnd();

    
    
    glEnd();

    glFlush();  // Render now
}



/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);                 // Initialize GLUT
    
    glutInitWindowSize(1080,720);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}