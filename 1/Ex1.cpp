#include <iostream>
using namespace std;


void access_wrong_memory() {
    cout << "Accessing invalid memory..." << endl;
    int* p = nullptr;
    cout << &p << endl;
    *p = 1;


}

void div_zero() {
    cout << "Dividing by zero..." << endl;
    int a = 5;
    int b = 0;
    cout << a / b << endl;
}

void overflow(int depth = 0) {
    cout << "Stack depth: " << depth << endl;
    overflow(depth + 1);
}


int main() {
     cout << "OverFlow error type 1, divZero type 2, access wrong memory type 3" << endl;
     int user;
     cin >> user;
     switch (user) {
         case 1:
             overflow();
         break;
         case 2:
             div_zero();
         break;
         case 3:
             access_wrong_memory();
         break;
     }





    return 0;
}
