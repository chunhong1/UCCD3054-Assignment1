#include <windows.h>
#include <GL/glut.h>
#include <Math.h>
#define PI 3.14159265f

// Global variables
char title[] = "A Beautiful Sunday";  // Windowed mode's title
int windowWidth = 640;     // Windowed mode's width
int windowHeight = 480;     // Windowed mode's height
int windowPosX = 50;      // Windowed mode's top-left corner x
int windowPosY = 50;      // Windowed mode's top-left corner y

// Projection clipping area
GLdouble clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;

// Car properties
float shift = 0;
float scale = 1;

//cloud properties
float bx = 0;

bool fullScreenMode = false; // Full-screen or windowed mode?

/* Draws a circle */
void drawCircle(float x, float y, float radius, int numSegments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * PI * float(i) / float(numSegments);
        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

/* Initialize OpenGL Graphics */
void initGL() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set background (clear) color to black
}

/* Callback handler for window re-paint event */
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer
    glMatrixMode(GL_MODELVIEW);    // To operate on the model-view matrix
    glLoadIdentity();              // Reset model-view matrix

    //sky
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 235);  // Skyblue
    glVertex2f(-2.0f, 0.0f);
    glVertex2f(2.0f, 0.0f);
    glVertex2f(2.0f, 1.0f);
    glVertex2f(-2.0f, 1.0f);
    glEnd();

    //grass
    glBegin(GL_QUADS);
    glColor3ub(17, 124, 19);  // Grass green
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-2.0f, 0.0f);
    glVertex2f(-2.0f, -1.0f);
    glVertex2f(-0.9f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(2.0f, 0.0f);
    glVertex2f(2.0f, -1.0f);
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

    //house
    //wall
    glBegin(GL_POLYGON);
    glVertex2f(-0.06f, 0.05f);
    glVertex2f(-0.06f, 0.0f);
    glVertex2f(0.06f, 0.0f);
    glVertex2f(0.06f, 0.05f);
    glVertex2f(0.0f, 0.05f);
    glVertex2f(-0.03f, 0.10f);
    glEnd();

    //windows and door
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.04f, 0.04f);
    glVertex2f(-0.04f, 0.00f);
    glVertex2f(-0.02f, 0.00f);
    glVertex2f(-0.02f, 0.04f);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.04f);
    glVertex2f(0.0f, 0.02f);
    glVertex2f(0.03f, 0.02f);
    glVertex2f(0.03f, 0.04f);
    glEnd();

    //rooftop
    glColor3ub(188, 74, 60);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.05f);
    glVertex2f(0.06f, 0.05f);
    glVertex2f(0.02f, 0.10f);
    glVertex2f(-0.03f, 0.10f);
    glEnd();

    glColor3ub(188, 74, 60);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.06f, 0.05f);
    glVertex2f(-0.03f, 0.10f);
    glVertex2f(-0.04f, 0.10f);
    glEnd();

    //sun
    glColor3ub(253, 184, 19);
    drawCircle(-0.5f, 0.5f, 0.1f, 100);

    //cloud
    glTranslatef(bx, 0, 0);
    glColor3ub(246, 246, 246);
    drawCircle(0.0f, 0.5f, 0.1f, 100);
    drawCircle(0.1f, 0.53f, 0.1f, 100);
    drawCircle(0.0f, 0.6f, 0.1f, 100);
    drawCircle(-0.1f, 0.57f, 0.1f, 100);

    drawCircle(0.7f, 0.7f, 0.1f, 100);
    drawCircle(0.8f, 0.73f, 0.1f, 100);
    drawCircle(0.7f, 0.8f, 0.1f, 100);
    drawCircle(0.6f, 0.77f, 0.1f, 100);

    bx += 0.01f;
    if (bx > 2.0f)
        bx = -2.0f;
    glutPostRedisplay();
    glLoadIdentity();

    //tree
    glColor3ub(128, 113, 83);
    glBegin(GL_QUADS);
    glVertex2f(-0.8f, -0.5f);
    glVertex2f(-0.8f, -0.7f);
    glVertex2f(-0.7f, -0.7f);
    glVertex2f(-0.7f, -0.5f);
    glEnd();

    glColor3ub(95, 146, 106);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f, -0.5f);
    glVertex2f(-0.6f, -0.5f);
    glVertex2f(-0.75f, -0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f, -0.35f);
    glVertex2f(-0.6f, -0.35f);
    glVertex2f(-0.75f, -0.1f);
    glEnd();

    glColor3ub(128, 113, 83);
    glBegin(GL_QUADS);
    glVertex2f(-0.40f, -0.38f);
    glVertex2f(-0.40f, -0.23f);
    glVertex2f(-0.36f, -0.23f);
    glVertex2f(-0.36f, -0.38f);
    glEnd();

    glColor3ub(95, 146, 106);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.43f, -0.3f);
    glVertex2f(-0.33f, -0.3f);
    glVertex2f(-0.38f, -0.15f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.43f, -0.22f);
    glVertex2f(-0.33f, -0.22f);
    glVertex2f(-0.38f, -0.09f);
    glEnd();

    glColor3ub(128, 113, 83);
    glBegin(GL_QUADS);
    glVertex2f(-0.18f, -0.15f);
    glVertex2f(-0.18f, -0.1f);
    glVertex2f(-0.15f, -0.1f);
    glVertex2f(-0.15f, -0.15f);
    glEnd();

    glColor3ub(95, 146, 106);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.20f, -0.1f);
    glVertex2f(-0.13f, -0.1f);
    glVertex2f(-0.17f, -0.05f);
    glEnd();

    glColor3ub(95, 146, 106);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.20f, -0.07f);
    glVertex2f(-0.13f, -0.07f);
    glVertex2f(-0.17f, -0.02f);
    glEnd();

    //reflect of tree
    glColor3ub(128, 113, 83);
    glBegin(GL_QUADS);
    glVertex2f(0.8f, -0.5f);
    glVertex2f(0.8f, -0.7f);
    glVertex2f(0.7f, -0.7f);
    glVertex2f(0.7f, -0.5f);
    glEnd();

    glColor3ub(95, 146, 106);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.9f, -0.5f);
    glVertex2f(0.6f, -0.5f);
    glVertex2f(0.75f, -0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.9f, -0.35f);
    glVertex2f(0.6f, -0.35f);
    glVertex2f(0.75f, -0.1f);
    glEnd();

    glColor3ub(128, 113, 83);
    glBegin(GL_QUADS);
    glVertex2f(0.40f, -0.38f);
    glVertex2f(0.40f, -0.23f);
    glVertex2f(0.36f, -0.23f);
    glVertex2f(0.36f, -0.38f);
    glEnd();

    glColor3ub(95, 146, 106);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.43f, -0.3f);
    glVertex2f(0.33f, -0.3f);
    glVertex2f(0.38f, -0.15f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.43f, -0.22f);
    glVertex2f(0.33f, -0.22f);
    glVertex2f(0.38f, -0.09f);
    glEnd();

    glColor3ub(128, 113, 83);
    glBegin(GL_QUADS);
    glVertex2f(0.18f, -0.15f);
    glVertex2f(0.18f, -0.1f);
    glVertex2f(0.15f, -0.1f);
    glVertex2f(0.15f, -0.15f);
    glEnd();

    glColor3ub(95, 146, 106);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.20f, -0.1f);
    glVertex2f(0.13f, -0.1f);
    glVertex2f(0.17f, -0.05f);
    glEnd();

    glColor3ub(95, 146, 106);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.20f, -0.07f);
    glVertex2f(0.13f, -0.07f);
    glVertex2f(0.17f, -0.02f);
    glEnd();

    //car
    glColor3ub(128, 113, 83);
    glTranslatef(0, shift, 0);
    glScalef(scale, scale, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.2f, -0.55f);
    glVertex2f(-0.2f, -0.7f);
    glVertex2f(0.2f, -0.7f);
    glVertex2f(0.2f, -0.55f);
    glEnd();

    //light
    glColor3ub(246, 246, 246);
    drawCircle(-0.15f, -0.6f, 0.03f, 100);
    drawCircle(0.15f, -0.6f, 0.03f, 100);

    glColor3ub(183, 150, 107);
    glBegin(GL_QUADS);
    glVertex2f(-0.1f, -0.6f);
    glVertex2f(-0.1f, -0.65f);
    glVertex2f(0.1f, -0.65f);
    glVertex2f(0.1f, -0.6f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.07f, -0.66f);
    glVertex2f(-0.07f, -0.68f);
    glVertex2f(0.07f, -0.68f);
    glVertex2f(0.07f, -0.66f);
    glEnd();

    //car upper
    glColor3ub(128, 113, 83);
    glBegin(GL_POLYGON);
    glVertex2f(-0.1f, -0.45f);
    glVertex2f(-0.2f, -0.55f);
    glVertex2f(0.2f, -0.55f);
    glVertex2f(0.1f, -0.45f);
    glEnd();

    //window
    glColor3ub(208, 219, 211);
    glBegin(GL_POLYGON);
    glVertex2f(-0.1f, -0.47f);
    glVertex2f(-0.15f, -0.53f);
    glVertex2f(0.15f, -0.53f);
    glVertex2f(0.1f, -0.47f);
    glEnd();

    //tyre
    glColor3ub(58, 54, 59);
    glBegin(GL_QUADS);
    glVertex2f(-0.18f, -0.7f);
    glVertex2f(-0.18f, -0.75f);
    glVertex2f(-0.13f, -0.75f);
    glVertex2f(-0.13f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.18f, -0.7f);
    glVertex2f(0.18f, -0.75f);
    glVertex2f(0.13f, -0.75f);
    glVertex2f(0.13f, -0.7f);
    glEnd();

    glLoadIdentity();

    glutSwapBuffers();  // Render now
}

