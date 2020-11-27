
// Simple openGL tetris game!
// Created by: HiperLunar
// version: 0.3
// date: 27/20/2020 (MM/DD/YYYY)

#include "piece.h"
#include "map.h"

#include <GL/glut.h>

#define TITLE "Tetris"
#define VERSION "0.1"

#define GAME_WIDTH 10
#define GAME_HEIGHT 22
#define POINT_SIZE 16

int constexpr WINDOW_WIDTH = GAME_WIDTH * POINT_SIZE;
int constexpr WINDOW_HEIGHT = GAME_HEIGHT * POINT_SIZE;

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

static tetris::Map map(GAME_WIDTH, GAME_HEIGHT);

tetris::Piece* active_piece;

int x = 1;
int y = 10;

unsigned int speed = 1;

bool down() {
	bool r = true;
	std::vector<int>& shape = active_piece->shape;
	int len = active_piece->len();
	for (int i = 0; i < shape.size(); ++i) {
		if (shape[i] > 0) {
			int _x = (i % len) + x;
			int _y = (i / len) + y;
			if (!(_y > 0)) {
				r = false;
			}
			if (map.get(_x, _y - 1) > 0) {
				r = false;
			}
		}
	}
	if (r) y -= 1;
}

bool rotate() {}
bool left() {
	bool r = true;
	std::vector<int>& shape = active_piece->shape;
	int len = active_piece->len();
	for (int i = 0; i < shape.size(); ++i) {
		if (shape[i] > 0) {
			int _x = (i % len) + x;
			int _y = (i / len) + y;
			if (!(_x > 0)) {
				r = false;
			}
			if (map.get(_x - 1, _y) > 0) {
				r = false;
			}
		}
	}
	if (r) x -= 1;
}
bool right() {
	bool r = true;
	std::vector<int>& shape = active_piece->shape;
	int len = active_piece->len();
	for (int i = 0; i < shape.size(); ++i) {
		if (shape[i] > 0) {
			int _x = (i % len) + x;
			int _y = (i / len) + y;
			if (!(_x + 1 < map.getWidth())) {
				r = false;
			}
			if (map.get(_x + 1, _y) > 0) {
				r = false;
			}
		}
	}
	if (r) x += 1;
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POINTS);
	for (int i=0; i < GAME_HEIGHT * GAME_WIDTH; ++i) {
		if (map[i] > 0) {
			int& c = map[i];
			glColor3ub(colors[3*c], colors[3*c+1], colors[3*c+2]);
			glVertex2d(i % GAME_WIDTH, i / GAME_WIDTH);
		}
	}

	std::vector<int>& shape = active_piece->shape;
	int len = active_piece->len();
	for (int i=0; i < shape.size(); ++i) {
		if (shape[i] > 0) {
			glColor3ub(colors[6], colors[7], colors[8]);
			glVertex2d((i % len) + x, (i / len) + y);
		}
	}
	glEnd();

	glFlush();
}

void keyboard(unsigned char key, int mouse_x, int mouse_y) {
	switch (key)
	{
	case 'w':
		active_piece->rotate();
		break;

	case 'a':
		left();
		break;
	
	case 'd':
		right();
		break;
	
	case 's':
		down();
		break;
	}

	glutPostRedisplay();
}

void update(int value) {

	down();

	glutPostRedisplay();
	glutTimerFunc(1000/speed, update, 0);
}

void setup() {
    glPointSize(POINT_SIZE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-0.5, GAME_WIDTH-0.5, -0.5, GAME_HEIGHT-0.5);

    glEnableClientState (GL_COLOR_ARRAY);

    glColorPointer(3, GL_UNSIGNED_BYTE, 0, colors);

	glClearColor(0,0,0,0);

	active_piece = &tetris::pieces[0];

	glutTimerFunc(1000/speed, update, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(TITLE);

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	setup();
	glutMainLoop();

    return 0;
}