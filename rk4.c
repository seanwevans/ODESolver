#include <stdio.h>
#include <stdlib.h>

float f(float t, float y);
float k1(float t, float y);
float k2(float t, float y, float h);
float k3(float t, float y, float h);
float k4(float t, float y, float h);

/*
	Let an initial value problem be specified as follows:
	y' = f(t,y),	y(t_0) = y_0
*/

int main(int argc, char *argv[]){

	float t0, y0, h, tmax;

	if (argc == 5){
		t0 = atof(argv[1]);
		y0 = atof(argv[2]);
		h = atof(argv[3]);
		tmax = atof(argv[4]);
	}
	else{
		t0 = 0;
		y0 = 1;
		h = 0.01;
		tmax = 1;
	}

	float tn = t0;
	float yn = y0;

	for(; tn < tmax; tn += h){
		fprintf(stdout, "%f %f\n", tn, yn);
		yn += (h/6) * (k1(tn,yn) + 2*k2(tn,yn,h) + 2*k3(tn,yn,h) + k4(tn,yn,h));
	}		

	return 0;
}

/* y' = */
float f(float t, float y){
	return t+y;
}

float k1(float t, float y){
	return f(t,y);
}

float k2(float t, float y, float h){
	return f(t+h/2, y+(h*k1(t,y))/2);
}

float k3(float t, float y, float h){
	return f(t+h/2, y+(h*k2(t,y,h))/2);
}

float k4(float t, float y, float h){
	return f(t+h, y+h*k3(t,y,h));
}
