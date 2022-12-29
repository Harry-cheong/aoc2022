#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    string myText;

    ifstream myFile("C:\\Users\\harry\\Desktop\\Computing\\aoc2022\\aoc2022\\Day 10\\Part 1\\input.txt");

    int cycleNo = 0;
    int signalStrength = 1;
    vector<int> signalStrengthAfterEachCycle;
    while (getline(myFile, myText)) {
        if (myText == "noop") {
            cycleNo++;
            signalStrengthAfterEachCycle.push_back(signalStrength);
        }
        else {
            int signalIncrease = stoi(myText.substr(5, 3));
            cycleNo++;
            // cout << signalIncrease << endl;
            signalStrengthAfterEachCycle.push_back(signalStrength);
            cycleNo++;
            signalStrengthAfterEachCycle.push_back(signalStrength);
            signalStrength += signalIncrease; 
        }
    };

    int sumOfSixSignalStrength = signalStrengthAfterEachCycle.at(19) * 20 + signalStrengthAfterEachCycle.at(59) * 60 + signalStrengthAfterEachCycle.at(99) * 100 + signalStrengthAfterEachCycle.at(139) * 140 + signalStrengthAfterEachCycle.at(179) * 180 + signalStrengthAfterEachCycle.at(219) * 220;

    cout << sumOfSixSignalStrength; // Answer: 17020

}