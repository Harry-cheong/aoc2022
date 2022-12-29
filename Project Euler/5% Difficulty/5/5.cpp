#include <iostream>
#include <vector>

using namespace std;

// Recursive Function to return gcd of a and b
long long int gcd(long long int a, long long int b) {
    if (b == 0) {
        return a;
    };
    return gcd(b, a % b);
}

// Function to return LCM of two numbers
long long int lcm(long long int a, long long int b) {
    return (a / gcd(a, b)) * b;
}


int main() {
    int num = 1;

    for (int i = 1; i < 21; i++) {
        num = lcm(num, i);
    };

    cout << num; // Answer: 232792560
}