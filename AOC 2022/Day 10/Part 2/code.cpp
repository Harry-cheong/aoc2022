#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void displayScreen(vector<vector<string>> display, ofstream &outFile) {
    for (int i1 = 0; i1 < 6; i1++) {
        for (int i2 = 0; i2 < display.at(i1).size(); i2++) {
            outFile << display.at(i1).at(i2);
        }
        outFile << endl;
    }
    outFile << endl;
}

void displaySprite(int indexOfMiddleSprite, ofstream &outFile) {
    outFile << "Sprite:";
    for (int i = 0; i < 40; i++) {
        if (indexOfMiddleSprite - 1 <= i && i <= indexOfMiddleSprite + 1)
            outFile << "🎅";
        else {
            outFile << "🎄";
        }
    }
    outFile << endl << endl;
}
void drawPixel(int drawAtPixel, int indexOfMiddleSprite, vector<vector<string>> &display, ofstream &outFile) {
    displaySprite(indexOfMiddleSprite, outFile);
    if (drawAtPixel < 40) {
        if (indexOfMiddleSprite - 1 <= drawAtPixel && drawAtPixel <= indexOfMiddleSprite + 1) {
            display.at(0).push_back("🎅");
        } else {
            display.at(0).push_back("🎄");
        }
        displayScreen(display, outFile);
    } else if (drawAtPixel < 80) {
        if (indexOfMiddleSprite - 1 <= (drawAtPixel - 40) && (drawAtPixel - 40) <= indexOfMiddleSprite + 1) {
            display.at(1).push_back("🎅");
        } else {
            display.at(1).push_back("🎄");
        }
        displayScreen(display, outFile);
    } else if (drawAtPixel < 120) {
        if (indexOfMiddleSprite - 1 <= (drawAtPixel - 80) && (drawAtPixel - 80) <= indexOfMiddleSprite + 1) {
            display.at(2).push_back("🎅");
        } else {
            display.at(2).push_back("🎄");
        }
        displayScreen(display, outFile);
    } else if (drawAtPixel < 160) {
        if (indexOfMiddleSprite - 1 <= (drawAtPixel - 120) && (drawAtPixel - 120) <= indexOfMiddleSprite + 1) {
            display.at(3).push_back("🎅");
        } else {
            display.at(3).push_back("🎄");
        }
        displayScreen(display, outFile);
    } else if (drawAtPixel < 200) {
        if (indexOfMiddleSprite - 1 <= (drawAtPixel - 160) &&(drawAtPixel - 160) <= indexOfMiddleSprite + 1) {
            display.at(4).push_back("🎅");
        } else {
            display.at(4).push_back("🎄");
        }
        displayScreen(display, outFile);
    } else {
        if (indexOfMiddleSprite - 1 <= (drawAtPixel - 200) && (drawAtPixel - 200) <= indexOfMiddleSprite + 1) {
            display.at(5).push_back("🎅");
        } else {
            display.at(5).push_back("🎄");
        }
        displayScreen(display, outFile);

    }
}

int main() {
    string myText;

    ifstream myFile("C:\\Users\\harry\\Desktop\\Computing\\aoc2022\\aoc2022\\Day 10\\Part 2\\input.txt");
    ofstream outFile("C:\\Users\\harry\\Desktop\\Computing\\aoc2022\\aoc2022\\Day 10\\Part 2\\output.txt");

    int drawAtPixel = 0;
    int indexOfMiddleSprite = 1; 

    // CRT
    vector<vector<string>> display;
    
    vector<string> row;
    for (int i = 0; i < 6; i++) {
        display.push_back(row);
    }
    
    vector<int> signalStrengthAfterEachCycle;
    while (getline(myFile, myText)) {
        if (myText == "noop") {
            drawPixel(drawAtPixel, indexOfMiddleSprite, display, outFile);
            drawAtPixel++;
            
        }
        else {
            int moveBy = stoi(myText.substr(5, 3));
            drawPixel(drawAtPixel, indexOfMiddleSprite, display, outFile);
            drawAtPixel++;
            // cout << signalIncrease << endl;
            drawPixel(drawAtPixel, indexOfMiddleSprite, display, outFile);
            drawAtPixel++;
            indexOfMiddleSprite += moveBy;
        }
    };

    // Display
    outFile << "Final:" << endl;
    displayScreen(display, outFile); // 8 letter capital letter word: RLEZFLGE
}