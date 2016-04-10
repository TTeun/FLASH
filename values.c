#define PI 3.14

float calc_length(float v_0, float v_1, float v_2) {
	float arg = v_0 * v_0 + v_1 * v_1 + v_2 * v_2;
	if (arg < 0){
		printf("Negative root!\n");
	}
	return sqrt(arg);
}

GLfloat light_position0[] = {1.0, 0.4, 0.6, 2.0};

int track_length;
float velocity[3];
float position[3];
float * road;
int om_en_om		= 1;
int start_sweep 	= 0;
float speed 		= 0.0;
float tilt 			= 0.0;
int time 			= 0;