#include "graphics.h"
#include <math.h>
#define PI 3.14159265359

void drawKoch(int fromX, int fromY, int toX, int toY, int level, double theta) {
	if (level == 0) {
		drawLine(fromX,fromY, toX,toY);
	} else {
		double fstX, sndX, thdX; //the three points of inflection of this segment of the curve
		double fstY, sndY, thdY;

		double magnitude = (fromX - toX) * (fromX - toX) + (fromY - toY) * (fromY - toY);
		magnitude = sqrt(magnitude);

		fstX = (toX - fromX) / 3 + fromX;
		fstY = (toY - fromY) / 3 + fromY;

		sndX = cos(theta - PI / 3) * magnitude / 3 + fstX;
		sndY = sin(theta - PI / 3) * magnitude / 3 + fstY;

		thdX = (fromX - toX) / 3 + toX;
		thdY = (fromY - toY) / 3 + toY;


		drawKoch(fromX,fromY, fstX,fstY, level - 1, theta);
		drawKoch(fstX,fstY, sndX,sndY, level - 1, theta - PI / 3);
		drawKoch(sndX,sndY, thdX,thdY, level - 1, theta + PI / 3);
		drawKoch(thdX,thdY, toX,toY, level - 1, theta);
	}
}

int main() {
	int level = 5;

	drawKoch(60,80, 313,80, level,0);

	return 0;
}
