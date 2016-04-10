
void drawRoad(float * _road, int track_length)
{
	float d = 1;

	start_sweep += 150;
	start_sweep = start_sweep % track_length;

	int end_sweep = start_sweep + 300;
	end_sweep = end_sweep % track_length;

	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

	GLfloat low_shininess[] = { 15.0 };
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);

	GLfloat mat_emission[] = {0.1, 0.1, 0.2, 0.1};
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);


	/* Draw the surface */
	glBegin(GL_LINE_STRIP);
	int i;
	for (i = 0; i < track_length; i += 6)
	{
		if (i > start_sweep)
		{
			d = (float)(i - start_sweep) / 300;
			d = sinf(3.14 * d);
			GLfloat mat_emission[] = {0.1 + 0.2 * d, 0.1, 0.2, 0.1};
			glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		}
		if (i > end_sweep)
		{
			GLfloat mat_emission[] = {0.1, 0.1, 0.2, 0.1};
			glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		}

		glNormal3f(_road[i], _road[i + 1], _road[i + 2]);
		glVertex3f(_road[i + 3], _road[i + 4], _road[i + 5]);
	}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	for (i = 0; i < track_length; i += 48) {
		glVertex3f(_road[i + 3], _road[i + 4], _road[i + 5] );
		glVertex3f(_road[i + 3] + _road[i], _road[i + 4] + _road[i + 1], _road[i + 5] + _road[i + 2] );
		glVertex3f(_road[i + 3], _road[i + 4], _road[i + 5] );

	}
	glEnd();

	/* Draw coordinate axes */
	glBegin(GL_LINES);
	glVertex3f(-1, 0, 0);
	glVertex3f(10, 0, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0, -1, 0);
	glVertex3f(0, 10, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0, 0, -1);
	glVertex3f(0, 0, 10);
	glEnd();
}
