#include <iostream>
#include "mandelbrot.h"

using namespace std;

int main() {
    complex<double> c;
    double imag;

    while (true) {
        cout << "Enter real and imaginary numbers: " << endl;
        cin >> c >> c;
        if (c == 0 && imag == 0) {
            break;
        }

        is_in_mandelbrot(std::complex<double> c, int N)

    }
}