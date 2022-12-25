#include <string> 
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {

    string myText; 
    int myInt;
    vector<int> elves;

    ifstream myReadFile("C:\\Users\\harry\\Desktop\\Computing\\aoc2022\\aoc2022\\Day 1\\Part 2\\input.txt");
    int i = 0;
    int sumOfCalories = 0;

    // Computing the total number of calories carried by each elf

    while (getline (myReadFile, myText)) {
        if (myText == "") {
            elves.push_back(sumOfCalories);
            sumOfCalories = 0;
        } else {
            sumOfCalories += stoi(myText);
        }
    }

    // Finding the top 3
    sort(elves.begin(), elves.end(), greater<int>());
   
    cout << elves.at(0) + elves.at(1) + elves.at(2); // Answer: 199628
    myReadFile.close();
}
