#include <iostream>
#include <GLFW/glfw3.h>
#include <GLUT/GLUT.h>
#include <vector>
#include <math.h>

const GLfloat width = 500;
const GLfloat height = 500;

GLubyte cubeIndices[24] = {0,3,2,1,2,3,7,6
    ,0,4,7,3,1,2,6,5,4,5,6,7,0,1,5,4};

GLfloat vertices[][3] =
{{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
    {1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0},
    {1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0}};

GLfloat colors[][3] =
{{0.0,0.0,0.0},{1.0,0.0,0.0},
    {1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0},
    {1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};

void display(){
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    //glDrawArrays(GL_QUADS, 0, 24);
    glDrawElements(GL_QUADS, 24,GL_UNSIGNED_BYTE, cubeIndices);
    glDisableClientState(GL_VERTEX_ARRAY);
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y){

}

void keyboard(unsigned char key, int x, int y){
    if(key=='q' || key == 'Q') exit(0);
}

void init(){
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,width ,height, 0);
    glMatrixMode(GL_MODELVIEW);

    glClearColor (1.0, 1.0, 1.0,1.0);
    //glColor3f(0.0,0.0,0.0);
}

void idle(){

}

int main(int argc,  char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("Assignment 3");
    glutPositionWindow(0, 0);


    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);

    init();
    glutMainLoop();
}
