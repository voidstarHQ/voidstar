#include <math.h>
#include <stdlib.h>
#include <vector>
#include "point.h"

GLfloat mouseX_, mouseY_; //posicao inicial do cursor
bool rotationing = true;
GLfloat matrix [] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};

std::vector<Point> points; 
bool mousePlot = true;
 
void
display(void) {
/* display callback, clear frame buffer and z buffer,
   plot points and draw references, swap buffers */
 
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
 glutWireTeapot(100);
 
  for (size_t i = 0; i < points.size(); i++) {
      glBegin(GL_POINTS);
        glColor3f(1.0,0.0,0.1);
        glPointSize(100);         
        glVertex3f(points.at(i).x, points.at(i).y, points.at(i).z);
      glEnd();
  }
 
 glFlush();
 glutSwapBuffers();
}
 
void mouse(int btn, int state, int x, int y)
{
 
    if(btn == GLUT_LEFT_BUTTON && mousePlot){
        float x_ = (float) x - glutGet(GLUT_WINDOW_WIDTH)/2;
        float y_ = (float) -(y - glutGet(GLUT_WINDOW_HEIGHT)/2);
        float z = 0.0;
 
        Point *p = new Point(x_,y_,z);
 
        points.push_back(*p);
    }
 
    if(btn == GLUT_RIGHT_BUTTON){
        mousePlot = !mousePlot;
    }
 
}
 
void myReshape(int w, int h)
{
    float nRange = w/2;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-w/2, w/2, -h/2, h/2, -nRange, nRange);
    glMatrixMode(GL_MODELVIEW);
}
 
void trackball(int PX, int PY){
 
    //mouse = anterior position
    //P = position in use
 
    if (rotationing && !mousePlot){
        GLint W = glutGet(GLUT_WINDOW_WIDTH);
        GLint H = glutGet(GLUT_WINDOW_HEIGHT);
 
        GLfloat ray; //for while, i needn't take the sqrt for the ray.
        if (W>H) ray=W*W/2; 
        else ray=H*H/2;
 
        mouseX_ -= W/2;         //
        GLfloat px = PX - W/2;   // this part is to use the center 
        mouseY_ = H/2 - mouseY_; // of the screen as the origin
        GLfloat py = H/2 - PY;   //
        //the idea is to find the Z coordinate of the two points in sphere's surface centered in the origin
        GLfloat mouseX_Y2 = mouseX_*mouseX_ + mouseY_*mouseY_;
        GLfloat pXY2 = px*px+py*py;
 
        if (mouseX_Y2 < ray && pXY2 < ray){ //this trackball only works for points inside the sphere
 
            GLfloat mouseZ = sqrt(ray - mouseX_Y2);
 
            GLfloat pz = sqrt(ray - pXY2);
 
            GLfloat axisRotation[3]; //vector product "mouse X P"
            axisRotation[0] = -mouseZ*py + mouseY_*pz;
            axisRotation[1] = mouseZ*px - mouseX_*pz;
            axisRotation[2] = -mouseY_*px + mouseX_*py;
 
            GLfloat anguloRotacao = atan(sqrt(axisRotation[0]*axisRotation[0] + axisRotation[1]*axisRotation[1] + axisRotation[2]*axisRotation[2]));
 
            glMatrixMode( GL_MODELVIEW );
            glLoadIdentity();
            glRotatef(anguloRotacao,axisRotation[0],axisRotation[1],axisRotation[2]);
            glMultMatrixf(matrix);
            glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
        }
    } 
    mouseX_ = PX;
    mouseY_ = PY;
    glutPostRedisplay();
 
}
 
int
main(int argc, char **argv)
{
    glutInit(&argc, argv);
/* need both double buffering and z buffer */
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("draw :)");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);     
    glutMouseFunc(mouse);
    glutMotionFunc(trackball);
    glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
    glutMainLoop();
    return 0;
}
