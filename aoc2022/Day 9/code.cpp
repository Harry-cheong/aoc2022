#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

void moveWithDirection(char direction, int &xcoord, int &ycoord) {
    switch (direction) {
        case 'D':
            ycoord--;
            break;
        case 'U':
            ycoord++;
            break;
        case 'R':
            xcoord++;
            break;
        case 'L':
            xcoord--;
            break;
    }
}

void moveDiagonal(int xhead, int &xtail, int yhead, int &ytail) {

    // First quadrant
    if (xhead > xtail && yhead > ytail) {
        xtail++;
        ytail++;
    }

    // Second quadrant
    else if (xhead < xtail && yhead > ytail) {
        xtail--;
        ytail++;
    }

    // Third quardrant
    else if (xhead < xtail && yhead < ytail) {
        xtail--;
        ytail--;
    }

    // Fourth quardrant 
    else if (xhead > xtail && yhead < ytail) {
        xtail++;
        ytail--;
    }

}

bool isTouching(int xhead, int xtail, int yhead, int ytail) {
    if (abs(yhead - ytail) > 1 || abs(xhead - xtail) > 1) {
        return false;
    }
    return true;
}
string moveHeadOnce(string headpos, char direction) {   
    int indexOfComma = headpos.find(",");

    int xhead = stoi(headpos.substr(1, indexOfComma - 1));
    int yhead = stoi(headpos.substr(indexOfComma + 1, headpos.size() - indexOfComma - 2));

    moveWithDirection(direction, xhead, yhead);
    string coordFinal = "(" + to_string(xhead) + "," + to_string(yhead) + ")";
    return coordFinal;
}

string moveTail(string headpos, string tailpos, char direction) {   
    // Head
    int indexOfComma = headpos.find(",");
    int xhead = stoi(headpos.substr(1, indexOfComma - 1));
    int yhead = stoi(headpos.substr(indexOfComma + 1, headpos.size() - indexOfComma - 2));

    // Tail
    indexOfComma = tailpos.find(",");
    int xtail = stoi(tailpos.substr(1, indexOfComma - 1));
    int ytail = stoi(tailpos.substr(indexOfComma + 1, tailpos.size() - indexOfComma - 2));

    // Tail move up/down in line with head
    if (xhead == xtail && yhead == ytail) {
        moveWithDirection(direction, xtail, ytail);
    }
    
    else if (xhead == xtail && (abs(yhead - ytail) == 2)) {
        moveWithDirection(direction, xtail, ytail);
    } 
    
    // Tail move left/right in line with head
    else if (yhead == ytail && (abs(xhead - xtail) == 2)) {
       moveWithDirection(direction, xtail, ytail);
    } 
    
    // Tail move up/down diagonally wrt head
    else if (!isTouching(xhead, xtail, yhead, ytail) && xhead != xtail && yhead != ytail) {

        moveDiagonal(xhead, xtail, yhead, ytail);

    }

    string coordFinal;
    coordFinal = "(" + to_string(xtail) + "," + to_string(ytail) + ")";
    return coordFinal;
}

int main() {
    string myText;
    vector<string> command;

    ifstream myFile("C:\\Users\\User\\Desktop\\Harry\\aoc2022\\aoc2022\\Day 9\\input.txt");
    ofstream outFile("C:\\Users\\User\\Desktop\\Harry\\aoc2022\\aoc2022\\Day 9\\output.txt");
    
    string coordOfHead = "(0,0)";
    string coordOfTail = "(0,0)";
    set<string>posHistory;
    int operationPerformed = 0;
    string staller;

    while (getline(myFile, myText)) {
        string direction = myText.substr(0, 1);
        int magnitude = stoi(myText.substr(2, 2));
        outFile << endl << direction << " " << magnitude << endl;

        for (int i = 0; i < magnitude; i++) {
            coordOfHead = moveHeadOnce(coordOfHead, direction[0]);
            coordOfTail = moveTail(coordOfHead, coordOfTail, direction[0]);
            outFile << "T: " << coordOfTail << " H: " <<coordOfHead << endl; 
            posHistory.insert(coordOfTail);
        }
        posHistory.insert(coordOfTail);
        // cout << coordOfTail << coordOfHead << endl; 
        // cin >> staller;
        operationPerformed++;
        // prevDirection = direction;
        
    }
    outFile << endl << posHistory.size() << endl;
    outFile << operationPerformed; // Answer: 6494 - incorrect

    // 5953 - Wrong Answer
}
