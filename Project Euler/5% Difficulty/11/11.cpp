#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    string myText;
    vector<int> numIndex;
    vector<vector<int>> grid;

    for (int i = 0; i < 20; i++) {
        numIndex.push_back(i * 3);
    }

    ifstream myFile("C:\\Users\\harry\\Desktop\\Computing\\aoc2022\\5% Difficulty\\Project Euler\\11\\input.txt");

    while (getline(myFile, myText)) {
        vector<int> line; 
        for (int index : numIndex) {
            line.push_back(stoi(myText.substr(index, 2)));
        }

        grid.push_back(line);
    }

    // Check bottom/top

    int product, highestVertical = 0;

    for (int column = 0; column < 20; column++) {

        // Largest possible 4 index selected: 16 17 18 19
        for (int i = 0; i < 17; i++) {
            product = grid.at(i).at(column) * grid.at(i + 1).at(column) * grid.at(i + 2).at(column) * grid.at(i + 3).at(column);

            if (product > highestVertical) {
                highestVertical = product;
            }
        }
    }

    cout << highestVertical << endl;

    // Check left/right 

    int highestHorizontal = 0; 
    for (int row = 0; row < 20; row++) {
        for (int i = 0; i < 17; i++) {
            product = grid.at(row).at(i) * grid.at(row).at(i + 1) * grid.at(row).at(i + 2) * grid.at(row).at(i + 3);

            if (product > highestHorizontal) {
                highestHorizontal = product;
            }
        }
    }

    cout << highestHorizontal << endl;
    
    // Check Diagonal Right

    int highestDiagonal = 0;

    // Check Diagonal Left



}