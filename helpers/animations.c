#include <GL/glut.h>
#include "../headers/animations.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

extern bool teapotAscend; 
extern bool teapotRotate;
extern float teapotY;
extern float teapotX;
extern float teapotTetha; 

float increaseTeapotY = 0.0;

bool backwardsRotation = false; 

void animateTeapot() {

    if(teapotAscend == true && teapotRotate == false)
    {
        teapotY += 0.1;
        increaseTeapotY += 0.1;
        if(teapotY >= 5.0)
        {
            teapotAscend = false; 
            teapotRotate = true;
        }
    } else if(increaseTeapotY > 0.0 && teapotRotate == false){
        teapotY -= 0.1;
        increaseTeapotY -=0.1;
    }

    if(teapotRotate == true && backwardsRotation == false)
    {
        teapotTetha -= 2.0;
        if(teapotTetha == -50)
        {
            sleep(1);
            backwardsRotation = true;
        }
    } else if(teapotRotate == true && backwardsRotation == true){
        teapotTetha += 2.0;
        if(teapotTetha == 0)
        {
            backwardsRotation = false; 
            teapotRotate = false; 
        }
    }
}

extern bool torusAscend;
extern bool torusRotate;  
extern float torusX;
extern float torusY;
extern float torusZ;
extern float torusTetha; 

float increaseTorusY = 0.0; 

void animateTorus() {
    if(torusAscend == true && torusRotate == false )
    {
        torusY += 0.1; 
        increaseTorusY += 0.1; 
        if(torusY >= 6.0)
        {
            torusRotate = true; 
            torusAscend = false; 
        }
    } else if(increaseTorusY > 0.0 && torusRotate == false)
    {
        torusY -= 0.1; 
        increaseTorusY -= 0.1;
    }


    if(torusRotate == true && torusTetha > -1080.0)
    {
        torusTetha -= 30.0;
    } else 
    {
        torusTetha = 0.0;
        torusRotate = false; 
    }
}