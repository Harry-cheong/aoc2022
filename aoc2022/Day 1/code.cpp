#include <string> 
#include <iostream>
#include <fstream>

using namespace std; 

int main() {

    string myText; 
    int myInt;
    int data[1000] = {};

    ifstream myReadFile("C:\\Users\\User\\Desktop\\Harry\\aoc2022\\aoc2022\\Day 1\\input.txt");
    int i = 0;
    int sumOfCalories = 0;

    // Computing the total number of calories carried by each elf

    while (getline (myReadFile, myText)) {
        if (myText == "") {
            data[i] = sumOfCalories;
            i++;
            sumOfCalories = 0;
        } else {
            sumOfCalories += stoi(myText);
        }
    }

    // Finding the largest 
    int highestCalories = 0;
    for (int calories : data) {
        if (calories > highestCalories) {
        highestCalories = calories; 
        }
    }
   
    cout << highestCalories; // Answer: 67633
    myReadFile.close();
}
