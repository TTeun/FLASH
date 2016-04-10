#include <math.h>
#include <stdio.h>
#include <GL/glut.h>
#include "values.c"
#include "initRoad.c"
#include "drawRoad.c"
#include "drawPlayer.c"
#include "updatePosition.c"

void keyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP 	: speed += 0.01; break;
	case GLUT_KEY_DOWN 	: speed -= ( (speed < 0) ? 0 : 0.01); break;
	case GLUT_KEY_RIGHT	: velocity[0] += 0.04; break;
	case GLUT_KEY_LEFT	: velocity[0] -= 0.04; break;
	}
}

void init_player(void) {
	position[0] = 0.5 * road[3] + 0.5 * road[9];
	position[1] = 0.5 * road[4] + 0.5 * road[10];
	position[2] = 0.5 * road[4] + 0.5 * road[11];

	velocity[0] = road[15] - road[3];
	velocity[1] = road[16] - road[4];
	velocity[2] = road[17] - road[5];

	speed = 0;
	tilt  = 0;
	time = 0;
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	update_position();
	drawPlayer();
	drawRoad(road, track_length);
	glutSwapBuffers();
}

void init(void)
{

	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

	glEnable (GL_BLEND);
	glBlendFunc (GL_ONE_MINUS_DST_COLOR, GL_SRC_ALPHA);

	glMatrixMode(GL_PROJECTION);
	gluPerspective( 60.0, 1.0, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, -6, 5,
	          0, 2, 0,
	          0, 1, 0 );
}


void play_game() {
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Track");
	glutDisplayFunc(display);
	glutSpecialFunc(keyboard);

	road = init_road1(road);
	init_player();
	init();

	glutIdleFunc(play_game);

	glutMainLoop();
	return 0;
}