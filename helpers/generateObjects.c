#include <GL/glut.h>
#include "../headers/generateObjects.h"

extern float wall1Pos;
extern float wall2Pos;

void displayObjects() {


    GLfloat cube_ambient[] = {0.1, 0.1, 0.1, 1.0};
    GLfloat cube_diffuse[] = {0.2, 0.1, 0.0, 1.0};
    GLfloat cube_specular[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat cube_shininess[] = {10.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, cube_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, cube_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, cube_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, cube_shininess);

    glPushMatrix();
    glTranslatef(0.0, -1.5, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(5.0, 5.0, 0.5);
    glutSolidCube(3.0);
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, cube_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, cube_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, cube_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, cube_shininess);

    glPushMatrix();
    glTranslatef(0.0, 0.0, wall1Pos);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glScalef(1.0, 3.0, 0.5);
    glutSolidCube(5.0);
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, cube_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, cube_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, cube_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, cube_shininess);

    glPushMatrix();
    glTranslatef(wall2Pos, 0.0, 0.0);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glScalef(1.0, 3.0, 0.5);
    glutSolidCube(5.0);
    glPopMatrix();
}

void displayTeapot() {
    glFrontFace(GL_CW);
    GLfloat teapot_ambient[] = {0.0, 0.1, 0.1, 1.0};
    GLfloat teapot_diffuse[] = {0.0, 0.5, 0.5, 1.0};
    GLfloat teapot_specular[] = {0.4, 0.4, 0.4, 1.0};
    GLfloat teapot_shininess[] = {10.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, teapot_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, teapot_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, teapot_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, teapot_shininess);

    glPushMatrix();
    glTranslatef(-2.5, 0.0, 0.0);
    glutSolidTeapot(1.0);
    glPopMatrix();

    glFrontFace(GL_CCW);
}


void displayTorus() {

    GLfloat torus_ambient[] = {0.1, 0.1, 0.1, 1.0};
    GLfloat torus_diffuse[] = {1.0, 1.0, 0.0, 1.0};
    GLfloat torus_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat torus_shininess[] = {50.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, torus_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, torus_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, torus_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, torus_shininess);

    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glTranslatef(3.0, 0.0, 0.25);
    glutSolidTorus(0.5, 1.0, 20, 40);
    glPopMatrix();

}

void displayIcosahedron() {
    
    GLfloat icosahedron_ambient[] = {0.1, 0.1, 0.1, 1.0};
    GLfloat icosahedron_diffuse[] = {0.5, 0.0, 0.5, 1.0};
    GLfloat icosahedron_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat icosahedron_shininess[] = {50.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, icosahedron_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, icosahedron_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, icosahedron_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, icosahedron_shininess);

    glPushMatrix();
    glutSolidIcosahedron();
    glPopMatrix();

}