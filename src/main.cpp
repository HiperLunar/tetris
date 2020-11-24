
// Simple openGL tetris game!
// Created by: HiperLunar
// version: 0.1
// date: 11/20/2020 (MM/DD/YYYY)

#include <vector>

#include <GL/glut.h>

#define TITLE "Tetris"
#define VERSION "0.1"

#define GAME_WIDTH 10
#define GAME_HEIGHT 22
#define POINT_SIZE 16

int constexpr WINDOW_WIDTH = GAME_WIDTH * POINT_SIZE;
int constexpr WINDOW_HEIGHT = GAME_HEIGHT * POINT_SIZE;

// Colors:
//



static const GLubyte colors[] = {
	0x00, 0x00, 0x00,
	0x00, 0xFF, 0xFF,
	0x00, 0x00, 0xFF,
	0xFF, 0xAA, 0x00,
	0xFF, 0xFF, 0x00,
	0x00, 0xFF, 0x00,
	0x99, 0x00, 0xFF,
	0xFF, 0x00, 0x00
};

int map[GAME_WIDTH * GAME_HEIGHT];

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(0xFF, 0x00, 0x00);

	glBegin(GL_POINTS);
	for (int i=0; i < GAME_HEIGHT * GAME_WIDTH; ++i) {
		if (map[i] > 0) {
			int& c = map[i];
			glColor3ub(colors[3*c], colors[3*c+1], colors[3*c+2]);
			glVertex2d(i % GAME_WIDTH, i / GAME_WIDTH);
		}
	}
	glEnd();

	glFlush();
}

void setup() {
    glPointSize(POINT_SIZE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-0.5, GAME_WIDTH-0.5, -0.5, GAME_HEIGHT-0.5);

    glEnableClientState (GL_COLOR_ARRAY);

    glColorPointer(3, GL_UNSIGNED_BYTE, 0, colors);

	glClearColor(0,0,0,0);

	map[1] = 2;
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(TITLE);

	glutDisplayFunc(display);

	setup();
	glutMainLoop();

    return 0;
}