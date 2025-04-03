#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int subArrayN(vector<int> array) {
    int maxSum = array[0];

    for (int i = 1; i < array.size(); i++) {
        array[i] = max(array[i],array[i]+array[i-1]);
        maxSum = max(maxSum,array[i]);
    }
    return maxSum;

}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <randomNumber> <array...>" << endl;
        return 1;
    }

    int randomNumber = atoi(argv[1]);

    vector<int> array;

    for (int i = 2; i < argc; ++i) {
        array.push_back(atoi(argv[i]));
    }


    cout << subArrayN(array) << endl;






    return 0;
}