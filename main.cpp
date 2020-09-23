#include<cstdio>
#include<iostream>
using namespace std;
#include<math.h>
#include <GL/gl.h>
#include <GL/glut.h>


GLfloat cloudPosition = 0.0f;
GLfloat boatPosition = 0.0f;
GLfloat planePosition =0.0f;
GLfloat planeSpeed = 0.03f;
GLfloat position = 0.0f;
GLfloat position2 = 0.0f;
GLfloat ysun = 0.0f;
GLfloat childSet1 = 0.0f;
GLfloat childSet2 = 0.0f;
GLfloat childSpeed = 0.01f;
GLfloat speed = 0.1f;
GLfloat speedCloud = 0.01f;
GLfloat boatSpeed = 0.025f;
GLfloat wavePosition =0.0f;
GLfloat waveSpeed1 =0.06f;
GLfloat waveSpeed2=0.03f;
float fish_t_x[10];
float fish_t_y[10];
float fish_r_a[10];
float fish_r_d[10];
int counter = 10.0f;
float counterFish=0.0;
int point = 0;
float x, y , i;
int j;
bool nightMode = false;
bool fishSight = false;

void update(int value) {

    if (cloudPosition < -1.5f) {
        cloudPosition = 1.2f;
    }

    cloudPosition -= speedCloud;

    if (cloudPosition > 1.5f) {
        cloudPosition = -1.2f;
    }

    if(position2 < -1.5f)
    {
        position2 = 1.2f;
    }


    position2 -= speedCloud;

    if(childSet1 > 0.05f) {

        childSet1 = 0.0f;
    }

    if(childSet1 < 0.0f) {
        childSet1 = 0.00f;
    }

    childSet1 += childSpeed;

    if(boatPosition > 1.68f) {
        boatPosition = -4.5f;
    }
    boatPosition += boatSpeed;


    if (planePosition < -1.5f) {
        planePosition = 1.2f;
    }
    planePosition -= planeSpeed;

    if (planePosition > 1.5f) {
        planePosition = -1.2f;
    }


    //wave control
    if (wavePosition < -1.5f) {
        wavePosition = 1.2f;
    }
    wavePosition += waveSpeed1;

    if (wavePosition > 1.5f) {
        wavePosition = -1.2f;
    }


    glutPostRedisplay();




    glutTimerFunc(100, update, 0);
}
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void handleMouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            speed += 0.1f;
            printf("clicked at (%d, %d)\n", x, y);
        }
    }

    glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {

    switch (key) {

    case 'l':
        if(position < -1.0)
        {
            position = -0.9f;
        }

        position-=speed;

        //speed = 0.0f;
        break;

    case 'r':


        if(position > 1.0)
        {
            position = 0.9f;
        }

        position+=speed;


        //glutPostRedisplay();
        //speed += 0.1f;
        break;

    case 'n':

        nightMode = true;

        break;

    case 'd':
        nightMode = false;
        break;

    case 'f':
        fishSight = true;
        break;

    case 'm':
        fishSight = false;
        break;

    case 'p'://plane speed stop
        planeSpeed = 0.0f;
        break;
    case 'o'://plane speed increase
        planeSpeed += 0.01f;

        break;





    }
    glutPostRedisplay();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    //sky
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(-1.0f, 0.5f);
    glVertex2f(1.0f, 0.5f);
    glVertex2f(1.0f, 1.0f);
    glEnd();

    //sun
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,1.0f,0.3f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.065*sin(i)+0.35;
        y=0.065*cos(i)+0.9;
        glVertex2f(x,y);
    }
    glEnd();


    //cloud
    glPushMatrix();
    glTranslatef(cloudPosition,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.4f, 0.9f);
    glVertex2d(-0.5f, 0.9f);
    glVertex2d(-0.6f, 0.8f);
    glVertex2d(-0.5f, 0.7f);
    glVertex2d(-0.4f, 0.7f);
    glVertex2d(-0.3f, 0.8f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.25f, 0.9f);
    glVertex2d(-0.35f, 0.9f);
    glVertex2d(-0.45f, 0.8f);
    glVertex2d(-0.35f, 0.7f);
    glVertex2d(-0.25f, 0.7f);
    glVertex2d(-0.15f, 0.8f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.1+0.4f, 0.9f);
    glVertex2d(-0.2f+0.4f, 0.9f);
    glVertex2d(-0.3f+0.4f, 0.8f);
    glVertex2d(-0.2f+0.4f, 0.7f);
    glVertex2d(-0.1f+0.4f, 0.7f);
    glVertex2d(-0.0f+0.4f, 0.8f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.05f+0.4f, 0.9f);
    glVertex2d(-0.05f+0.4f, 0.9f);
    glVertex2d(-0.15f+0.4f, 0.8f);
    glVertex2d(-0.05f+0.4f, 0.7f);
    glVertex2d(0.05f+0.4f, 0.7f);
    glVertex2d(0.15f+0.4f, 0.8f);
    glEnd();

    glPopMatrix();

    //night sky
    if(nightMode==true) {
        glBegin(GL_QUADS);
        glColor3f(0.1f, 0.1f, 0.3f);
        glVertex2f(-1.0f, 1.0f);
        glVertex2f(-1.0f, 0.5f);
        glVertex2f(1.0f, 0.5f);
        glVertex2f(1.0f, 1.0f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        //glVertex2f(0.5f, 0.6f);
        for(i=0; i<=2*3.14; i+=0.001)
        {
            x=0.065*sin(i)+0.35+0.2;
            y=0.065*cos(i)+0.9;
            glVertex2f(x,y);
        }
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.1f, 0.1f, 0.3f);
        //glVertex2f(0.5f, 0.6f);
        for(i=0; i<=2*3.14; i+=0.001)
        {
            x=0.065*sin(i)+0.35+0.05+0.2;
            y=0.065*cos(i)+0.9;
            glVertex2f(x,y);
        }
        glEnd();

    }

    //mountains
    glBegin(GL_TRIANGLES);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-1.2f+0.5f-0.4f, 0.5f);
    glVertex2f(-0.8f+0.5f-0.4f, 0.5f);
    glVertex2f(-0.9f+0.5f-0.4f, 0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.65f, 0.65f, 0.65f);
    glVertex2f(-1.2f+0.6f-0.4f, 0.5f);
    glVertex2f(-0.8f+0.6f-0.4f, 0.5f);
    glVertex2f(-1.0f+0.6f-0.4f, 0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-1.2f+0.5f, 0.5f);
    glVertex2f(-0.8f+0.5f, 0.5f);
    glVertex2f(-0.9f+0.5f, 0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.65f, 0.65f, 0.65f);
    glVertex2f(-1.2f+0.6f, 0.5f);
    glVertex2f(-0.8f+0.6f, 0.5f);
    glVertex2f(-1.0f+0.6f, 0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-1.2f+0.5f+0.4f, 0.5f);
    glVertex2f(-0.8f+0.5f+0.4f, 0.5f);
    glVertex2f(-0.9f+0.5f+0.4f, 0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.65f, 0.65f, 0.65f);
    glVertex2f(-1.2f+0.6f+0.4f, 0.5f);
    glVertex2f(-0.8f+0.6f+0.4f, 0.5f);
    glVertex2f(-1.0f+0.6f+0.4f, 0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-1.2f+0.5f+0.8f, 0.5f);
    glVertex2f(-0.8f+0.5f+0.8f, 0.5f);
    glVertex2f(-0.9f+0.5f+0.8f, 0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.65f, 0.65f, 0.65f);
    glVertex2f(-1.2f+0.6f+0.8f, 0.5f);
    glVertex2f(-0.8f+0.6f+0.8f, 0.5f);
    glVertex2f(-1.0f+0.6f+0.8f, 0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-1.2f+0.5f+1.2f, 0.5f);
    glVertex2f(-0.8f+0.5f+1.2f, 0.5f);
    glVertex2f(-0.9f+0.5f+1.2f, 0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.65f, 0.65f, 0.65f);
    glVertex2f(-1.2f+0.6f+1.2f, 0.5f);
    glVertex2f(-0.8f+0.6f+1.2f, 0.5f);
    glVertex2f(-1.0f+0.6f+1.2f, 0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-1.2f+0.5f+1.6f, 0.5f);
    glVertex2f(-0.8f+0.5f+1.6f, 0.5f);
    glVertex2f(-0.9f+0.5f+1.6f, 0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.65f, 0.65f, 0.65f);
    glVertex2f(-1.2f+0.6f+1.6f, 0.5f);
    glVertex2f(-0.8f+0.6f+1.6f, 0.5f);
    glVertex2f(-1.0f+0.6f+1.6f, 0.8f);
    glEnd();


