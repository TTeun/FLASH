
void update_position(void) {
	float dist_left = speed;
	// printf("<v,n> = %f\n", velocity[0] * road[time + 12] + velocity[1] * road[time + 13] + velocity[2] * road[time + 14]);
	while (dist_left > 0) {
		float v1[3] = {road[time + 9], road[time + 10], road[time + 11]};
		float v2[3] = {road[time + 15], road[time + 16], road[time + 17]};

		float a[3] = {v2[0] - position[0], v2[1] - position[1], v2[2] - position[2]};
		float b[3] = {v2[0] - v1[0], v2[1] - v1[1], v2[2] - v1[2]};

		float size_a = calc_length(a[0], a[1], a[2]);
		float size_b = calc_length(b[0], b[1], b[2]);
		float size_vel = calc_length(velocity[0], velocity[1], velocity[2]);

		float alpha = acos( (velocity[0] * b[0] + velocity[1] * b[1] + velocity[2] * b[2] ) /
		                    (size_vel * size_b) );

		float gamma = acos( (a[0] * b[0] + a[1] * b[1] + a[2] * b[2] ) /
		                    (size_a * size_b) );

		// printf("alpha : %f\t gamma : %f, time : %d\n", alpha, gamma, time);

		float d0 = 0;
		if (gamma != 0) {
			d0 = (sinf(gamma) * size_a / sinf(alpha) );

			if (d0 > dist_left) {
				dist_left /= size_vel;
				position[0] += dist_left * velocity[0];
				position[1] += dist_left * velocity[1];
				position[2] += dist_left * velocity[2];
				dist_left = 0;
			} else {
				dist_left -= d0;
				d0 /= size_vel;
				position[0] += d0 * velocity[0];
				position[1] += d0 * velocity[1];
				position[2] += d0 * velocity[2];
				float n[3] = {road[time + 18], road[time + 19], road[time + 20]};
				float n_correct = (velocity[0] * n[0] + velocity[1] * n[1] + velocity[2] * n[2] )
				                  / ( n[0] * n[0] + n[1] * n[1] + n[2] * n[2] );
				velocity[0] -= n_correct * n[0];
				velocity[1] -= n_correct * n[1];
				velocity[2] -= n_correct * n[2];
				time += 6;
			}
		} else {
			time += 6;
		}
		// printf("velocity : %f\t%f\t%f\n", velocity[0], velocity[1], velocity[2]);
		// printf("position : %f\t%f\t%f\n\n", position[0], position[1], position[2]);
	}

	// glBegin(GL_TRIANGLES);
	// glNormal3f(road[time], road[time + 1], road[time + 2]);
	// glVertex3f(road[time + 3], road[time + 4], road[time + 4]);
	// glVertex3f(road[time + 9], road[time + 10], road[time + 11]);
	// glVertex3f(road[time + 15], road[time + 16], road[time + 17]);
	// glEnd();

	// float center[3] = { (road[time + 3] + road[time + 9] + road[time + 15]) / 3 ,
	//                     (road[time + 4] + road[time + 10] + road[time + 16]) / 3,
	//                     (road[time + 5] + road[time + 11] + road[time + 17]) / 3
	//                   };

	// glBegin(GL_LINES);
	// glVertex3f(center[0], center[1], center[2]);
	// glVertex3f(center[0] + road[time + 12], center[1] + road[time + 13], center[2] + road[time + 14]);
	// glEnd();


	// printf("time is %d\n", time);
}
