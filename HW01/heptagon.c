#include <stdio.h>
#include "graphics.h"
#include <math.h>
#define ANGLE 0.897597901 // the external angle of a heptagon, in radians
#define LENGTH 60 //the length of a side


// given an current angle and a point to begin, it will calculate
// the x coordinates of the next endpoint of a line.
int nextX(double angle, int length, int thisX) {
	double x = cos(angle);
	x *= length;
	x += thisX;
	return (int) x;
}

// given an current angle and a point to begin, it will calculate
// the y coordinates of the next endpoint of a line.
int nextY(double angle, int length, int thisY) {
	double y = sin(angle);
	y *= length;
	y += thisY;
	return (int) y;
}


int main() {

	int x = 100;
	int y = 100;
	double theta = 0;

	int i;

	for (i = 0; i < 6; i++) {
		int newX = nextX(theta, LENGTH, x);
		int newY = nextY(theta, LENGTH, y);
		theta += ANGLE;

		drawLine(x,y, newX, newY);

		x = newX;
		y = newY;
	}

	drawLine(x,y, 100,100);

	return 0;

}