/* Call back when the windows is re-sized */
void reshape(GLsizei width, GLsizei height) {
    // Compute aspect ratio of the new window
    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping area to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset the projection matrix
    if (width >= height) {
        clipAreaXLeft = -1.0 * aspect;
        clipAreaXRight = 1.0 * aspect;
        clipAreaYBottom = -1.0;
        clipAreaYTop = 1.0;
    }
    else {
        clipAreaXLeft = -1.0;
        clipAreaXRight = 1.0;
        clipAreaYBottom = -1.0 / aspect;
        clipAreaYTop = 1.0 / aspect;
    }
    gluOrtho2D(clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop);
}

/* Callback handler for normal-key event */
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 27:     // ESC key
        exit(0);
        break;
    }
}

/* Callback handler for special-key event */
void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_F1:    // F1: Toggle between full-screen and windowed mode
        fullScreenMode = !fullScreenMode;         // Toggle state
        if (fullScreenMode) {                     // Full-screen mode
            windowPosX = glutGet(GLUT_WINDOW_X); // Save parameters for restoring later
            windowPosY = glutGet(GLUT_WINDOW_Y);
            windowWidth = glutGet(GLUT_WINDOW_WIDTH);
            windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
            glutFullScreen();                      // Switch into full screen
        }
        else {                                         // Windowed mode
            glutReshapeWindow(windowWidth, windowHeight); // Switch into windowed mode
            glutPositionWindow(windowPosX, windowPosX);   // Position top-left corner
        }
        break;
    case GLUT_KEY_UP:
        // Translate and scale the car when the UP arrow key is pressed
        if (shift < 0.07f) {
            shift += 0.01f;
            scale -= 0.1f;
            glutPostRedisplay(); // Trigger a redraw to update the car's position and scale
        }

        break;

    case GLUT_KEY_DOWN:
        // Translate and scale the car when the UP arrow key is pressed
        if (shift > -0.03f) {
            shift -= 0.01f;
            scale += 0.1f;
            glutPostRedisplay(); // Trigger a redraw to update the car's position and scale
        }
        break;
    }
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(windowWidth, windowHeight);  // Initial window width and height
    glutInitWindowPosition(windowPosX, windowPosY); // Initial window top-left corner (x, y)
    glutCreateWindow(title);      // Create window with given title
    glutDisplayFunc(display);     // Register callback handler for window re-paint
    glutReshapeFunc(reshape);     // Register callback handler for window re-shape
    glutSpecialFunc(specialKeys); // Register callback handler for special-key event
    glutKeyboardFunc(keyboard);   // Register callback handler for special-key event
    initGL();                     // Our own OpenGL initialization
    glutMainLoop();               // Enter event-processing loop
    return 0;
}