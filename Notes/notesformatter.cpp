#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;

int main() {
    int mode; 
    int line;
    cout << "Line: ";
    cin >> line;
    cout << "Mode 1: Chapter, Mode 2: Chapter Topic" << endl;
    cout << "Select Mode: ";
    cin >> mode;

    string myText;
    int lineInFile = 0;

    ifstream inFile("C:\\Users\\harry\\Desktop\\Computing\\aoc2022\\Notes\\C++ libraries\\utility.txt");
    ofstream outFile("C:\\Users\\harry\\Desktop\\Computing\\aoc2022\\Notes\\C++ libraries\\newutility.txt");

    // Variables
    
    // Case 1
    string unaltered = "____________________________________________________";
    string chapterName;
    int unalteredLength = 0;
    int chapterLength = 0;
    int frontLengthof_ = 0;
    int endLengthof_ = 0;
    string frontString_;
    string endString_;

    // Case 2
    int difficultyLvl;
    string topicName;
    string newLine = "";

    switch(mode) {
        case 1:
            cout << "< Chapter >" << endl;
            cout << "Chapter Name (press $ to complete): ";
            cin.ignore();
            getline(cin, chapterName, '$');

            for (char i: chapterName) {
                chapterLength++;
            }
            
            for (char i : unaltered) {
                unalteredLength++;
            }

            if (chapterLength % 2 == 0) {
                frontLengthof_ = endLengthof_ = unalteredLength / 2 - chapterLength / 2 - 1;
            } else {
                frontLengthof_ = endLengthof_ = (unalteredLength - 1 - chapterLength) / 2;
            }

            for (int i = 0; i < frontLengthof_; i++) {
                frontString_ += "_";
            }

            for (int i = 0; i < endLengthof_; i++) {
                endString_ += "_";
            }
            
            // Rewritting File
            while (getline(inFile, myText)) {
                lineInFile++;
                if (lineInFile == line) {
                    outFile <<  frontString_ << " " << chapterName << " " << endString_ << endl;
                } else {
                    outFile << myText << endl;  
                }
            };
            break;
        
        case 2:
            cout << "< Chapter Topic >" << endl;
            cout << "Difficulty Level: ";
            cin >> difficultyLvl;
            cout << "Topic Name (press $ to complete): ";
            cin.ignore();
            getline(cin, topicName, '$'); 

            // Rewriting File
            while (getline(inFile, myText)) {
                lineInFile++;
                if (lineInFile == line) {
                    newLine += "| ";
                    for (int i = 0; i < difficultyLvl; i++) {
                        newLine += "[🌟]";
                    }
                    newLine += " ";
                    newLine += topicName;
                    newLine += " |";
                    outFile << newLine << endl;
                } else {
                    outFile << myText << endl;  
                }
            };
            break;

        default:
            cout << "Invalid Mode";
            break;
    }

    inFile.close();
    outFile.close();


    remove("C:\\Users\\harry\\Desktop\\Computing\\aoc2022\\Notes\\C++ libraries\\utility.txt");
    if (rename("C:\\Users\\harry\\Desktop\\Computing\\aoc2022\\Notes\\C++ libraries\\newutility.txt", "C:\\Users\\harry\\Desktop\\Computing\\aoc2022\\Notes\\C++ libraries\\utility.txt") != 0) {
        cout << "No such File or directory";
    } else {
        cout << "Successful";
    }
}
