#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int arraySearchAndFind(string word, char alphabet) {
    for (char character : word) {
        if (character == alphabet) {
            return true;
        }
    }
    return false;
}

int main() {
    string myText; 
    string rucksackGroup[3] = {}; 

    // A list of alphabets 
    char alphabet[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    
    int sumOfPriority = 0;
    int commonCount = 0; 

    ifstream myFile("C:\\Users\\User\\Desktop\\Harry\\aoc2022\\aoc2022\\Day 3\\Part 2\\input.txt");
   
    int i = 0;
    while (getline(myFile, myText)) {
        rucksackGroup[i] = myText;
        i++;
        if (i == 3) {
            i = 0;
            string rucksackMem1 = rucksackGroup[0];
            string rucksackMem2 = rucksackGroup[1];
            string rucksackMem3 = rucksackGroup[2];
            int priorityNum = 0;
            char common;

            // Checking which alphabet, lower/upper, is found inside all 3 of the rucksacks
            for (char _alphabet : alphabet) {
                if (arraySearchAndFind(rucksackMem1, _alphabet) && arraySearchAndFind(rucksackMem2, _alphabet) && arraySearchAndFind(rucksackMem3, _alphabet)) {
                    char common = _alphabet; 
                    while (true) {
                        if (common == alphabet[priorityNum]) {
                            break;
                        } 
                        priorityNum += 1;
                    }
                    priorityNum += 1;

                    cout << priorityNum << common << endl, 
                    commonCount++;
                    // cout << common;
                    sumOfPriority += priorityNum;
                }
            // cout << "Not found" << endl;
                
            }
        }
    }
    cout << commonCount << endl; // Answer: 100
    cout << sumOfPriority; // Answer: 2620

}