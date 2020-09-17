#include<cstdio>
#include<iostream>
using namespace std;
#include<math.h>
#include <GL/gl.h>
#include <GL/glut.h>


GLfloat cloudPosition = 0.0f;
GLfloat boatPosition = 0.0f;
GLfloat fishPosition = 0.0f;
GLfloat position = 0.0f;
GLfloat position2 = 0.0f;
GLfloat childSet1 = 0.0f;
GLfloat childSet2 = 0.0f;
GLfloat childSpeed = 0.01f;
GLfloat speed = 0.1f;
GLfloat speedCloud = 0.01f;
GLfloat boatSpeed = 0.025f;
float fish_t_x[10];
float fish_t_y[10];
float fish_r_a[10];
float fish_r_d[10];
int counter = 10.0f;
int point = 0;
float x, y , i;
int j;

void update(int value) {

    if (cloudPosition < -1.5f){
        cloudPosition = 1.2f;
    }

    cloudPosition -= speedCloud;

    if (cloudPosition > 1.5f){
        cloudPosition = -1.2f;
    }

    if(position2 < -1.5f)
      {
         position2 = 1.2f;
      }


   position2 -= speedCloud;

      if(childSet1 > 0.05f){

          childSet1 = 0.0f;
      }

      if(childSet1 < 0.0f){
        childSet1 = 0.00f;
      }

      childSet1 += childSpeed;

      if(boatPosition > 1.68f){
        boatPosition = -4.5f;
      }
      boatPosition += boatSpeed;



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
	for(i=0;i<=2*3.14;i+=0.001)
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
    glColor3f(0.0f, 1.0f, 0.5f);
    glVertex2f(-1.0f, -0.3f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.3f);
    glEnd();

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
     //Fish
     glPushMatrix();
    glTranslatef(boatPosition, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.220f, 0.0f);
    glVertex2f(-0.25,-0.2);
    glVertex2f(-0.2,-0.2);
    glVertex2f(-0.1,-0.15);
    glEnd();
glPopMatrix();
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

glBegin(GL_QUADS);
glColor3f(0.7f, 0.4f, 0.2f);
glVertex2f(-0.12f, 0.08f-0.03f-0.05f);
glVertex2f(-0.09f, 0.08f-0.03f-0.05f);
glVertex2f(-0.09f, 0.22f+0.35f-0.03f-0.05f);
glVertex2f(-0.12f,0.22f+0.35f-0.03f-0.05f);
glEnd();
glPopMatrix();

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
		for(i=0;i<=2*3.14;i+=0.001)
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
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.045*sin(i)+0.07f-0.35f;
			y=-0.03*cos(i)-0.7f;
			glVertex2f(x,y);
		}
	glEnd();

	       glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.05*sin(i)-0.35f;
			y=0.03*cos(i)-0.48f;
			glVertex2f(x,y);
		}
		glEnd();
        glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.035*sin(i)-0.35f+0.02f+0.005f;
			y=0.04*cos(i)-0.52f-0.02f;
			glVertex2f(x,y);
		}
		glEnd();
        glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.04*sin(i)-0.35f+0.02f+0.06f;
			y=0.035*cos(i)-0.52f-0.02f;
			glVertex2f(x,y);
		}
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.05*sin(i)-0.35f+0.02f+0.06f;
			y=0.035*cos(i)-0.485f;
			glVertex2f(x,y);
		}
		glEnd();


    glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.5f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
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
		for(i=0;i<=2*3.14;i+=0.001)
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
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.045*sin(i)+0.07f-0.35f;
			y=-0.03*cos(i)-0.7f;
			glVertex2f(x,y);
		}
	glEnd();

	       glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.05*sin(i)-0.35f;
			y=0.03*cos(i)-0.48f;
			glVertex2f(x,y);
		}
		glEnd();
        glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.035*sin(i)-0.35f+0.02f+0.005f;
			y=0.04*cos(i)-0.52f-0.02f;
			glVertex2f(x,y);
		}
		glEnd();
        glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.04*sin(i)-0.35f+0.02f+0.06f;
			y=0.035*cos(i)-0.52f-0.02f;
			glVertex2f(x,y);
		}
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.05*sin(i)-0.35f+0.02f+0.06f;
			y=0.035*cos(i)-0.485f;
			glVertex2f(x,y);
		}
		glEnd();


    glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.5f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
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
		for(i=0;i<=2*3.14;i+=0.001)
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
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.045*sin(i)+0.07f-0.35f;
			y=-0.03*cos(i)-0.7f;
			glVertex2f(x,y);
		}
	glEnd();

	       glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.05*sin(i)-0.35f;
			y=0.03*cos(i)-0.48f;
			glVertex2f(x,y);
		}
		glEnd();
        glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.035*sin(i)-0.35f+0.02f+0.005f;
			y=0.04*cos(i)-0.52f-0.02f;
			glVertex2f(x,y);
		}
		glEnd();
        glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.04*sin(i)-0.35f+0.02f+0.06f;
			y=0.035*cos(i)-0.52f-0.02f;
			glVertex2f(x,y);
		}
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.05*sin(i)-0.35f+0.02f+0.06f;
			y=0.035*cos(i)-0.485f;
			glVertex2f(x,y);
		}
		glEnd();


    glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.5f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
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
		for(i=0;i<=2*3.14;i+=0.001)
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
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.045*sin(i)+0.07f-0.35f;
			y=-0.03*cos(i)-0.7f;
			glVertex2f(x,y);
		}
	glEnd();

	       glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.05*sin(i)-0.35f;
			y=0.03*cos(i)-0.48f;
			glVertex2f(x,y);
		}
		glEnd();
        glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.035*sin(i)-0.35f+0.02f+0.005f;
			y=0.04*cos(i)-0.52f-0.02f;
			glVertex2f(x,y);
		}
		glEnd();
        glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.04*sin(i)-0.35f+0.02f+0.06f;
			y=0.035*cos(i)-0.52f-0.02f;
			glVertex2f(x,y);
		}
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.05*sin(i)-0.35f+0.02f+0.06f;
			y=0.035*cos(i)-0.485f;
			glVertex2f(x,y);
		}
		glEnd();


    glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.5f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
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
		for(i=0;i<=2*3.14;i+=0.001)
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
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.045*sin(i)+0.07f-0.35f;
			y=-0.03*cos(i)-0.7f;
			glVertex2f(x,y);
		}
	glEnd();

	       glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.05*sin(i)-0.35f;
			y=0.03*cos(i)-0.48f;
			glVertex2f(x,y);
		}
		glEnd();
        glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.035*sin(i)-0.35f+0.02f+0.005f;
			y=0.04*cos(i)-0.52f-0.02f;
			glVertex2f(x,y);
		}
		glEnd();
        glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.04*sin(i)-0.35f+0.02f+0.06f;
			y=0.035*cos(i)-0.52f-0.02f;
			glVertex2f(x,y);
		}
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.05*sin(i)-0.35f+0.02f+0.06f;
			y=0.035*cos(i)-0.485f;
			glVertex2f(x,y);
		}
		glEnd();


    glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.5f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
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
		for(i=0;i<=2*3.14;i+=0.001)
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
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.045*sin(i)+0.07f-0.35f;
			y=-0.03*cos(i)-0.7f;
			glVertex2f(x,y);
		}
	glEnd();

	       glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.05*sin(i)-0.35f;
			y=0.03*cos(i)-0.48f;
			glVertex2f(x,y);
		}
		glEnd();
        glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.035*sin(i)-0.35f+0.02f+0.005f;
			y=0.04*cos(i)-0.52f-0.02f;
			glVertex2f(x,y);
		}
		glEnd();
        glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.04*sin(i)-0.35f+0.02f+0.06f;
			y=0.035*cos(i)-0.52f-0.02f;
			glVertex2f(x,y);
		}
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.05*sin(i)-0.35f+0.02f+0.06f;
			y=0.035*cos(i)-0.485f;
			glVertex2f(x,y);
		}
		glEnd();


    glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.5f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
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
		for(i=0;i<=2*3.14;i+=0.001)
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
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.045*sin(i)+0.07f-0.35f;
			y=-0.03*cos(i)-0.7f;
			glVertex2f(x,y);
		}
	glEnd();

	       glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.05*sin(i)-0.35f;
			y=0.03*cos(i)-0.48f;
			glVertex2f(x,y);
		}
		glEnd();
        glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.035*sin(i)-0.35f+0.02f+0.005f;
			y=0.04*cos(i)-0.52f-0.02f;
			glVertex2f(x,y);
		}
		glEnd();
        glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.04*sin(i)-0.35f+0.02f+0.06f;
			y=0.035*cos(i)-0.52f-0.02f;
			glVertex2f(x,y);
		}
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.05*sin(i)-0.35f+0.02f+0.06f;
			y=0.035*cos(i)-0.485f;
			glVertex2f(x,y);
		}
		glEnd();


    glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.5f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
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
		for(i=0;i<=2*3.14;i+=0.001)
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
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.045*sin(i)+0.07f-0.35f;
			y=-0.03*cos(i)-0.7f;
			glVertex2f(x,y);
		}
	glEnd();

	       glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.05*sin(i)-0.35f;
			y=0.03*cos(i)-0.48f;
			glVertex2f(x,y);
		}
		glEnd();
        glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.035*sin(i)-0.35f+0.02f+0.005f;
			y=0.04*cos(i)-0.52f-0.02f;
			glVertex2f(x,y);
		}
		glEnd();
        glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.04*sin(i)-0.35f+0.02f+0.06f;
			y=0.035*cos(i)-0.52f-0.02f;
			glVertex2f(x,y);
		}
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.05*sin(i)-0.35f+0.02f+0.06f;
			y=0.035*cos(i)-0.485f;
			glVertex2f(x,y);
		}
		glEnd();


    glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.5f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
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
		for(i=0;i<=2*3.14;i+=0.001)
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
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.045*sin(i)+0.07f-0.35f;
			y=-0.03*cos(i)-0.7f;
			glVertex2f(x,y);
		}
	glEnd();

	       glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.05*sin(i)-0.35f;
			y=0.03*cos(i)-0.48f;
			glVertex2f(x,y);
		}
		glEnd();
        glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.035*sin(i)-0.35f+0.02f+0.005f;
			y=0.04*cos(i)-0.52f-0.02f;
			glVertex2f(x,y);
		}
		glEnd();
        glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.04*sin(i)-0.35f+0.02f+0.06f;
			y=0.035*cos(i)-0.52f-0.02f;
			glVertex2f(x,y);
		}
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.3f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.05*sin(i)-0.35f+0.02f+0.06f;
			y=0.035*cos(i)-0.485f;
			glVertex2f(x,y);
		}
		glEnd();


    glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f,0.5f,0.0f);
		//glVertex2f(0.5f, 0.6f);
		for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.03*sin(i)-0.3f;
			y=0.03*cos(i)-0.5f;
			glVertex2f(x,y);
		}
	glEnd();
	glPopMatrix();

	//fish
	/*glPushMatrix();

	glRotatef(15.0f, 0.0f, 0.0f, -1.0f);
	glRotatef(15.0f, 0.0f, 0.0f, 1.0f);
	//glRotatef(15.0f, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.1f, 0.1f, 0.0f);



	    glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.8f,0.8f,0.8f);
			for(i=0;i<=2*3.14;i+=0.001)
		{
			x=0.06*sin(i);
			y=0.03*cos(i);
			glVertex2f(x,y);
		}
		glEnd();
		glBegin(GL_TRIANGLES);
		glColor3f(0.8f,0.8f,0.8f);
		glVertex2f(0.0f+0.05f, 0.0f);
		glVertex2f(0.05f+0.05f, -0.07f);
		glVertex2f(0.05f+0.05f, 0.07f);
		glEnd();
    glPopMatrix();*/

















   glFlush();
   glutSwapBuffers();
}





int main(int argc, char** argv) {
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
