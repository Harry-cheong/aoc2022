#include <iostream>
#include <fstream>
#include <deque>
#include <set> 
#include <vector>

using namespace std;

string indexWrtRow(int row, int column) {
    string index = to_string(row) + "r" + to_string(column);
    return index;
}

string indexWrtCol(int row, int column) {
    string index = to_string(column) + "c" + to_string(row);
    return index;
}

// Iteration Logic 
    // Possible cases
    // Case 1: First tree -> skip
    // Case 2: cur > vision -> track
    // Case 3: cur < vision -> skip
    // Case 4: max curr (9) -> move on

void iterateFront(deque<int> array, int unknownNo, string mode, set<string> &track) {
    int curTree = 0;
    int curVisibleTree = 0;

    for (int im = 0; im < array.size(); im++) {
            curTree = array.at(im);

            if (im == 0) {
                
            } else if (curTree > curVisibleTree) {
                if (mode == "column") {
                    track.insert(indexWrtCol(unknownNo, im));
                    track.insert(indexWrtRow(unknownNo, im));
                } else if (mode == "row") {
                    track.insert(indexWrtCol(im, unknownNo));
                    track.insert(indexWrtRow(im, unknownNo));
                }
            } else if (curTree == 9) {
                return;
            }
            if (curTree > curVisibleTree) {
                curVisibleTree = curTree;
            }
        };

}

void iterateBack(deque<int> array, int unknownNo, string mode, set<string> &track) {
    int curTree = 0;
    int curVisibleTree = 0;

    for (int im = array.size()-1; im > -1; im--) {
            curTree = array.at(im);

            if (im == array.size()-1) {
                
            } else if (curTree > curVisibleTree) {
                if (mode == "column") {
                    track.insert(indexWrtCol(unknownNo, im));
                    track.insert(indexWrtRow(unknownNo, im));
                } else if (mode == "row") {
                    track.insert(indexWrtCol(im, unknownNo));
                    track.insert(indexWrtRow(im, unknownNo));
                }
            } else if (curTree == 9) {
                return;
            }
            if (curTree > curVisibleTree) {
                curVisibleTree = curTree;
            }
        };

}

int main() {
    string myText;

    ifstream myFile("C:\\Users\\User\\Desktop\\Harry\\aoc2022\\aoc2022\\Day 8\\Part 1\\input.txt");

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

    set<string> indexOfTreeVisible;
    // Logic:
    // Using sets, we can avoid double-counting a single element 
    // Every time a tree of a specific index is visible, append the 2 possible index of the tree into the set
    // For example: if the 3th tree on the 2th row is visible, then append 3r2 and 2c3 into the set, that way when checking for columns later, the same tree will not be counted again
    // to find total visile trees, divide size of indexOfTreeVisible by 2

    // Including all trees that are definitely visible
    int count = 0;
    // First & last tree of each row
    for (int rowNo = 0; rowNo < noOfRow; rowNo++) {
        indexOfTreeVisible.insert(indexWrtRow(rowNo, 0));
        indexOfTreeVisible.insert(indexWrtCol(rowNo, 0));

        indexOfTreeVisible.insert(indexWrtRow(rowNo, noOfCol - 1));
        indexOfTreeVisible.insert(indexWrtCol(rowNo, noOfCol - 1));
        
        // cout << indexWrtRow(rowNo, 0) << " " << indexWrtCol(rowNo, 0) << " " << indexWrtRow(rowNo, noOfColumn - 1) << " " << indexWrtCol(rowNo, noOfColumn - 1) << endl;
    }

    // First & last tree of each column 
    for (int columnNo = 0; columnNo < noOfRow; columnNo++) {
        indexOfTreeVisible.insert(indexWrtCol(0, columnNo));
        indexOfTreeVisible.insert(indexWrtRow(0, columnNo));

        indexOfTreeVisible.insert(indexWrtCol(noOfRow - 1, columnNo));
        indexOfTreeVisible.insert(indexWrtRow(noOfRow - 1,columnNo));

        // cout << indexWrtCol(columnNo, 0) << " " << indexWrtRow(columnNo, 0) << " " << indexWrtCol(columnNo,noOfRow - 1) << " " << indexWrtRow(noOfRow - 1,columnNo) << endl;
    }

    // Iterating through the rows to find indexes of visible trees
    // From front of the row
    for (int rowNo = 0; rowNo < noOfRow; rowNo++) {

        // From front of the row
        iterateFront(rowAll.at(rowNo), rowNo, "row", indexOfTreeVisible);
        

        // From back of the row
        iterateBack(rowAll.at(rowNo), rowNo, "row", indexOfTreeVisible);
    }

    // Iterating through the colums to find indexes of visible trees

    // From front of the column
    for (int colNo = 0; colNo < noOfCol; colNo++) {
        // From start of the column
        iterateFront(colAll.at(colNo), colNo, "column", indexOfTreeVisible);

        // From back of the column
        iterateBack(colAll.at(colNo), colNo, "column", indexOfTreeVisible);
    }

    cout << indexOfTreeVisible.size()/2; // Answer: 1736
}