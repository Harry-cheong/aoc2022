#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

int main() {
    string myText;
    int processedCharacter = 0;

    ifstream myFile("C:\\Users\\User\\Desktop\\Harry\\aoc2022\\aoc2022\\Day 6\\Part 1\\input.txt");

    while (getline(myFile, myText)) {
        deque<char> history;

        for (char character:myText) {
            // cout << character;
            if (history.size() == 14) {
                    history.pop_front();
                    history.push_back(character);
                } else {
                    history.push_back(character);
                }

            if (processedCharacter > 14) {
                // Finding duplicates inside array
                for (int i1 = 0; i1 < 14; i1++) {
                    for (int i2 = i1 + 1; i2 < 14; i2++) {
                        if (history.at(i1) == history.at(i2)) {
                            goto nextChar;
                        } 
                    }
                }
                
                break;
            }
            
            nextChar: 
            processedCharacter++;
            }
        }
        cout << processedCharacter + 1; // Answer: 2263

    }