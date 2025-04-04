#include <complex>
#include <iostream>

#include <vector>

using namespace std;


void mandelbrot(double real, double imag, int N) {
        double zReal = 0.0;
        double zImag = 0.0;


        for (int i = 0; i < N; i++) {
                const double r2 = zReal * zReal;
                const double i2 = zImag * zImag;

                // Escape condition: if |z|^2 > 4, then the point escapes to infinity
                if (r2 + i2 > 4.0) {
                        cout << real << " + " << imag << "i" << " is not in mandelbrot set" << endl;
                        return;
                }

                // Update z = z^2 + c
                zImag = 2.0 * zReal * zImag + imag;
                zReal = r2 - i2 + real;
        }

        // If it doesn't escape, it's in the Mandelbrot set
        cout << real << " + " << imag << "i" << " is in mandelbrot set" << endl;
}

int main(int argc, char* argv[]){

        if (argc < 3) {
                cout << "Usage: " << argv[0] << " <real> <imaginary> Optional: <N>" << endl;
                return 1;
        }

        const double real = stod(argv[1]);
        const double imag = stod(argv[2]);
        int N = 10000;
        if (argc > 3) {
            N = stoi(argv[3]);
        }
        mandelbrot(real, imag,N);

        return 0;

}