#include "mandelbrot.h"

using namespace std;

bool is_in_mandelbrot(std::complex<double> c, int N) {
    int limits = 10000;
    double zReal = 0.0;
    double zImag = 0.0;


    for (int i = 0; i < limits; i++) {
        const double r2 = zReal * zReal;
        const double i2 = zImag * zImag;

        // Escape condition: if |z|^2 > 4, then the point escapes to infinity
        if (r2 + i2 > 4.0) {
            return false;
        }

        // Update z = z^2 + c
        zImag = 2.0 * zReal * zImag + imag;
        zReal = r2 - i2 + real;
    }


    return true;
}

