#include <stdlib.h>
#include <GL/glut.h>
float rotationAngle = 0.01;
void renderText(float x, float y, float z, const char* text, float depth) {
    // Render text with an outline in blue
    glPushMatrix();
    glTranslatef(x, y, z);

    glColor3f(0.0, 0.0, 0.0); // black 
    glPushMatrix();
    glScalef(0.005, 0.005, depth); // Adjust scale and depth based on your needs
    for (const char* c = text; *c != '\0'; ++c) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }
    glPopMatrix();

    // Main text in white
    glColor3f(1.0, 1.0, 1.0); // White color
    glScalef(0.005, 0.005, depth); // Adjust scale and depth based on your needs
    for (const char* c = text; *c != '\0'; ++c) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }
    glPopMatrix();
}

void drawHead(float x, float y, float z, float size) {
    // Draw a green cube with a black outline
    glPushMatrix();
    glTranslatef(x, y, z);

    // head1
    glColor3f(0.0, 1.0, 1.0); // Green color
    glPushMatrix();
    glScalef(1.0, 1.0, 0.5);
    glutSolidCube(size);
    glPopMatrix();

    // White outline
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(1.0, 1.0, 1.0); // white color
    glPushMatrix();
    glScalef(1.0, 1.0, 0.5);
    glLineWidth(1.0);
    glutWireCube(size);
    glPopMatrix();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // head2
    glColor3f(0.0, 1.0, 1.0); // Green color
    glPushMatrix();
    glTranslatef(0, -0.2, 0.6);
    glScalef(0.5, 0.5, 0.7);
    glutSolidCube(size);
    glPopMatrix();

    // White outline
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(1.0, 1.0, 1.0); // white color
    glPushMatrix();
    glTranslatef(0, -0.2, 0.6);
    glScalef(0.5, 0.5, 0.7);
    glLineWidth(1.0);
    glutWireCube(size);
    glPopMatrix();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


    // Eye 1
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); // Black color
    glTranslatef(-0.2, 0.1, 0.25);
    glutSolidCube(size * 0.1);
    glPopMatrix();

    // Eye 2
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); // Black color
    glTranslatef(0.2, 0.1, 0.25);
    glutSolidCube(size * 0.1);
    glPopMatrix();

    // Mouth 1
    glPushMatrix();
    glScalef(2.0, 0.5, 0.5); // Scale the mouth
    glColor3f(0.0, 0.0, 0.0); // Black color
    glTranslatef(0.0, -0.7, 1.9); // Translate the mouth
    glutSolidCube(size * 0.1);
    glPopMatrix();

    glPopMatrix();
}

void drawBody(float x, float y, float z, float size) {
    // Draw a green cube with a black outline
    glPushMatrix();
    glTranslatef(x, y, z);

    // Green cube
    glColor3f(0.0, 1.0, 1.0); // Green color
    glPushMatrix();
    glTranslatef(0, 0, -0.6);
    glScalef( 0.75, 0.75, 1.5);
    glutSolidCube(size);
    glPopMatrix();

    // White outline
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(1.0, 1.0, 1.0); // white color
    glPushMatrix();
    glTranslatef(0, 0, -0.6);
    glScalef(0.75, 0.75, 1.5);
    glLineWidth(1.0);
    glutWireCube(size);
    glPopMatrix();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glPopMatrix();
} 

