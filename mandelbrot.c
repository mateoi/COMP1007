#include <complex.h>
#include "graphics.h"
#include <stdbool.h>

#define LEVEL 100

bool isMandel(double complex, double complex, int);

int main() {

	double complex zero = 0.000000001 + 0.0 * I;
	// can´t use mathematical zero because
	// the math library has some weird glitches.
	// this is why there are some dead pixels in the final image
	int x,y;

	for (x = 0; x < 499; x++) {
		for (y = 0; y < 299; y++) {
			double re = (x / 500.0) * 3 - 2;
			double im = (y / 300.0) * 2 - 1;
			double complex point = re + im * I;
			// point is the complex number at x,y if the drawing surface were a
			// complex plane from Re[-2, 1] + Im[-1,1].
			// technically the y axis is inverted but the mandelbrot set is symmetric.

			if (isMandel(point, zero, LEVEL)) {
				drawLine(x,y,x,y);
			}
		}
	}

	return 0;

}

/*
 * The test for whether a point c is in the set is simple:
 * iff the polynomial z_(n+1) = (z_n)^2 + c diverges as n -> infinity,
 * c belongs in the set.
 *
 * We can't test this analytically, so instead we recursively apply
 * the polynomial until the magnitude exceeds 2 and we fail, or we
 * get past a predetermined threshold and hence assume inclusion.
 *
 * ...which is a  long way of saying "wikipedia: RTFA"
 */
bool isMandel(double complex init, double complex point, int level) {
	if (cabs(point) > 2) { // if the point is past 2 the test is guaranteed to fail.
		return false;
	} else {
		if (level <= 0) {
			return true;
		} else {
			double complex newPoint = point * point + init;
			return isMandel(init, newPoint, level - 1);
		}
	}
}
