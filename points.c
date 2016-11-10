#include <GL/glew.h>
#include <stdio.h>
#include <GL/glut.h>
#include "math_3d.h"

#define WIDTH  256
#define HEIGHT 256
#define PIXL 4

GLuint VBO;


static
void
display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_POINTS, 0, 1);

    glDisableVertexAttribArray(0);

    glutSwapBuffers();
}


static
void
keyboard(unsigned char key, int x, int y) {
    (void) x;
    (void) y;
    switch (key) {
    case 'q':
    case 'Q':
    case 27:
        exit(0);
        break;
    }
    glutPostRedisplay();
}



int
main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(3 * WIDTH, 3 * HEIGHT);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("points");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    GLenum GLEWinit = glewInit();
    if (GLEW_OK != GLEWinit) {
        fprintf(stderr, "GLEW: %s\n", glewGetErrorString(GLEWinit));
        return 1;
    }

    printf("GL_VERSION = %s\n", glGetString(GL_VERSION));
    printf("GL_RENDERER = %s\n", glGetString(GL_RENDERER));

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    Vector3f verts[1];
    verts[0] = Vector3f(0.0f, 0.0f, 0.0f);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

    glutMainLoop();
    return 0;
}
