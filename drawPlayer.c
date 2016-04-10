
void drawPlayer() {
	glEnable(GL_DEPTH_TEST);

	float v0 = velocity[0];
	float v1 = velocity[1];
	float v2 = velocity[2];

	float length = sqrt(v0 * v0 + v1 * v1 + v2 * v2);
	v0 /= length;
	v1 /= length;
	v2 /= length;

	float p0 = position[0] + 0 * road[time];
	float p1 = position[1] + 0 * road[time + 1];
	float p2 = position[2] + 0 * road[time + 2];

	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat low_shininess[] = { 15.0 };
	GLfloat mat_emission[] = {0.0, 0.0, 1.0, 0.1};

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);


	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f( p0 - 0.1 , p1, p2);
	glVertex3f( p0 + 0.1 , p1, p2);
	glVertex3f( p0, p1 + v1, v2 + p2);
	glVertex3f( p0, p1 + 0.1 * road[time + 1], p2 + 0.1 * road[time + 2]);
	glVertex3f( p0 - 0.1 , p1, p2);
	glVertex3f( p0, p1 + v1, v2 + p2);
	glEnd();

	glBegin(GL_LINES);
	glVertex3fv(position);
	glVertex3f(p0 + 0.8 * road[time] - v0,
	           p1 + 0.8 * road[time + 1] - v1,
	           p2 + 0.8 * road[time + 2] - v2);
	glEnd();

	float scaler = (speed < 0.02) ? speed : 0.02;
	scaler *= 25;
	scaler += 1;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(p0 + 1 * scaler * road[time] - 1.5 * scaler * v0, p1 + 1 * scaler * road[time + 1] - 1.5 * scaler * v1, p2 + 1 * scaler * road[time + 2] - 1.5 * scaler * v2,
	          p0 + 2 * scaler * v0, p1 + 2 * scaler * v1, p2 + 2 * scaler * v2,
	          road[time], road[time + 1], road[time + 2]);
	glPushMatrix();
	glDisable(GL_DEPTH_TEST);
}