//plane
    glPushMatrix();
    glTranslatef(planePosition,0.0f, 0.0f);
    glBegin(GL_TRIANGLES);//plane front
    glColor3ub(96,96,96);
    glVertex2f(.38+.2,.65+.2);
    glVertex2f(.40+.2,.62+.2);
    glVertex2f(.40+.2,.68+.2);
    glEnd();

    glBegin(GL_POLYGON);//plane body
    glColor3ub(0,153,153);
    glVertex2f(.40+.2,.62+.2);
    glVertex2f(.49+.2,.62+.2);
    glVertex2f(.52+.2,.71+.2);
    glVertex2f(.50+.2,.71+.2);
    glVertex2f(.49+.2,.68+.2);
    glVertex2f(.40+.2,.68+.2);
    glEnd();


    glBegin(GL_QUADS);//plane wing upper
    glColor3ub(0,153,153);
    glVertex2f(.44+.2,.68+.2);
    glVertex2f(.46+.2,.68+.2);
    glVertex2f(.47+.2,.71+.2);
    glVertex2f(.45+.2,.71+.2);
    glEnd();

    glBegin(GL_QUADS);//plane wing lower
    glColor3ub(0,153,153);
    glVertex2f(.44+.2,.62+.2);
    glVertex2f(.46+.2,.62+.2);
    glVertex2f(.47+.2,.58+.2);
    glVertex2f(.45+.2,.58+.2);
    glEnd();
    glPopMatrix();

    //land
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(1.0f, -0.2f);
    glVertex2f(1.0f, 0.5f);
    glEnd();


    //river
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 0.8f);
    glVertex2f(-1.0f, -0.0f);
    glVertex2f(-1.0f, -0.3f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(1.0f, -0.0f);
    glEnd();

    //land
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.4f);
    glVertex2f(-1.0f, -0.3f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.3f);
    glEnd();


    //grass


    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0 , 0.0);
    glVertex2f(0.866f+.2f-.3f,0.466f);
    glVertex2f(0.916f+.2f-.3f,0.466f);
    glVertex2f(0.883f+.2f-.3f,0.533f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.1,0.3, 0.0);
    glVertex2f(0.9f+.2f-.3f,0.466f);
    glVertex2f(0.933f+.2f-.3f,0.466f);
    glVertex2f(0.925f+.2f-.3f,0.512f);
    glEnd();

