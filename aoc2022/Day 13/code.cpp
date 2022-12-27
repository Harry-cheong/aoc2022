#include <iostream>
#include <vector> 
#include <fstream>
#include <string>

using namespace std;

vector<string> separateintoelements(string list) {
    string list_copy = list;
    int indexOfOpenBracket, indexOfComma, indexOfClosedBracket;
    vector<int> openIndexes, closedIndexes;
    string element;
    vector<string> array;

    // Logic
    // e.g. [9, 8, [9, 7]]
    // if '[' comes after ',' -> slice from start to the comma
    // if ',' comes after '[' -> find the closest bracket that corresponds the first open bracket
        // How to find corresponding bracket?
        // Find the index of '[' and ']' 
        // check the contents included in the two brackets
        // if there are no brackets, or matching pairs of brackets, extract element, if not continue this process until the element is found 
    cout << list << endl;

    while (true) {
        indexOfOpenBracket = list_copy.find('[');
        indexOfComma = list_copy.find(',');
        if (indexOfOpenBracket == string::npos && indexOfComma == string::npos) {
            break;
        }

        // cout << "indexOfBracket: " << indexOfOpenBracket << "  " << "indexOfComma: " << indexOfComma << endl << endl;


        if (indexOfOpenBracket > indexOfComma) {
            element = list_copy.substr(0, indexOfComma);
            array.push_back(element);
            list_copy.erase(0, indexOfComma + 1);

        } else if (indexOfOpenBracket < indexOfComma){  
            int prevClosedBracket = 0; 

            while (true) {
                indexOfClosedBracket = list_copy.find(']', prevClosedBracket);

                string check = list_copy.substr(indexOfOpenBracket + 1, indexOfClosedBracket - 1);

                cout << check << endl; 

                int checkForOpenBracket = 0, checkForClosedBracket = 0;
                int searchForOpenBracket = 0, searchForClosedBracket = 0;
                int noOfOpenBracket = 0, noOfClosedBracket = 0;

                while (checkForOpenBracket != string::npos) {
                    checkForClosedBracket = check.find(']', searchForClosedBracket);
                    checkForOpenBracket = check.find('[', searchForOpenBracket);

                    if (checkForOpenBracket != string::npos) {
                        searchForOpenBracket = checkForOpenBracket + 1;
                        noOfOpenBracket ++;
                    }
                    
                    if (checkForClosedBracket != string::npos) {
                        searchForClosedBracket = checkForClosedBracket + 1;
                        noOfClosedBracket++;
                    }

                }

                // cout << "No. of OpenBracket: " << noOfOpenBracket << " No. of ClosedBracket: " << noOfClosedBracket << endl;

                if (noOfOpenBracket == noOfClosedBracket) {
                    break;
                }

                prevClosedBracket = indexOfClosedBracket + 1; 
            }

            array.push_back("[]");
            array.push_back(element = list_copy.substr(1, indexOfClosedBracket));
            list_copy.erase(0, indexOfClosedBracket);
        }
    }

    return array;
}

bool isList(string list) {
    if (list[0] == '[' && list[list.size() - 1] == ']') {
        return true;
    } else {
        return false;
    }
}

void compare(string left, string right) {

    vector<string> elementsLeft, elementsRight, newArray;
    elementsLeft = separateintoelements(left);
    elementsRight = separateintoelements(right);

    while (true) {
        if (elementsLeft.at(0) == "[]") {
            elementsLeft.erase(elementsLeft.begin() + 0);
        }

        if (elementsLeft.size() == 1) {
            elementsLeft = separateintoelements(elementsLeft.at(0));
        } else {
            break;
        }
    }

    while (true) {
            if (elementsRight.at(0) == "[]") {
            elementsRight.erase(elementsRight.begin() + 0);
        }

        if (elementsRight.size() == 1) {
            elementsRight = separateintoelements(elementsRight.at(0));
        } else {
            break;
        }
    }
}

int main() {
    string myText;

    ifstream myFile("C:\\Users\\harry\\Desktop\\Computing\\aoc2022\\aoc2022\\Day 13\\input.txt");
    
    vector<string> pairs;

    while (getline(myFile, myText)) {
        if (myText != "") {
            pairs.push_back(myText);
        }
    }

    vector<string> left, right;

    // int noOfPairs = 0;
    // string left, right;
    // for (int i = 0; i < pairs.size()/2; i++) {
    //     if (i == 0) {
    //         left = pairs.at(i);
    //         right = pairs.at(i + 1);
    //     } else {
    //         left = pairs.at(i + 1);
    //         right = pairs.at(i + 2);
    //     }

    //     while (left != "" || right != "") {

    //     }

    // }

    compare(pairs.at(0), pairs.at(1));

}