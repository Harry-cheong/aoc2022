#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string myText; 
    int sumOfPriority = 0;
    char priorityNumber[27] = {0, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    ifstream myFile("C:\\Users\\User\\Desktop\\Harry\\aoc2022\\aoc2022\\Day 3\\Part 1\\input.txt");

    int lengthOfData = 0;
    string compartmentOne, compartmentTwo;
    while (getline(myFile, myText)) {

        // Splitting the rucksuck into two compartments
        lengthOfData = myText.length();
        compartmentOne = myText.substr(0, lengthOfData/2);
        compartmentTwo = myText.substr(lengthOfData/2);
        int priority = 0;

        // Finding the common element
        for (int i1 = 0; i1 < compartmentOne.length() + 1; i1++) {
            for (int i2 = 0; i2 < compartmentTwo.length() + 1; i2++) {
                if (compartmentTwo[i2] == compartmentOne[i1]) 
                
                // Finding the priority number
                {
                    char common = compartmentTwo[i2];
                    char key = tolower(common);
                    while (priority < 28) {
                        if (key == priorityNumber[priority]) {
                            break;
                        } 
                        priority += 1;
                    }
                    
                    if (isupper(common)) {
                        priority += 26;
                    }
                    goto next;
                }
            }
        }
        next: {
            sumOfPriority += priority;
        }
    }
    cout << sumOfPriority; // Answer: 8123
}
