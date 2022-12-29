#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int sumofsquares = (100 * 101 * 201) / 6;
    int squareofsum = pow((100 * 101) / 2, 2);

    int difference = squareofsum - sumofsquares;

    cout << difference << endl; // Answer: 25164150
}