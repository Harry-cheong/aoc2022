#include <iostream>
#include <deque>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    deque<int> digits;
    long long int largestProduct = 0;
    string myText;
    
    ifstream myFile("C:\\Users\\harry\\Desktop\\Computing\\aoc2022\\Project Euler\\8\\input.txt");

    while (getline(myFile, myText)) {
        for (char digitchar : myText) {
            digits.push_back(int(digitchar - '0'));
        }
    }

    cout << digits.size() << endl;

    while (digits.size() != 12) {
        long long int num = 1;
        for (int i = 0; i < 13; i++){
            num *= digits.at(i);
        }

        digits.pop_front();

        if (num > largestProduct) {
            largestProduct = num;
        }
    }

    cout << largestProduct; // Answer: 23514624000
}