#include <GL/glut.h>
#include <cmath>

void task1();
void task2();

void RenderScene();

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(700, 70);
    glutInitWindowSize(900, 900);
    glutCreateWindow("Game");

    glutDisplayFunc(RenderScene);
    glutMainLoop();
    return 0;
}

void RenderScene() {

    glClearColor(0.8, 0.8, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    task1();
    task2();

    glutSwapBuffers();
}



void task1(){
    float t=0, x=0, y=0;

    glPushMatrix();
    glScalef(.05, .05, .05);
    glBegin(GL_LINE_STRIP);
    glColor3f(1, 1, 1);

    while (t<5*M_PI){
        x=t*sin(t);
        y=t*cos(t);
        glVertex2f(x, y);
        t+=M_PI/100;
    }

    glEnd();
    glPopMatrix();
}

void task2(){
    float t=0, x=0, y=0;

    glPushMatrix();
    glScalef(.05, .05, .05);
    glBegin(GL_LINE_STRIP);
    glColor3f(1, 1, 1);

    while (t<2*M_PI){
        x=16*pow(sin(t), 3);
        y=(13*cos(t))-(5*cos(2*t))-(2*cos(3*t))-cos(4*t);
        glVertex2f(x, y);
        t+=M_PI/100;
    }

    glEnd();
    glPopMatrix();
}