//grass1

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0 , 0.0);
    glVertex2f(0.866f+.2f-.3f+.1-.04,0.466f+.009);
    glVertex2f(0.916f+.2f-.3f+.1-.04,0.466f+.009);
    glVertex2f(0.883f+.2f-.3f+.1-.04,0.533f+.009);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.1,0.3, 0.0);
    glVertex2f(0.9f+.2f-.3f+.1-.04,0.466f+.009);
    glVertex2f(0.933f+.2f-.3f+.1-.04,0.466f+.009);
    glVertex2f(0.925f+.2f-.3f+.1-.04,0.512f+.009);
    glEnd();



    //grass
    glBegin(GL_POLYGON);
    glColor3f(0.1,0.3, 0.0);//
    glVertex2f(0.866f,0.466f);
    glVertex2f(0.916f,0.466f);
    glVertex2f(0.883f,0.533f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0 , 0.0);
    glVertex2f(0.9f,0.466f);
    glVertex2f(0.933f,0.466f);
    glVertex2f(0.925f,0.512f);
    glEnd();


    //grass end


    if(nightMode==true) {
        //land
        glBegin(GL_QUADS);
        glColor3f(0.1f, 0.7f, 0.4f);
        glVertex2f(-1.0f, 0.5f);
        glVertex2f(-1.0f, -0.2f);
        glVertex2f(1.0f, -0.2f);
        glVertex2f(1.0f, 0.5f);
        glEnd();

        //grass


        glBegin(GL_POLYGON);
        glColor3f(0.0,0.0 , 0.0);
        glVertex2f(0.866f+.2f-.3f,0.466f);
        glVertex2f(0.916f+.2f-.3f,0.466f);
        glVertex2f(0.883f+.2f-.3f,0.533f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.1,0.3, 0.0);
        glVertex2f(0.9f+.2f-.3f,0.466f);
        glVertex2f(0.933f+.2f-.3f,0.466f);
        glVertex2f(0.925f+.2f-.3f,0.512f);
        glEnd();

//grass1

        glBegin(GL_POLYGON);
        glColor3f(0.0,0.0 , 0.0);
        glVertex2f(0.866f+.2f-.3f+.1-.04,0.466f+.009);
        glVertex2f(0.916f+.2f-.3f+.1-.04,0.466f+.009);
        glVertex2f(0.883f+.2f-.3f+.1-.04,0.533f+.009);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.1,0.3, 0.0);
        glVertex2f(0.9f+.2f-.3f+.1-.04,0.466f+.009);
        glVertex2f(0.933f+.2f-.3f+.1-.04,0.466f+.009);
        glVertex2f(0.925f+.2f-.3f+.1-.04,0.512f+.009);
        glEnd();



        //grass
        glBegin(GL_POLYGON);
        glColor3f(0.1,0.3, 0.0);//
        glVertex2f(0.866f,0.466f);
        glVertex2f(0.916f,0.466f);
        glVertex2f(0.883f,0.533f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0,0.0 , 0.0);
        glVertex2f(0.9f,0.466f);
        glVertex2f(0.933f,0.466f);
        glVertex2f(0.925f,0.512f);
        glEnd();


        //grass end


        //river
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.7f, 0.8f);
        glVertex2f(-1.0f, -0.0f);
        glVertex2f(-1.0f, -0.3f);
        glVertex2f(1.0f, -0.3f);
        glVertex2f(1.0f, -0.0f);
        glEnd();



        //land
        glBegin(GL_QUADS);
        glColor3f(0.1f, 0.6f, 0.3f);
        glVertex2f(-1.0f, -0.3f);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(1.0f, -0.3f);
        glEnd();
    }

    //tree
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.25f, 0.0f+0.55f);
    glVertex2f(0.0f-0.6f-0.25f, 0.05f+0.02f+0.55f);
    glVertex2f(-0.03f-0.6f-0.25f, 0.0f+0.55f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.25f, 0.0f-0.02f+0.55f);
    glVertex2f(0.0f-0.6f-0.25f, 0.05f+0.02f-0.02f+0.55f);
    glVertex2f(-0.03f-0.6f-0.25f, 0.0f-0.02f+0.55f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.25f, 0.0f-0.02f-0.03f+0.55f);
    glVertex2f(0.0f-0.6f-0.25f, 0.05f+0.02f-0.02f-0.03f+0.55f);
    glVertex2f(-0.03f-0.6f-0.25f, 0.0f-0.02f-0.03f+0.55f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.01f, 0.01f);
    glVertex2f(0.009f-0.6f-0.25f, 0.0f-0.02f-0.03f+0.55f);
    glVertex2f(-0.009f-0.6f-0.25f,0.0f-0.02f-0.03f+0.55f);
    glVertex2f(-0.009f-0.6f-0.25f,0.0f-0.02f-0.03f-0.03f+0.55f);
    glVertex2f(0.009f-0.6f-0.25f,0.0f-0.02f-0.03f-0.03f+0.55f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.895f, 0.0f, 0.0f);
    //tree
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.25f+0.35f, 0.0f+0.55f);
    glVertex2f(0.0f-0.6f-0.25f+0.35f, 0.05f+0.02f+0.55f);
    glVertex2f(-0.03f-0.6f-0.25f+0.35f, 0.0f+0.55f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.25f+0.35f, 0.0f-0.02f+0.55f);
    glVertex2f(0.0f-0.6f-0.25f+0.35f, 0.05f+0.02f-0.02f+0.55f);
    glVertex2f(-0.03f-0.6f-0.25f+0.35f, 0.0f-0.02f+0.55f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.25f+0.35f, 0.0f-0.02f-0.03f+0.55f);
    glVertex2f(0.0f-0.6f-0.25f+0.35f, 0.05f+0.02f-0.02f-0.03f+0.55f);
    glVertex2f(-0.03f-0.6f-0.25f+0.35f, 0.0f-0.02f-0.03f+0.55f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.01f, 0.01f);
    glVertex2f(0.009f-0.6f-0.25f+0.35f, 0.0f-0.02f-0.03f+0.55f);
    glVertex2f(-0.009f-0.6f-0.25f+0.35f,0.0f-0.02f-0.03f+0.55f);
    glVertex2f(-0.009f-0.6f-0.25f+0.35f,0.0f-0.02f-0.03f-0.03f+0.55f);
    glVertex2f(0.009f-0.6f-0.25f+0.35f,0.0f-0.02f-0.03f-0.03f+0.55f);
    glEnd();

    //tree
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.25f+0.42f, 0.0f+0.55f);
    glVertex2f(0.0f-0.6f-0.25f+0.42f, 0.05f+0.02f+0.55f);
    glVertex2f(-0.03f-0.6f-0.25f+0.42f, 0.0f+0.55f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.25f+0.42f, 0.0f-0.02f+0.55f);
    glVertex2f(0.0f-0.6f-0.25f+0.42f, 0.05f+0.02f-0.02f+0.55f);
    glVertex2f(-0.03f-0.6f-0.25f+0.42f, 0.0f-0.02f+0.55f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.25f+0.42f, 0.0f-0.02f-0.03f+0.55f);
    glVertex2f(0.0f-0.6f-0.25f+0.42f, 0.05f+0.02f-0.02f-0.03f+0.55f);
    glVertex2f(-0.03f-0.6f-0.25f+0.42f, 0.0f-0.02f-0.03f+0.55f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.01f, 0.01f);
    glVertex2f(0.009f-0.6f-0.25f+0.42f, 0.0f-0.02f-0.03f+0.55f);
    glVertex2f(-0.009f-0.6f-0.25f+0.42f,0.0f-0.02f-0.03f+0.55f);
    glVertex2f(-0.009f-0.6f-0.25f+0.42f,0.0f-0.02f-0.03f-0.03f+0.55f);
    glVertex2f(0.009f-0.6f-0.25f+0.42f,0.0f-0.02f-0.03f-0.03f+0.55f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.45f, 0.0f, 0.0f);
    //tree
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.25f+0.35f, 0.0f+0.55f);
    glVertex2f(0.0f-0.6f-0.25f+0.35f, 0.05f+0.02f+0.55f);
    glVertex2f(-0.03f-0.6f-0.25f+0.35f, 0.0f+0.55f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.25f+0.35f, 0.0f-0.02f+0.55f);
    glVertex2f(0.0f-0.6f-0.25f+0.35f, 0.05f+0.02f-0.02f+0.55f);
    glVertex2f(-0.03f-0.6f-0.25f+0.35f, 0.0f-0.02f+0.55f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.25f+0.35f, 0.0f-0.02f-0.03f+0.55f);
    glVertex2f(0.0f-0.6f-0.25f+0.35f, 0.05f+0.02f-0.02f-0.03f+0.55f);
    glVertex2f(-0.03f-0.6f-0.25f+0.35f, 0.0f-0.02f-0.03f+0.55f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.01f, 0.01f);
    glVertex2f(0.009f-0.6f-0.25f+0.35f, 0.0f-0.02f-0.03f+0.55f);
    glVertex2f(-0.009f-0.6f-0.25f+0.35f,0.0f-0.02f-0.03f+0.55f);
    glVertex2f(-0.009f-0.6f-0.25f+0.35f,0.0f-0.02f-0.03f-0.03f+0.55f);
    glVertex2f(0.009f-0.6f-0.25f+0.35f,0.0f-0.02f-0.03f-0.03f+0.55f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    //tree
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.25f+0.35f, 0.0f+0.55f);
    glVertex2f(0.0f-0.6f-0.25f+0.35f, 0.05f+0.02f+0.55f);
    glVertex2f(-0.03f-0.6f-0.25f+0.35f, 0.0f+0.55f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.25f+0.35f, 0.0f-0.02f+0.55f);
    glVertex2f(0.0f-0.6f-0.25f+0.35f, 0.05f+0.02f-0.02f+0.55f);
    glVertex2f(-0.03f-0.6f-0.25f+0.35f, 0.0f-0.02f+0.55f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.25f+0.35f, 0.0f-0.02f-0.03f+0.55f);
    glVertex2f(0.0f-0.6f-0.25f+0.35f, 0.05f+0.02f-0.02f-0.03f+0.55f);
    glVertex2f(-0.03f-0.6f-0.25f+0.35f, 0.0f-0.02f-0.03f+0.55f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.01f, 0.01f);
    glVertex2f(0.009f-0.6f-0.25f+0.35f, 0.0f-0.02f-0.03f+0.55f);
    glVertex2f(-0.009f-0.6f-0.25f+0.35f,0.0f-0.02f-0.03f+0.55f);
    glVertex2f(-0.009f-0.6f-0.25f+0.35f,0.0f-0.02f-0.03f-0.03f+0.55f);
    glVertex2f(0.009f-0.6f-0.25f+0.35f,0.0f-0.02f-0.03f-0.03f+0.55f);
    glEnd();
    glPopMatrix();

    //tree
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.25f+0.42f, 0.0f+0.55f);
    glVertex2f(0.0f-0.6f-0.25f+0.42f, 0.05f+0.02f+0.55f);
    glVertex2f(-0.03f-0.6f-0.25f+0.42f, 0.0f+0.55f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.25f+0.42f, 0.0f-0.02f+0.55f);
    glVertex2f(0.0f-0.6f-0.25f+0.42f, 0.05f+0.02f-0.02f+0.55f);
    glVertex2f(-0.03f-0.6f-0.25f+0.42f, 0.0f-0.02f+0.55f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.25f+0.42f, 0.0f-0.02f-0.03f+0.55f);
    glVertex2f(0.0f-0.6f-0.25f+0.42f, 0.05f+0.02f-0.02f-0.03f+0.55f);
    glVertex2f(-0.03f-0.6f-0.25f+0.42f, 0.0f-0.02f-0.03f+0.55f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.01f, 0.01f);
    glVertex2f(0.009f-0.6f-0.25f+0.42f, 0.0f-0.02f-0.03f+0.55f);
    glVertex2f(-0.009f-0.6f-0.25f+0.42f,0.0f-0.02f-0.03f+0.55f);
    glVertex2f(-0.009f-0.6f-0.25f+0.42f,0.0f-0.02f-0.03f-0.03f+0.55f);
    glVertex2f(0.009f-0.6f-0.25f+0.42f,0.0f-0.02f-0.03f-0.03f+0.55f);
    glEnd();
    glPopMatrix();

    //tree
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.35f, 0.0f+0.4f);
    glVertex2f(0.0f-0.6f-0.35f, 0.05f+0.02f+0.4f);
    glVertex2f(-0.03f-0.6f-0.35f, 0.0f+0.4f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.35f, 0.0f-0.02f+0.4f);
    glVertex2f(0.0f-0.6f-0.35f, 0.05f+0.02f-0.02f+0.4f);
    glVertex2f(-0.03f-0.6f-0.35f, 0.0f-0.02f+0.4f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.35f, 0.0f);
    glVertex2f(0.05f-0.02f-0.6f-0.35f, 0.0f-0.02f-0.03f+0.4f);
    glVertex2f(0.0f-0.6f-0.35f, 0.05f+0.02f-0.02f-0.03f+0.4f);
    glVertex2f(-0.03f-0.6f-0.35f, 0.0f-0.02f-0.03f+0.4f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.01f, 0.01f);
    glVertex2f(0.009f-0.6f-0.35f, 0.0f-0.02f-0.03f+0.4f);
    glVertex2f(-0.009f-0.6f-0.35f,0.0f-0.02f-0.03f+0.4f);
    glVertex2f(-0.009f-0.6f-0.35f,0.0f-0.02f-0.03f-0.03f+0.4f);
    glVertex2f(0.009f-0.6f-0.35f,0.0f-0.02f-0.03f-0.03f+0.4f);
    glEnd();

    //tree_start

    glColor3f(0.1f, 0.01f, 0.01f);
    glLineWidth(7);
    glBegin(GL_LINES);
    glVertex2f(-0.46, 0.050);
    glVertex2f(-0.46, 0.170);
    glEnd();

    glColor3f(0.0f, 0.35f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.52, 0.22);
    glVertex2f(-0.46, 0.30);
    glVertex2f(-0.40, 0.22);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.52, 0.17);
    glVertex2f(-0.46, 0.30);
    glVertex2f(-0.40, 0.17);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.52, 0.12);
    glVertex2f(-0.46, 0.30);
    glVertex2f(-0.40, 0.12);
    glEnd();
    //tree_end


    //tree_start---
    glColor3f(0.1f, 0.01f, 0.01f);
    glLineWidth(7);
    glBegin(GL_LINES);
    glVertex2f(-0.16, 0.050);
    glVertex2f(-0.16, 0.170);
    glEnd();

    glColor3f(0.0f, 0.35f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.22, 0.22);
    glVertex2f(-0.16, 0.30);
    glVertex2f(-0.10, 0.22);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.22, 0.17);
    glVertex2f(-0.16, 0.30);
    glVertex2f(-0.10, 0.17);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.22, 0.12);
    glVertex2f(-0.16, 0.30);
    glVertex2f(-0.10, 0.12);
    glEnd();
    //tree_end

    //tree_start
    glColor3f(0.1f, 0.01f, 0.01f);
    glLineWidth(7);
    glBegin(GL_LINES);
    glVertex2f(-0.60, 0.050);
    glVertex2f(-0.60, 0.170);
    glEnd();

    glColor3f(0.0f, 0.35f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.66, 0.22);
    glVertex2f(-0.60, 0.30);
    glVertex2f(-0.54, 0.22);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.66, 0.17);
    glVertex2f(-0.60, 0.30);
    glVertex2f(-0.54, 0.17);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.66, 0.12);
    glVertex2f(-0.60, 0.30);
    glVertex2f(-0.54, 0.12);
    glEnd();
    //tree_end


    //house1

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.5f, 0.3f);
    glVertex2f(-0.85f-0.05f+0.12f, 0.5f-0.01f);
    glVertex2f(-0.7f-0.02f, 0.5f-0.01f);
    glVertex2f(-0.7f-0.02f, 0.48f-0.01f);
    glVertex2f(-0.85f-0.05f+0.12f, 0.48f-0.01f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.85f-0.02f, 0.45f-0.01f);
    glVertex2f(-0.7f+0.01f, 0.45f-0.01f);
    glVertex2f(-0.7f+0.01f, 0.48f-0.01f);
    glVertex2f(-0.85f-0.02f, 0.48f-0.01f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.5f, 0.3f);
    glVertex2f(-0.85f, 0.45f-0.01f);
    glVertex2f(-0.85f, 0.32f-0.01f);
    glVertex2f(-0.71f, 0.32f-0.01f);
    glVertex2f(-0.71f, 0.45f-0.01f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.8f, 0.32f);
    glVertex2f(-0.8f, 0.38f);
    glVertex2f(-0.835f, 0.38f);
    glVertex2f(-0.835f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.8f+0.07f, 0.34f+0.02f);
    glVertex2f(-0.8f+0.07f, 0.38f+0.02f);
    glVertex2f(-0.835f+0.07f, 0.38f+0.02f);
    glVertex2f(-0.835f+0.07f, 0.34f+0.02f);
    glEnd();

    //house2
    glPushMatrix();
    glTranslatef(0.25f-0.02f, 0.1f-0.02f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.5f, 0.3f);
    glVertex2f(-0.85f-0.05f+0.12f, 0.5f-0.01f);
    glVertex2f(-0.7f-0.02f, 0.5f-0.01f);
    glVertex2f(-0.7f-0.02f, 0.48f-0.01f);
    glVertex2f(-0.85f-0.05f+0.12f, 0.48f-0.01f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.85f-0.02f, 0.45f-0.01f);
    glVertex2f(-0.7f+0.01f, 0.45f-0.01f);
    glVertex2f(-0.7f+0.01f, 0.48f-0.01f);
    glVertex2f(-0.85f-0.02f, 0.48f-0.01f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.5f, 0.3f);
    glVertex2f(-0.85f, 0.45f-0.01f);
    glVertex2f(-0.85f, 0.32f-0.01f);
    glVertex2f(-0.71f, 0.32f-0.01f);
    glVertex2f(-0.71f, 0.45f-0.01f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.8f, 0.32f);
    glVertex2f(-0.8f, 0.38f);
    glVertex2f(-0.835f, 0.38f);
    glVertex2f(-0.835f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.8f+0.07f, 0.34f+0.02f);
    glVertex2f(-0.8f+0.07f, 0.38f+0.02f);
    glVertex2f(-0.835f+0.07f, 0.38f+0.02f);
    glVertex2f(-0.835f+0.07f, 0.34f+0.02f);
    glEnd();
    glPopMatrix();
    //
    //house2_start
    //top
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.5f, 0.3f);
    glVertex2f(-0.38f, 0.49f);
    glVertex2f(-0.28f, 0.49f);
    glVertex2f(-0.28f, 0.47f);
    glVertex2f(-0.38f, 0.47);
    glEnd();
    //next top
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.47f, 0.44f);
    glVertex2f(-0.29f, 0.44f);
    glVertex2f(-0.29f, 0.47f);
    glVertex2f(-0.47f, 0.47f);
    glEnd();
    //room
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.5f, 0.3f);
    glVertex2f(-0.45f, 0.44f);
    glVertex2f(-0.45f, 0.31f);
    glVertex2f(-0.31f, 0.31f);
    glVertex2f(-0.31f, 0.44f);
    glEnd();
    //door
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.4f, 0.32f);
    glVertex2f(-0.4f, 0.38f);
    glVertex2f(-0.435f, 0.38f);
    glVertex2f(-0.435f, 0.32f);
    glEnd();
    //window
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.33f, 0.32f);
    glVertex2f(-0.33f, 0.36f);
    glVertex2f(-0.365f, 0.36f);
    glVertex2f(-0.365f, 0.32f);
    glEnd();


    //house2_end

    if(nightMode==false) {
        //children
        //child 1
        glPushMatrix();
        glTranslatef(0.0f, childSet1, 0.0f);
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.7f, 0.4f);
        glVertex2f(0.5f, 0.3f);
        glVertex2f(0.5f, 0.27f);
        glVertex2f(0.52f, 0.27f);
        glVertex2f(0.52f, 0.3f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.49f+0.005f, 0.27f);
        glVertex2f(0.47f+0.005f, 0.29f);
        glVertex2f(0.47f+0.005f, 0.28f);
        glVertex2f(0.49f+0.005f, 0.26f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.53f-0.005f, 0.27f);
        glVertex2f(0.53f-0.005f, 0.26f);
        glVertex2f(0.55f+0.005f, 0.28f);
        glVertex2f(0.55f+0.005f, 0.29f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.49f+0.005f, 0.27f);
        glVertex2f(0.49f+0.005f, 0.24f);
        glVertex2f(0.53f-0.005f, 0.24f);
        glVertex2f(0.53f-0.005f, 0.27f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.49f+0.005f, 0.24f);
        glVertex2f(0.49f+0.005f, 0.225f);
        glVertex2f(0.53f-0.005f, 0.225f);
        glVertex2f(0.53f-0.005f, 0.24f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.49f+0.005f, 0.225f);
        glVertex2f(0.49f+0.005f, 0.2f);
        glVertex2f(0.51f-0.005f, 0.2f);
        glVertex2f(0.51f-0.005f, 0.225f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.53f-0.005f, 0.225f);
        glVertex2f(0.51f+0.005f, 0.225f);
        glVertex2f(0.51f+0.005f, 0.2f);
        glVertex2f(0.53f-0.005f, 0.2f);
        glEnd();

        //child 2

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.7f, 0.4f);
        glVertex2f(0.5f+0.3f, 0.3f);
        glVertex2f(0.5f+0.3f, 0.27f);
        glVertex2f(0.52f+0.3f, 0.27f);
        glVertex2f(0.52f+0.3f, 0.3f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 3.0f, 0.0f);
        glVertex2f(0.49f+0.005f+0.3f, 0.27f);
        glVertex2f(0.47f+0.005f+0.3f, 0.29f);
        glVertex2f(0.47f+0.005f+0.3f, 0.28f);
        glVertex2f(0.49f+0.005f+0.3f, 0.26f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 3.0f, 0.0f);
        glVertex2f(0.53f-0.005f+0.3f, 0.27f);
        glVertex2f(0.53f-0.005f+0.3f, 0.26f);
        glVertex2f(0.55f+0.005f+0.3f, 0.28f);
        glVertex2f(0.55f+0.005f+0.3f, 0.29f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 3.0f, 0.0f);
        glVertex2f(0.49f+0.005f+0.3f, 0.27f);
        glVertex2f(0.49f+0.005f+0.3f, 0.24f);
        glVertex2f(0.53f-0.005f+0.3f, 0.24f);
        glVertex2f(0.53f-0.005f+0.3f, 0.27f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.49f+0.005f+0.3f, 0.24f);
        glVertex2f(0.49f+0.005f+0.3f, 0.225f);
        glVertex2f(0.53f-0.005f+0.3f, 0.225f);
        glVertex2f(0.53f-0.005f+0.3f, 0.24f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.49f+0.005f+0.3f, 0.225f);
        glVertex2f(0.49f+0.005f+0.3f, 0.2f);
        glVertex2f(0.51f-0.005f+0.3f, 0.2f);
        glVertex2f(0.51f-0.005f+0.3f, 0.225f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.53f-0.005f+0.3f, 0.225f);
        glVertex2f(0.51f+0.005f+0.3f, 0.225f);
        glVertex2f(0.51f+0.005f+0.3f, 0.2f);
        glVertex2f(0.53f-0.005f+0.3f, 0.2f);
        glEnd();

        //child 3

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.7f, 0.4f);
        glVertex2f(0.5f+0.14f, 0.3f+0.1f);
        glVertex2f(0.5f+0.14f, 0.27f+0.1f);
        glVertex2f(0.52f+0.14f, 0.27f+0.1f);
        glVertex2f(0.52f+0.14f, 0.3f+0.1f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.5f);
        glVertex2f(0.49f+0.005f+0.14f, 0.27f+0.1f);
        glVertex2f(0.47f+0.005f+0.14f, 0.29f+0.1f);
        glVertex2f(0.47f+0.005f+0.14f, 0.28f+0.1f);
        glVertex2f(0.49f+0.005f+0.14f, 0.26f+0.1f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.5f);
        glVertex2f(0.53f-0.005f+0.14f, 0.27f+0.1f);
        glVertex2f(0.53f-0.005f+0.14f, 0.26f+0.1f);
        glVertex2f(0.55f+0.005f+0.14f, 0.28f+0.1f);
        glVertex2f(0.55f+0.005f+0.14f, 0.29f+0.1f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.5f);
        glVertex2f(0.49f+0.005f+0.14f, 0.27f+0.1f);
        glVertex2f(0.49f+0.005f+0.14f, 0.24f+0.1f);
        glVertex2f(0.53f-0.005f+0.14f, 0.24f+0.1f);
        glVertex2f(0.53f-0.005f+0.14f, 0.27f+0.1f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.49f+0.005f+0.14f, 0.24f+0.1f);
        glVertex2f(0.49f+0.005f+0.14f, 0.225f+0.1f);
        glVertex2f(0.53f-0.005f+0.14f, 0.225f+0.1f);
        glVertex2f(0.53f-0.005f+0.14f, 0.24f+0.1f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.49f+0.005f+0.14f, 0.225f+0.1f);
        glVertex2f(0.49f+0.005f+0.14f, 0.2f+0.1f);
        glVertex2f(0.51f-0.005f+0.14f, 0.2f+0.1f);
        glVertex2f(0.51f-0.005f+0.14f, 0.225f+0.1f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.53f-0.005f+0.14f, 0.225f+0.1f);
        glVertex2f(0.51f+0.005f+0.14f, 0.225f+0.1f);
        glVertex2f(0.51f+0.005f+0.14f, 0.2f+0.1f);
        glVertex2f(0.53f-0.005f+0.14f, 0.2f+0.1f);
        glEnd();
        glPopMatrix();
    }

    //boat
    glPushMatrix();
    glTranslatef(boatPosition, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.4f, 0.2f);
    glVertex2f(-0.3f, -0.1f-0.05f);
    glVertex2f(0.3f, -0.1f-0.05f);
    glVertex2f(0.45f, 0.15f-0.05f);
    glVertex2f(0.25f, 0.08f-0.05f);
    glVertex2f(-0.25f, 0.08f-0.05f);
    glVertex2f(-0.45f, 0.15f-0.05f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.95f);
    glVertex2f(-0.43f, 0.12f+0.1f-0.03f-0.05f);
    glVertex2f(0.43f, 0.12f+0.1f-0.03f-0.05f);
    glVertex2f(-0.1f, 0.22f+0.35f-0.03f-0.05f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.4f,0.6f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.04*sin(i)+0.3f-0.25f;
        y=0.04*cos(i)+0.45f-0.15f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.7f,0.2f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.04*sin(i)+0.3f-0.28f;
        y=0.04*cos(i)+0.45f-0.22f-0.01f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.6f,0.5f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.04*sin(i)+0.3f-0.28f+0.08f+0.01f;
        y=0.04*cos(i)+0.45f-0.21f-0.01f;
        glVertex2f(x,y);
    }
    glEnd();




    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.4f, 0.2f);
    glVertex2f(-0.12f, 0.08f-0.03f-0.05f);
    glVertex2f(-0.09f, 0.08f-0.03f-0.05f);
    glVertex2f(-0.09f, 0.22f+0.35f-0.03f-0.05f);
    glVertex2f(-0.12f,0.22f+0.35f-0.03f-0.05f);
    glEnd();
    glPopMatrix();

    //wave


    //wave1
    glPushMatrix();
    glTranslatef(wavePosition, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.1,0.2,0.6);////
    glVertex2f(-1.0f+.3, -0.5f+.3);
    glVertex2f(-0.966f+.3, -0.416f+.3);
    glVertex2f(-0.933f+.3, -0.5f+.3);
    glVertex2f(-0.9f+.3, -0.416f+.3);
    glVertex2f(-0.866f+.3, -0.5f+.3);
    glVertex2f(-0.833f+.3, -0.416f+.3);
    glVertex2f(-0.8f+.3, -0.5f+.3);
    glEnd();
    glPopMatrix();

    //wave2
    glPushMatrix();
    glTranslatef(wavePosition, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.1,0.2,0.6);////
    glVertex2f(-1.0f+.3+.6, -0.5f+.3);
    glVertex2f(-0.966f+.3+.6, -0.416f+.3);
    glVertex2f(-0.933f+.3+.6, -0.5f+.3);
    glVertex2f(-0.9f+.3+.6, -0.416f+.3);
    glVertex2f(-0.866f+.3+.6, -0.5f+.3);
    glVertex2f(-0.833f+.3+.6, -0.416f+.3);
    glVertex2f(-0.8f+.3+.6, -0.5f+.3);
    glEnd();
    glPopMatrix();

    //wave2

    //flower
    glPushMatrix();
    //glTranslatef(0.0, 0.0, 4.0);

    glRotatef(counter,0.0,0.0,1.0);
    //glRotatef(15.0f,0.0,1.0,0.0);

    /*counter-=1.0;
    if(counter<=0.0){
        counter=15.0;
    }*/
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.03*sin(i)-0.3f;
        y=0.05*cos(i)-0.45f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.2f,0.5f, 0.1f);
    x=0.03*sin(i)-0.3f;
    y=0.05*cos(i)-0.6f;
    glVertex2f(x,y);
    glVertex2f(x,-1.0f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.2f,0.5f, 0.1f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.045*sin(i)+0.07f-0.35f;
        y=-0.03*cos(i)-0.7f;
        glVertex2f(x,y);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.05*sin(i)-0.35f;
        y=0.03*cos(i)-0.48f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.035*sin(i)-0.35f+0.02f+0.005f;
        y=0.04*cos(i)-0.52f-0.02f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.04*sin(i)-0.35f+0.02f+0.06f;
        y=0.035*cos(i)-0.52f-0.02f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.05*sin(i)-0.35f+0.02f+0.06f;
        y=0.035*cos(i)-0.485f;
        glVertex2f(x,y);
    }
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.5f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.03*sin(i)-0.3f;
        y=0.03*cos(i)-0.5f;
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    //flower
    glPushMatrix();


    glRotatef(7.0,0.0,0.0,1.0);
    glTranslatef(0.2f, -0.05f, 0.0f);
    //glRotatef(15.0f,0.0,1.0,0.0);

    /*counter-=1.0;
    if(counter<=0.0){
        counter=15.0;
    }*/
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.03*sin(i)-0.3f;
        y=0.05*cos(i)-0.45f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.2f,0.5f, 0.1f);
    x=0.03*sin(i)-0.3f;
    y=0.05*cos(i)-0.6f;
    glVertex2f(x,y);
    glVertex2f(x,-1.0f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.2f,0.5f, 0.1f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.045*sin(i)+0.07f-0.35f;
        y=-0.03*cos(i)-0.7f;
        glVertex2f(x,y);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.05*sin(i)-0.35f;
        y=0.03*cos(i)-0.48f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.035*sin(i)-0.35f+0.02f+0.005f;
        y=0.04*cos(i)-0.52f-0.02f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.04*sin(i)-0.35f+0.02f+0.06f;
        y=0.035*cos(i)-0.52f-0.02f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.05*sin(i)-0.35f+0.02f+0.06f;
        y=0.035*cos(i)-0.485f;
        glVertex2f(x,y);
    }
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.5f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.03*sin(i)-0.3f;
        y=0.03*cos(i)-0.5f;
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    //flower
    glPushMatrix();


    glRotatef(5.0,0.0,0.0,1.0);
    glTranslatef(0.4f, -0.05f, 0.0f);
    //glRotatef(15.0f,0.0,1.0,0.0);

    /*counter-=1.0;
    if(counter<=0.0){
        counter=15.0;
    }*/
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.03*sin(i)-0.3f;
        y=0.05*cos(i)-0.45f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.2f,0.5f, 0.1f);
    x=0.03*sin(i)-0.3f;
    y=0.05*cos(i)-0.6f;
    glVertex2f(x,y);
    glVertex2f(x,-1.0f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.2f,0.5f, 0.1f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.045*sin(i)+0.07f-0.35f;
        y=-0.03*cos(i)-0.7f;
        glVertex2f(x,y);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.05*sin(i)-0.35f;
        y=0.03*cos(i)-0.48f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.035*sin(i)-0.35f+0.02f+0.005f;
        y=0.04*cos(i)-0.52f-0.02f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.04*sin(i)-0.35f+0.02f+0.06f;
        y=0.035*cos(i)-0.52f-0.02f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.05*sin(i)-0.35f+0.02f+0.06f;
        y=0.035*cos(i)-0.485f;
        glVertex2f(x,y);
    }
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.5f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.03*sin(i)-0.3f;
        y=0.03*cos(i)-0.5f;
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    //flower
    glPushMatrix();


    glRotatef(5.0,0.0,0.0,1.0);
    glTranslatef(0.6f, -0.05f, 0.0f);
    //glRotatef(15.0f,0.0,1.0,0.0);

    /*counter-=1.0;
    if(counter<=0.0){
        counter=15.0;
    }*/
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.03*sin(i)-0.3f;
        y=0.05*cos(i)-0.45f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.2f,0.5f, 0.1f);
    x=0.03*sin(i)-0.3f;
    y=0.05*cos(i)-0.6f;
    glVertex2f(x,y);
    glVertex2f(x,-1.0f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.2f,0.5f, 0.1f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.045*sin(i)+0.07f-0.35f;
        y=-0.03*cos(i)-0.7f;
        glVertex2f(x,y);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.05*sin(i)-0.35f;
        y=0.03*cos(i)-0.48f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.035*sin(i)-0.35f+0.02f+0.005f;
        y=0.04*cos(i)-0.52f-0.02f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.04*sin(i)-0.35f+0.02f+0.06f;
        y=0.035*cos(i)-0.52f-0.02f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.05*sin(i)-0.35f+0.02f+0.06f;
        y=0.035*cos(i)-0.485f;
        glVertex2f(x,y);
    }
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.5f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.03*sin(i)-0.3f;
        y=0.03*cos(i)-0.5f;
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    //flower
    glPushMatrix();


    glRotatef(5.0,0.0,0.0,1.0);
    glTranslatef(1.05f, -0.07f, 0.0f);
    //glRotatef(15.0f,0.0,1.0,0.0);

    /*counter-=1.0;
    if(counter<=0.0){
        counter=15.0;
    }*/
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.03*sin(i)-0.3f;
        y=0.05*cos(i)-0.45f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.2f,0.5f, 0.1f);
    x=0.03*sin(i)-0.3f;
    y=0.05*cos(i)-0.6f;
    glVertex2f(x,y);
    glVertex2f(x,-1.0f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.2f,0.5f, 0.1f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.045*sin(i)+0.07f-0.35f;
        y=-0.03*cos(i)-0.7f;
        glVertex2f(x,y);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.05*sin(i)-0.35f;
        y=0.03*cos(i)-0.48f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.035*sin(i)-0.35f+0.02f+0.005f;
        y=0.04*cos(i)-0.52f-0.02f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.04*sin(i)-0.35f+0.02f+0.06f;
        y=0.035*cos(i)-0.52f-0.02f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.05*sin(i)-0.35f+0.02f+0.06f;
        y=0.035*cos(i)-0.485f;
        glVertex2f(x,y);
    }
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.5f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.03*sin(i)-0.3f;
        y=0.03*cos(i)-0.5f;
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();



    //flower
    glPushMatrix();


    glRotatef(5.0,0.0,0.0,1.0);
    glTranslatef(1.3f, -0.065f, 0.0f);
    //glRotatef(15.0f,0.0,1.0,0.0);

    /*counter-=1.0;
    if(counter<=0.0){
        counter=15.0;
    }*/
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.03*sin(i)-0.3f;
        y=0.05*cos(i)-0.45f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.2f,0.5f, 0.1f);
    x=0.03*sin(i)-0.3f;
    y=0.05*cos(i)-0.6f;
    glVertex2f(x,y);
    glVertex2f(x,-1.0f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.2f,0.5f, 0.1f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.045*sin(i)+0.07f-0.35f;
        y=-0.03*cos(i)-0.7f;
        glVertex2f(x,y);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.05*sin(i)-0.35f;
        y=0.03*cos(i)-0.48f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.035*sin(i)-0.35f+0.02f+0.005f;
        y=0.04*cos(i)-0.52f-0.02f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.04*sin(i)-0.35f+0.02f+0.06f;
        y=0.035*cos(i)-0.52f-0.02f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.05*sin(i)-0.35f+0.02f+0.06f;
        y=0.035*cos(i)-0.485f;
        glVertex2f(x,y);
    }
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.5f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.03*sin(i)-0.3f;
        y=0.03*cos(i)-0.5f;
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    //flower
    glPushMatrix();


    glRotatef(5.0,0.0,0.0,1.0);
    glTranslatef(0.9f, -0.05f, 0.0f);
    //glRotatef(15.0f,0.0,1.0,0.0);

    /*counter-=1.0;
    if(counter<=0.0){
        counter=15.0;
    }*/
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.03*sin(i)-0.3f;
        y=0.05*cos(i)-0.45f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.2f,0.5f, 0.1f);
    x=0.03*sin(i)-0.3f;
    y=0.05*cos(i)-0.6f;
    glVertex2f(x,y);
    glVertex2f(x,-1.0f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.2f,0.5f, 0.1f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.045*sin(i)+0.07f-0.35f;
        y=-0.03*cos(i)-0.7f;
        glVertex2f(x,y);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.05*sin(i)-0.35f;
        y=0.03*cos(i)-0.48f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.035*sin(i)-0.35f+0.02f+0.005f;
        y=0.04*cos(i)-0.52f-0.02f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.04*sin(i)-0.35f+0.02f+0.06f;
        y=0.035*cos(i)-0.52f-0.02f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.05*sin(i)-0.35f+0.02f+0.06f;
        y=0.035*cos(i)-0.485f;
        glVertex2f(x,y);
    }
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.5f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.03*sin(i)-0.3f;
        y=0.03*cos(i)-0.5f;
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    //flower
    glPushMatrix();


    glRotatef(5.0,0.0,0.0,-1.0);
    glTranslatef(0.855f, -0.05f, 0.0f);
    //glRotatef(15.0f,0.0,1.0,0.0);

    /*counter-=1.0;
    if(counter<=0.0){
        counter=15.0;
    }*/
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.03*sin(i)-0.3f;
        y=0.05*cos(i)-0.45f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.2f,0.5f, 0.1f);
    x=0.03*sin(i)-0.3f;
    y=0.05*cos(i)-0.6f;
    glVertex2f(x,y);
    glVertex2f(x,-1.0f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.2f,0.5f, 0.1f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.045*sin(i)+0.07f-0.35f;
        y=-0.03*cos(i)-0.7f;
        glVertex2f(x,y);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.05*sin(i)-0.35f;
        y=0.03*cos(i)-0.48f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.035*sin(i)-0.35f+0.02f+0.005f;
        y=0.04*cos(i)-0.52f-0.02f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.04*sin(i)-0.35f+0.02f+0.06f;
        y=0.035*cos(i)-0.52f-0.02f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.05*sin(i)-0.35f+0.02f+0.06f;
        y=0.035*cos(i)-0.485f;
        glVertex2f(x,y);
    }
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.5f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.03*sin(i)-0.3f;
        y=0.03*cos(i)-0.5f;
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    //flower
    glPushMatrix();


    glRotatef(5.0,0.0,0.0,-1.0);
    glTranslatef(0.03f, -0.05f, 0.0f);
    //glRotatef(15.0f,0.0,1.0,0.0);

    /*counter-=1.0;
    if(counter<=0.0){
        counter=15.0;
    }*/
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.03*sin(i)-0.3f;
        y=0.05*cos(i)-0.45f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.2f,0.5f, 0.1f);
    x=0.03*sin(i)-0.3f;
    y=0.05*cos(i)-0.6f;
    glVertex2f(x,y);
    glVertex2f(x,-1.0f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.2f,0.5f, 0.1f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.045*sin(i)+0.07f-0.35f;
        y=-0.03*cos(i)-0.7f;
        glVertex2f(x,y);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.05*sin(i)-0.35f;
        y=0.03*cos(i)-0.48f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.035*sin(i)-0.35f+0.02f+0.005f;
        y=0.04*cos(i)-0.52f-0.02f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.04*sin(i)-0.35f+0.02f+0.06f;
        y=0.035*cos(i)-0.52f-0.02f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.3f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.05*sin(i)-0.35f+0.02f+0.06f;
        y=0.035*cos(i)-0.485f;
        glVertex2f(x,y);
    }
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.5f,0.0f);
    //glVertex2f(0.5f, 0.6f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.03*sin(i)-0.3f;
        y=0.03*cos(i)-0.5f;
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    if(fishSight==true) {

        //fish
        glLoadIdentity();
        glPushMatrix();
        glRotatef(30.0f, 0.0f, 0.0f, 1.0f);

        glRotatef(counterFish,0.0,0.0,-1.0);
        counterFish+=10.0;

        //glRotatef(15.0f, 0.0f, 0.0f, -1.0f);
        //glRotatef(15.0f, 0.0f, 0.0f, 1.0f);
        //glRotatef(15.0f, 0.0f, 0.0f, 1.0f);
        //glTranslatef(0.1f, 0.1f, 0.0f);



        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.8f,0.8f,0.8f);
        for(i=0; i<=2*3.14; i+=0.001)
        {
            x=0.06*sin(i);
            y=0.03*cos(i);
            glVertex2f(x,y-0.23f);
        }
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(0.0f+0.05f, 0.0f-0.23f);
        glVertex2f(0.05f+0.05f, -0.07f-0.23f);
        glVertex2f(0.05f+0.05f, 0.07f-0.23f);
        glEnd();
        glPopMatrix();
    }


    //river2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 0.8f);
    glVertex2f(-1.0f, -0.182f);
    glVertex2f(-1.0f, -0.4f);
    glVertex2f(1.0f, -0.4f);
    glVertex2f(1.0f, -0.18f);
    glEnd();

    //street light
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1f,0.1f,0.1f);
    for(i=0; i<=2*3.14; i+=0.001)
    {
        x=0.03*sin(i)-0.5f-0.2f;
        y=0.01*cos(i)+0.05f;
        glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.1f,0.1f,0.1f);
    //glPointSize(50.0);
    glVertex2f(0.01f-0.5f-0.2f, -0.1f);
    glVertex2f(-0.01f-0.5f-0.2f, -0.1f);
    glVertex2f(-0.01f-0.5f-0.2f, -1.0f);
    glVertex2f(0.01f-0.5f-0.2f, -1.0f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f,1.0f,1.0f);
    glPointSize(20.0);
    glVertex2f(-0.05f-0.5f-0.2f, 0.0f-0.05f);
    glVertex2f(0.0f-0.5f-0.2f, -0.1f-0.05f);
    glVertex2f(0.05f-0.5f-0.2f, 0.0f-0.05f);
    glVertex2f(0.0f-0.5f-0.2f, 0.1f-0.05f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9f,0.9f,0.9f);
    //glPointSize(50.0);
    glVertex2f(-0.05f-0.5f-0.2f, 0.0f-0.05f);
    glVertex2f(0.0f-0.5f-0.2f, -0.1f-0.05f);
    glVertex2f(0.05f-0.5f-0.2f, 0.0f-0.05f);
    glVertex2f(0.0f-0.5f-0.2f, 0.1f-0.05f);
    glEnd();
    if(nightMode==true) {
        glBegin(GL_QUADS);
        glColor3f(1.0f,1.0f,0.4f);
        //glPointSize(50.0);
        glVertex2f(-0.05f-0.5f-0.2f, 0.0f-0.05f);
        glVertex2f(0.0f-0.5f-0.2f, -0.1f-0.05f);
        glVertex2f(0.05f-0.5f-0.2f, 0.0f-0.05f);
        glVertex2f(0.0f-0.5f-0.2f, 0.1f-0.05f);
        glEnd();
    }
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f,1.0f,1.0f);
    glPointSize(20.0);
    glVertex2f(-0.025f-0.5f-0.2f, 0.0f-0.05f);
    glVertex2f(0.0f-0.5f-0.2f, -0.1f-0.05f);
    glVertex2f(0.025f-0.5f-0.2f, 0.0f-0.05f);
    glVertex2f(0.0f-0.5f-0.2f, 0.1f-0.05f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.1f,0.1f,0.1f);
    glPointSize(50.0);
    glVertex2f(-0.015f-0.5f-0.2f, 0.0f-0.05f+0.12f);
    glVertex2f(0.0f-0.5f-0.2f, -0.035f-0.05f+0.12f);
    glVertex2f(0.015f-0.5f-0.2f, 0.0f-0.05f+0.12f);
    glVertex2f(0.0f-0.5f-0.2f, 0.035f-0.05f+0.12f);
    glEnd();

    glFlush();
    glutSwapBuffers();
}


int main(int argc, char** argv) {
    cout << "Countryside Landscape\n";
    cout << "Interactions:\n";
    cout << "d: Day mode\n";
    cout << "f: Fish jumping view\n";
    cout << "m: Stop fish jumping view\n";
    cout << "n: Night Mode\n";
    cout << "o: Plane speed increase\n";
    cout << "p: Plane speed stop\n";


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Countryside Landscape");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    init();
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutTimerFunc(1000, update, 0);
    glutMainLoop();

    return 0;
}
