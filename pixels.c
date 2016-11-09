#include <stdio.h>
#include <GL/glut.h>

#define wWIDTH  260
#define wHEIGHT 260

static GLubyte Image[wWIDTH * wHEIGHT * 4];


static
GLboolean
ReadData() {
    for (int i = 0; i < wWIDTH * wHEIGHT * 4; i += 4) {
        Image[i + 0] = 0;
        Image[i + 1] = 0;
        Image[i + 2] = 0;
        Image[i + 3] = 255;
    }

    unsigned char previous = 0;
    /* for (int i = 0; i < wWIDTH * wHEIGHT; ++i) { */
    for (int i = 0; i < wWIDTH * wHEIGHT; i += 4) {
        unsigned char current = 0;
        if (fread(&current, 1, 1, stdin) == 1) {
            if (0 == i) {
                previous = current;
                continue;
            }
            int idx = wWIDTH * previous + current;
            Image[idx + 0] = 1 + Image[idx + 0];
            Image[idx + 1] = 1 + Image[idx + 1];
            Image[idx + 2] = 1 + Image[idx + 2];
            Image[idx + 3] = 255;
            previous = current;
        }
        else
            return GL_FALSE;
    }
    return GL_TRUE;
}


static
void
Display(void) {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    float zoom = 3.0;
    glPixelZoom(zoom, zoom);

    if (GL_TRUE != ReadData()) {
        perror("read");
        exit(0);
    }
    glDrawPixels(wWIDTH, wHEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, Image);
    /* glDrawPixels(wWIDTH, wHEIGHT, GL_LUMINANCE, GL_UNSIGNED_BYTE, Image); */

    glutSwapBuffers();
}


static
void
Reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, 0.0, height, 0.0, 2.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


static
void
Key(unsigned char key, int x, int y) {
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
    glutInitWindowSize(2*wWIDTH, 2*wHEIGHT);
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

    glutCreateWindow(argv[0]);

    printf("GL_VERSION = %s\n", (char *) glGetString(GL_VERSION));
    printf("GL_RENDERER = %s\n", (char *) glGetString(GL_RENDERER));
    printf("%dx%d\n", wWIDTH, wHEIGHT);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glPixelStorei(GL_UNPACK_ROW_LENGTH, wWIDTH);

    printf("Keys:\n"
           "     ESC Q q  Exit\n");

    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Key);
    glutDisplayFunc(Display);

    glutMainLoop();
    return 0;
}
