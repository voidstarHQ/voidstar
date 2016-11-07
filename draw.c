#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

#define W 260
#define H 260

static
void
display() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    unsigned data[3 * W * H];
    /* for (size_t y = 0; y < W; ++y) { */
    /*     for (size_t x = 0; x < H; ++x) { */
    /*         data[3 * (x + W * y) + 0] = ( rand() % 255 ) * 255 * 255 * 255; */
    /*         data[3 * (x + W * y) + 1] = ( rand() % 255 ) * 255 * 255 * 255; */
    /*         data[3 * (x + W * y) + 2] = ( rand() % 255 ) * 255 * 255 * 255; */
    /*         /\* data[2][x][y] = ( rand() % 255 ) * 255 * 255 * 255; *\/ */
    /*     } */
    /* } */

    for (size_t i = 0; i < 3 * W * H; ++i) {
        /* unsigned current; */
        /* if (1 == fread(&current, 1, 1, stdin)) { */
            data[i] = 150;
            /* data[3 * (x + W * y) + 0] = 1; */
            /* data[3 * (x + W * y) + 1] = 1; */
            /* data[3 * (x + W * y) + 2] = 1; */
        /* } else { */
        /*     perror("read"); */
        /*     exit(1); */
        /* } */
    }

    glDrawPixels(W, H, GL_RGB, GL_UNSIGNED_INT, data);

    glutSwapBuffers();
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
}


int
main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(W, H);
    glutCreateWindow("miners");
    glutDisplayFunc(display);
    glutKeyboardFunc(Key);
    glutMainLoop();
    return 0;
}
