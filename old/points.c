#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glext.h>

#include "shaders.hh"

#define WIDTH  256
#define HEIGHT 256
#define DEPTH 256
#define PIXL 4

struct content {
    size_t height;
    size_t width;
    size_t depth;
    size_t size;
    GLuint program_id;
    GLuint vertex_buffer_id;
    GLuint vertex_colors_id;
    GLfloat *vertex_buffer;
    GLfloat *vertex_colors;
};

struct content *global_ctx;

static struct content *
content_create()
{
    struct content *ctx = new struct content;
    if (!ctx) {
        return NULL;
    }
    ctx->width = WIDTH;
    ctx->height = HEIGHT;
    ctx->depth = DEPTH;
    ctx->size = ctx->width * ctx->height * ctx->depth * 3;
    ctx->vertex_buffer = new GLfloat[ctx->size * sizeof (GLfloat)];
    ctx->vertex_colors = new GLfloat[ctx->size * sizeof (GLfloat)];

    if (!ctx->vertex_buffer || !ctx->vertex_colors) {
        free(ctx->vertex_buffer);
        free(ctx->vertex_colors);
        free(ctx);
        return NULL;
    }

    return ctx;
}

static bool
content_init(struct content *ctx)
{
    size_t pos = 0;
    for (size_t x = 0; x < ctx->width; ++x) {
        for (size_t y = 0; y < ctx->height; ++y) {
            for (size_t z = 0; z < ctx->depth; ++z) {
                size_t tmp = pos;
                ctx->vertex_buffer[pos++] = (float)x - (float)ctx->width / 2;
                ctx->vertex_buffer[pos++] = (float)y - (float)ctx->height / 2;
                ctx->vertex_buffer[pos++] = (float)z - (float)ctx->depth / 2;
                pos = tmp;
                ctx->vertex_colors[pos++] = (float)x / (float)ctx->width;
                ctx->vertex_colors[pos++] = (float)y / (float)ctx->height;
                ctx->vertex_colors[pos++] = (float)z / (float)ctx->depth;
            }
        }
    }

    glEnable(GL_VERTEX_ARRAY);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glGenBuffers(1, &ctx->vertex_buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, ctx->vertex_buffer_id);
    glBufferData(GL_ARRAY_BUFFER, ctx->size * sizeof(GLfloat), ctx->vertex_buffer, GL_STATIC_DRAW);

    glGenBuffers(1, &ctx->vertex_colors_id);
    glBindBuffer(GL_ARRAY_BUFFER, ctx->vertex_colors_id);
    glBufferData(GL_ARRAY_BUFFER, ctx->size * sizeof(GLfloat), ctx->vertex_colors, GL_STATIC_DRAW);

    ctx->program_id = LoadShaders( "vertex.glsl", "fragment.glsl" );

    return true;
}

static void
display(void) {
    struct content *ctx = global_ctx;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, 1, 0.1, 500.);
    gluLookAt(
        0, 0, 0,
        0, 0, 0,
        0, 1, 0
    );

    glUseProgram(ctx->program_id);

    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, ctx->vertex_buffer_id);
    glDrawArrays(GL_POINTS, 0, ctx->size / 3);
    glDisableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, ctx->vertex_colors_id);
    glDisableVertexAttribArray(1);

    glDisableClientState(GL_VERTEX_ARRAY);

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

    GLenum GLEWinit = glewInit();
    if (GLEW_OK != GLEWinit) {
        fprintf(stderr, "GLEW: %s\n", glewGetErrorString(GLEWinit));
        return 1;
    }

    global_ctx = content_create();
    content_init(global_ctx);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    printf("GL_VERSION = %s\n", glGetString(GL_VERSION));
    printf("GL_RENDERER = %s\n", glGetString(GL_RENDERER));


    glutMainLoop();
    return 0;
}
