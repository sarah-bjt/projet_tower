#include <iostream>
#include "bullet.hpp"

#include "App.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <img/img.hpp>

#include <sstream>

#include "simpletext.h"
#include "utils.hpp"
#include "GLHelpers.hpp"

double previousTime {0.0};

void Bullet::bullet_draw(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(this->_directX, this->_directY, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
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

    this->_directX += (target_X - this->X) * this->speed * time;
    this->_directY += (target_Y - this->Y) * this->speed * time;

    //std::cout << "_directX = " << this->_directX << " et _directY = " << this->_directY << std::endl;

    this->bullet_draw();
}

void Bullet::bullet_disappear(){
    delete this;  //Est-ce correct meme ?
}