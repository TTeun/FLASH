float * init_road1(float * _road) {
	track_length = 120000;
	_road = (float *) malloc (track_length * sizeof(float));
	int i;
	float t = 0.0;
	for (i = 0; i < track_length; i += 12) {
		_road[i]   	 = 0.0;
		_road[i + 1] = -.2 * cosf(t / 5);
		_road[i + 2] = 1.0;

		_road[i + 3] = 1.0;
		_road[i + 4] = t;
		_road[i + 5] = sinf(t / 5);


		_road[i  + 6] = 0.0;
		_road[i + 7] = -.2 * cosf(t / 5);
		_road[i + 8] = 1.0;

		_road[i + 9] = -1.0;
		_road[i + 10] = t;
		_road[i + 11] = sinf(t / 5);
		t += 0.1;
	}

	
	
	return _road;
}
