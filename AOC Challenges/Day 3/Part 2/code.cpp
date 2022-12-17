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
    char alphabet[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    for (int i = 0; i << 27; i++) {
        alphabet[27 + i] = toupper(alphabet[i]);
    }
    cout << alphabet[27] << endl; 
    int sumOfPriority = 0;
    
    int commonCount; 

    ifstream myFile("C:\\Users\\harry\\Desktop\\Computing\\aoc2022\\AOC Challenges\\Day 3\\Part 2\\input.txt");

    int i = 0;
    while (getline(myFile, myText)) {
        rucksackGroup[i] = myText;
        i++;
        if (i == 3) {
            i = 0;
            string rucksackMem1 = rucksackGroup[0];
            string rucksackMem2 = rucksackGroup[1];
            string rucksackMem3 = rucksackGroup[2];
            int priorityNum = 1;
            char common;

            for (char _alphabet : alphabet) {
                if (arraySearchAndFind(rucksackMem1, _alphabet) && arraySearchAndFind(rucksackMem2, _alphabet) && arraySearchAndFind(rucksackMem3, _alphabet)) {
                    char common = _alphabet; 
                    char key = tolower(common);
                    while (priorityNum < 28) {
                        if (key == alphabet[priorityNum]) {
                            break;
                        } 
                        priorityNum += 1;
                    }
                    
                    if (isupper(common)) {
                        priorityNum += 26;
                    }\

                    commonCount++;
                    // cout << common;
                    sumOfPriority += priorityNum;
                }
            // cout << "Not found" << endl;
                
            }
        }
    }
    // cout << commonCount << endl;
    // cout << sumOfPriority;

}