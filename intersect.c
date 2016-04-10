#include <stdio.h>
#include <math.h>

float calc_length(float v_0, float v_1, float v_2) {
	return sqrt(v_0 * v_0 + v_1 * v_1 + v_2 * v_2);

}

float distance(void) {
	float v0[3] = {2, 2, 0};
	float v1[3] = {3, 2, 0};
	float v2[3] = {2, 3, 0};
	float v3[3] = {3, 3, 0};

	float vel[3] = {0.25, 1.0, 0.0};
	float d0 = .5;
	float a[3] = {(1 - d0) * (v3[0] - v1[0]) + d0 * (v2[0] - v0[0]),
	              (1 - d0) * (v3[1] - v1[1]) + d0 * (v2[1] - v0[1]),
	              (1 - d0) * (v3[2] - v1[2]) + d0 * (v2[2] - v0[2])
	             };

	float b[3] = {v3[0] - v2[0], v3[1] - v2[1], v3[2] - v2[2]};
	float theta = acos( (vel[0] * a[0] + vel[1] * a[1] + vel[2] * a[2] ) /
	                    (calc_length(vel[0], vel[1], vel[2]) * calc_length(a[0], a[1], a[2])));

	if (theta == 0){
		return d0;
	}


	float gamma = acos( (vel[0] * b[0] + vel[1] * b[1] + vel[2] * b[2] ) /
	                    (calc_length(vel[0], vel[1], vel[2]) * calc_length(b[0], b[1], b[2])));

	float distance = .9;

	return (sinf(theta) * calc_length(a[0], a[1], a[2]) / sinf(gamma) );
}





int main() {
	printf("%f\n", distance());
	return 0;
}



