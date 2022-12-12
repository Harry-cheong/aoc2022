#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {

    string myText; 
    string data[2500] = {};

    ifstream myReadFile ("C:\\Users\\harry\\Desktop\\Computing\\aoc2022\\AOC Challenges\\Day 2\\input.txt");

    int i = 0; 
    while (getline (myReadFile, myText)) {
        if (myText == "") {
            continue;
        }
        data[i] = myText;
        i++;
    }

    int totalScore = 0;
    for (string match : data) {

        // Representation
        // A: Rock, B: Paper, C: Scissors
        // X: Rock, Y: Paper, Z: Scissors
            string shape1 = match.substr(0, 1);
            string shape2 = match.substr(2, 1); 
            
            // Score for the shape you selected 
            if (shape2 == "X") {
                totalScore += 1;
            } else if (shape2 == "Y") {
                totalScore += 2; 
            } else if (shape2 == "Z") {
                totalScore += 3;
            }

            // Score for match result
            
            // Draw
            if ((shape1 == "A" && shape2 == "X") || (shape1 == "B" && shape2 == "Y") || (shape1 == "C" && shape2 == "Z")) {
                totalScore += 3;
            } 
            
            // Win 

            // Rock d. Scissors
            else if (shape2 == "X" && shape1 == "C") {
                totalScore += 6;
            }
            
            // Paper d. Rock 
            else if (shape2 == "Y" && shape1 == "A") {
                totalScore += 6;
            }

            // Scissors d. Paper 
            else if (shape2 == "Z" && shape1 == "B") {
                totalScore += 6;
            }
    }
        
    cout << totalScore;
}