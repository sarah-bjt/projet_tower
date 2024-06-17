#include <iostream>
#include "bullet.hpp"

#include <math.h>
#define M_PI 3.14159265358979f

#include "App.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <img/img.hpp>

#include <sstream>

#include "simpletext.h"
#include "utils.hpp"
#include "GLHelpers.hpp"

float invisible {1.0f};
double previous_time_time {0.0};

void Bullet::bullet_draw(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glPushMatrix();
    glTranslatef(this->_directX, this->_directY, 0.0f);
    glColor4f(1.0f, 0.0f, 0.0f, invisible); //invisible
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(this->X, this->Y);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * M_PI * float(i) / float(100);
        float x = cosf(angle) * this->size +  this->X;
        float y = sinf(angle) * this->size +  this->Y;
        
        glVertex2f(x, y);
    }
    
    glEnd();
    glPopMatrix();
}

void Bullet::bullet_fire(float target_X, float target_Y){
    const double time {glfwGetTime()/10};
    const double time_elapsed2 {time - previous_time_time};  //récupère le temps en direct
    previous_time_time = time;

    this->_directX += (target_X - this->X) * this->speed * time_elapsed2;
    this->_directY += (target_Y - this->Y) * this->speed * time_elapsed2;

    this->bullet_draw();

    this->X = this->_directX;
    this->Y = this->_directY;
    if(this->X < target_X+(120.0f/720.0f)/2.0f && this->X > target_X-(120.0f/720.0f)/2.0f){
        if(this->Y < target_Y+(120.0f/720.0f)/2.0f && this->Y > target_Y-(120.0f/720.0f)/2.0f){
            this->bullet_disappear();
        }
    }
}

void Bullet::bullet_disappear(){
    invisible = 0.0f;
}