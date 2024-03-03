#include <GL/glut.h>
#include <math.h>
#include "./headers/keyboardFuncs.h"
#include "./headers/lighting.h"
#include "./headers/generateObjects.h"
#include "./headers/animations.h"
#include <stdio.h>
#include <stdbool.h>


float cameraVisionX = 0.0;
float cameraVisionY = 8.0;
float cameraVisionZ = -20.0;

float teapotX = 0.0; 
float teapotY = 0.0; 
float teapotTetha = 0.0;

bool teapotAscend = false; 
bool teapotRotate = false; 

float torusY = 0.0;
float torusTetha = 0.0; 

bool torusAscend = false; 
bool torusRotate = false;

float hedronX;
float hedronY;
float hedronZ;
float hedronTethaX = 0.0;
float hedronTethaZ = 0.0;

bool hedronAscend = false;
bool hedronRotate = false; 

float wall1Pos = 7.5; 
float wall2Pos = 7.5;

int init() {
    glClearColor(0.9f, 0.8f, 0.7f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0); 

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cameraVisionX, cameraVisionY, cameraVisionZ,  
              0.0, 0.0, 0.0,  
              0.0, 1.0, 0.0); 

    lighting();
}

void update(int value) {

    animateTeapot();
    animateTorus();

    glutPostRedisplay();
    glutTimerFunc(32, update, 0);  
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);    

    glPushMatrix();
    glTranslatef(0.0, torusY, 0.0);
    glRotatef(torusTetha, 1.0, 0.0, 0.0);
    displayTorus();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, teapotY, 0.0);
    glRotatef(teapotTetha, 0.0, 0.0, 1.0);
    displayTeapot();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(hedronX, 0.0, hedronZ);
    glRotatef(hedronTethaZ, 0.0, 0.0, 1.0);
    glRotatef(hedronTethaX, 1.0, 0.0, 0.0);
    displayIcosahedron();
    glPopMatrix();

    displayObjects();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(200,0);
    glutInitWindowSize(400,400);
    glutCreateWindow("Projeto de Computação Gráfica");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);  
    glutKeyboardFunc(keyboardZoom);
    glutSpecialFunc(keyboardRotation);
    glutMainLoop();
    return 0; 
}