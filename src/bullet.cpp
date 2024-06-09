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
    glVertex2f(0.0f, 0.0f);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * M_PI * float(i) / float(100);
        float x = cosf(angle) * this->size;
        float y = sinf(angle) * this->size;
        
        glVertex2f(x, y);
    }
    
    glEnd();
    glPopMatrix();
}

void Bullet::bullet_fire(float pos_X, float pos_Y){
    const double time {glfwGetTime()/10};
    const double time_elapse {time - previousTime};  //récupère le temps en direct
    previousTime = time;

    this->_directX += pos_X * this->speed * time_elapse;
    this->_directY += pos_Y * this->speed * time_elapse;

    this->bullet_draw();
}

void Bullet::bullet_disappear(){
    delete this;  //Est-ce correct meme ?
}