void drawLeg(float x, float y, float z, float size) {
    // Draw a green rectangular leg with a black outline
    glPushMatrix();
    // Green rectangular leg 1
    glTranslatef(0.5, 0.8, -0.2); // Move to the next leg position
    glColor3f(0.0, 1.0, 1.0); // Green color
    glPushMatrix();
    glScalef(0.4, 0.8, 0.4);
    glutSolidCube(size);
    glPopMatrix();

    // White outline
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(1.0, 1.0, 1.0); // White color
    glPushMatrix();
    glScalef(0.4, 0.8, 0.4);
    glLineWidth(1.0);
    glutWireCube(size);
    glPopMatrix();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // Green rectangular leg 2
    glTranslatef(-1, 0.0, 0.0); // Move to the next leg position
    glColor3f(0.0, 1.0, 1.0); // Green color
    glPushMatrix();
    glScalef(0.4, 0.8, 0.4);
    glutSolidCube(size);
    glPopMatrix();

    // White outline
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(1.0, 1.0, 1.0); // White color
    glPushMatrix();
    glScalef(0.4, 0.8, 0.4);
    glLineWidth(1.0);
    glutWireCube(size);
    glPopMatrix();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // Green rectangular leg 3
    glTranslatef(0, 0.0, -0.9); // Move to the next leg position
    glColor3f(0.0, 1.0, 1.0); // Green color
    glPushMatrix();
    glScalef(0.4, 0.8, 0.4);
    glutSolidCube(size);
    glPopMatrix();

    // White outline
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(1.0, 1.0, 1.0); // White color
    glPushMatrix();
    glScalef(0.4, 0.8, 0.4);
    glLineWidth(1.0);
    glutWireCube(size);
    glPopMatrix();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // Green rectangular leg 4
    glTranslatef(1, 0.0, 0.0); // Move to the next leg position
    glColor3f(0.0, 1.0, 1.0); // Green color
    glPushMatrix();
    glScalef(0.4, 0.8, 0.4);
    glutSolidCube(size);
    glPopMatrix();

    // White outline
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(1.0, 1.0, 1.0); // White color
    glPushMatrix();
    glScalef(0.4, 0.8, 0.4);
    glLineWidth(1.0);
    glutWireCube(size);
    glPopMatrix();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPopMatrix();
}



void drawTail(float x, float y, float z, float size) {
    glColor3f(0.0, 1.0, 1.0); // Turquoise color

    // Solid cone for the tail
    glPushMatrix();
    glTranslatef(x, 1.3, -1.2);
    glRotatef(-150.0, 1.0, 0.0, 0.0); // Rotate for a 45-degree angle upwards
    glutSolidCone(size * 0.35, size * 1.0, 20, 20); // Adjust the dimensions based on your needs
    glPopMatrix();

}


void drawTriceratops() {
    glPushMatrix();
    glTranslatef(0.0, -0.3, 0.0);
    drawHead(0.0, 2.0, 0.0, 1.0);
    drawBody(0.0, 1.25, 0.0, 1.0);
    drawTail(0.0, 0.0, -0.1, 1.0);
    drawLeg(-0.5, 0.0, 0.0, 1.0);

    // Draw Triceratops horns
    glColor3f(0.0, 0.0, 0.0); // Black color

    // First Cone
    glPushMatrix();
    glTranslatef(0.3, 2.3, 0.0);
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glutSolidCone(0.2, 1.0, 20, 20);
    glPopMatrix();

    // Second Cone (mid)
    glPushMatrix();
    glTranslatef(0.0, 1.8, 0.7);
    glScalef(0.7, 0.7, 0.7);
    glRotatef(-45.0, 1.0, 0.0, 0.0); // Adjust the rotation for the upward direction
    glutSolidCone(0.2, 1.0, 20, 20);
    glPopMatrix();

    // Third Cone
    glPushMatrix();
    glTranslatef(-0.3, 2.3, 0.0);
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glutSolidCone(0.2, 1.0, 20, 20);
    glPopMatrix();

    glPopMatrix();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Set the camera position
    gluLookAt(4.0, 4.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Apply rotation to the entire dinosaur
    glRotatef(rotationAngle, 0.0, 1.0, 0.0);

    // Render 3D text at the specified position
    glColor3f(1.0, 1.0, 1.0); // White color
    renderText(-2.7, -1.0, 0.0, "Dinosaur by Ipan", 0.1); // Adjust depth based on your needs

    drawTriceratops();

    // Increment the rotation angle for the next frame
    rotationAngle += 0.1;

    glutSwapBuffers();
    glutPostRedisplay();
}


void reshape(int width, int height) {
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)width / (float)height, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void init() {
    glClearColor(1.0, 1.0,1.0, 1.0); // white background
    glEnable(GL_DEPTH_TEST);
    glLineWidth(10.0); // Set line width for stroke font
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);  // Set the initial window size to 800x600
    glutCreateWindow("OpenGL Isometric 3D Text Rendering");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);
    glutMainLoop();

    return 0;
}
