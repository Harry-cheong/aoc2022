#include <iostream>
#include <fstream>
#include <deque>
#include <set> 
#include <vector>

using namespace std;

// Iteration Logic 
    // Possible cases
    // Case 1: any tree shorter than house height -> seen
    // Case 2: tree > house height -> block all trees behind 
    // Case 3: cur == visibleheight, then wait for next tree that is taller

int iterateFront(int index, deque<int> array) {
    int visibleHeight = array.at(index);
    int curTree = 0;
    int curVisibleTree = 0;
    int noOfVisibleTrees = 0;
    bool houseHeightReached = false;

    if (index != 0) {
        for (int im = index - 1; im > -1; im--) {
            curTree = array.at(im);
            
            if (!houseHeightReached && visibleHeight > curTree) {
                noOfVisibleTrees++;
            }
            else if (curTree == visibleHeight) {
                houseHeightReached = true;
                noOfVisibleTrees++;

            } else if (curTree > visibleHeight) {
                noOfVisibleTrees++;
                break;
            }
        }
    }
    return noOfVisibleTrees;
    
}

int iterateBack(int index, deque<int> array) {
    int visibleHeight = array.at(index);
    int curTree = 0;
    int curVisibleTree = 0;
    int noOfVisibleTrees = 0;
    bool houseHeightReached = false;

    // Condition 1 is that all trees until a tree of height 9 is visible
    bool condition = false;

    if (index != array.size()) {
        for (int im = index + 1; im < array.size(); im++) {
            curTree = array.at(im);

            if (!houseHeightReached && visibleHeight > curTree) {
                noOfVisibleTrees++;
            }
            else if (curTree == visibleHeight) {
                houseHeightReached = true;
                noOfVisibleTrees++;

            } else if (curTree > visibleHeight) {
                noOfVisibleTrees++;
                break;
            }
        }
    }
    
    return noOfVisibleTrees;
}

int deriveScenicNo(int rowNo, int colNo, deque<int> rowArray, deque<int> colArray) {
    int noOfTreeLeft = 0;
    int noOfTreeRight = 0;
    int noOfTreeTop = 0;
    int noOfTreeBottom = 0;
    int scenicNo;

    // Finding no. of trees on the left of house
    noOfTreeLeft = iterateFront(colNo, rowArray);

    // Finding no. of trees on the right of house
    noOfTreeRight = iterateBack(colNo, rowArray);

    // // Finding no.of trees on the top of house
    noOfTreeTop = iterateFront(rowNo, colArray);

    // // Finding no.of trees on the bottom of house
    noOfTreeBottom = iterateBack(rowNo, colArray);

    scenicNo = noOfTreeBottom * noOfTreeLeft * noOfTreeRight * noOfTreeTop;
    return scenicNo;
}

int main() {
    string myText;

    ifstream myFile("C:\\Users\\User\\Desktop\\Harry\\aoc2022\\aoc2022\\Day 8\\Part 2\\input.txt");

    vector<deque<int>> rowAll;
    vector<deque<int>> colAll;
    deque<int> rowCurrent;

    while (getline(myFile, myText)) {
        rowCurrent.clear();
        for (char tree : myText) {
            // cout << int(tree - '0');
            rowCurrent.push_back(int(tree - '0'));
        }
        // cout << " next" << endl;
        rowAll.push_back(rowCurrent);
    }

    // cout << "info acquired";
    int noOfRow = 99;
    int noOfCol = rowAll.size();
    deque<int> colCurrent;

    // Creating arrays of columns of trees 
    for (int i1 = 0; i1 < noOfCol; i1++) {
        colCurrent.clear();

        // Taking tree from different rows at a specific index to create array of column
        for (int i2 = 0; i2 < noOfRow; i2++) {
            colCurrent.push_back(rowAll.at(i2).at(i1));
            // cout << rowAll.at(i2).at(i1);
        }
        // cout << " " << "done" << endl;
        colAll.push_back(colCurrent);

    };

    int highestScenicNo = 0;
    int currentScenicNo = 0;
    // Logic:
    // Find the innermost tree that is visible for each row and column
    // Log the scenic point of each of such tree
    // Find max 

    // Iterating through the all the trees 
    for (int rowNo = 0; rowNo < noOfRow; rowNo++) {
        for (int colNo = 0; colNo < noOfCol; colNo++) {
            currentScenicNo = deriveScenicNo(rowNo, colNo, rowAll.at(rowNo), colAll.at(colNo));
            if (currentScenicNo > highestScenicNo) {
                highestScenicNo = currentScenicNo;
            }
        }
        // cout << endl;
    }  
    cout << highestScenicNo; // Attempt: 14580 - Answer Inaccurate
    // Next attempt: 805392 - wrong answer
}