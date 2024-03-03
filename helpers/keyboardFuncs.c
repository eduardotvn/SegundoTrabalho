#include "../headers/keyboardFuncs.h"
#include "../headers/lighting.h"
#include <GL/glut.h>
#include <stdio.h>
#include <stdbool.h>


extern float cameraVisionX;
extern float cameraVisionY;
extern float cameraVisionZ;

extern bool teapotAscend; 
extern bool torusAscend; 
extern bool hedronRotate;

void keyboardZoom(unsigned char key, int x, int y) {
    switch (key) {
        case '+':
            cameraVisionZ -= 0.3;  
            break;
        case '-':
            cameraVisionZ += 0.3;  
            break;
        case 'b':
            teapotAscend = true; 
            break; 
        case 't':
            torusAscend = true; 
            break; 
        case 'h':
            if(hedronRotate == false)
            {
                hedronRotate = true; 
            } else
            {
                hedronRotate = false; 
            }
            break; 
        case 27: 
            exit(0);
            break;
    }
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 50.0); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cameraVisionX, cameraVisionY, cameraVisionZ,  
            0.0, 0.0, 0.0,  
            0.0, 1.0, 0.0); 
    lighting();    

    glutPostRedisplay();
}

extern float hedronX;
extern float hedronZ;
extern float hedronTethaX;
extern float hedronTethaZ;
extern float wall1Pos;
extern float wall2Pos;

void keyboardRotation(int key, int x, int y)
{
    if(hedronRotate == false)
    {
        switch (key) {
            case GLUT_KEY_LEFT:
                glRotatef(4.0, 0.0, 4.0, 0.0);  
                break;
            case GLUT_KEY_RIGHT:
                glRotatef(-4.0, 0.0, 4.0, 0.0);  
                break;
            case GLUT_KEY_UP: 
                glRotatef(4.0, 4.0, 0.0, 0.0);
                break;
            case GLUT_KEY_DOWN:
                glRotatef(-4.0, 4.0, 0.0, 0.0);
                break; 
        }
        lighting();    

        glutPostRedisplay();
    } else 
    {
        switch (key) {
            case GLUT_KEY_LEFT:
                if(hedronX < 5)
                {
                    hedronX += 0.3;
                    hedronTethaZ -= 20;  
                    break;
                }
            case GLUT_KEY_RIGHT:
                hedronX -= 0.3;
                hedronTethaZ += 20;  
                break;
            case GLUT_KEY_UP: 
                if(hedronZ < 5)
                {
                    hedronZ += 0.3;
                    hedronTethaX += 20;  
                    break;
                }
            case GLUT_KEY_DOWN:
                hedronZ -= 0.3;
                hedronTethaX -= 20;  
                break; 
        }
    }
}