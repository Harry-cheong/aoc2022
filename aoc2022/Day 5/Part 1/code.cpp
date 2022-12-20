#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

int main() {
    string myText;

    deque<string> boxStack1;
    deque<string> boxStack2;
    deque<string> boxStack3;
    deque<string> boxStack4;
    deque<string> boxStack5;
    deque<string> boxStack6;
    deque<string> boxStack7;
    deque<string> boxStack8;
    deque<string> boxStack9;
    

    ifstream myFile("C:\\Users\\User\\Desktop\\Harry\\aoc2022\\aoc2022\\Day 5\\Part 1\\input.txt");
    
    // Box Stacks 

    int line = 1;
    int indexOfCrates[9] = {1, 5, 9, 13, 17, 21, 25, 29, 33};

    while (getline(myFile, myText)) {
        if (line < 9) {
            
            // Storing initial pos of crates
            string ch;

            ch = myText[indexOfCrates[0]];
            if (ch != " ") 
                boxStack1.push_back(ch);
            cout << ch;
            
            ch = myText[indexOfCrates[1]];
            if (ch != " ") 
                boxStack2.push_back(ch);
            cout << ch;

            ch = myText[indexOfCrates[2]];
            if (ch != " ") 
                boxStack3.push_back(ch);
            cout << ch;

            ch = myText[indexOfCrates[3]];
            if (ch != " ") 
                boxStack4.push_back(ch);
            cout << ch;

            ch = myText[indexOfCrates[4]];
            if (ch != " ") 
                boxStack5.push_back(ch);
            cout << ch;

            ch = myText[indexOfCrates[5]];
            if (ch != " ") 
                boxStack6.push_back(ch);
            cout << ch;

            ch = myText[indexOfCrates[6]];
            if (ch != " ") 
                boxStack7.push_back(ch);
            cout << ch;

            ch = myText[indexOfCrates[7]];
            if (ch != " ") 
                boxStack8.push_back(ch);
            cout << ch;

            ch = myText[indexOfCrates[8]];
            if (ch != " ") 
                boxStack9.push_back(ch);
            cout << ch;

            cout << " " << "Registered" << endl;

            // Registered after 8 lines
            //  GR    P  Registered
            //  HW TP H  Registered
            //  FTPBD N  Registered
            // LTMQLC Z  Registered
            // CCNVSH VG Registered
            // GLFDMVTJH Registered
            // MDJFFNCSF Registered
            // QRVJNRHGZ Registered
    
        } 
        else if (line < 11) {

        } else {
            
            // Finding specific info from line
            int indexOfFrom = myText.find("from");
            int indexOfTo = myText.find("to");

            int noOfBox = stoi(myText.substr(indexOfFrom - 3, 2));
            int initialStack =  stoi(myText.substr(indexOfTo - 2, 1));
            int finalStack = stoi(myText.substr(indexOfTo + 2)); 
        
            // cout << noOfBox << initialStack << finalStack << endl;

            // Moving crates
            for (int i = 0; i < noOfBox; i++) {
                string transfer;
                switch(initialStack) {
                    case 1:
                        transfer = boxStack1.front();
                        boxStack1.pop_front();
                        break;
                    case 2:
                        transfer = boxStack2.front();
                        boxStack2.pop_front();
                        break;
                    case 3:
                        transfer = boxStack3.front();
                        boxStack3.pop_front();
                        break;
                    case 4:
                        transfer = boxStack4.front();
                        boxStack4.pop_front();
                        break;
                    case 5:
                        transfer = boxStack5.front();
                        boxStack5.pop_front();
                        break;
                    case 6:
                        transfer = boxStack6.front();
                        boxStack6.pop_front();
                        break;
                    case 7:
                        transfer = boxStack7.front();
                        boxStack7.pop_front();
                        break;
                    case 8:
                        transfer = boxStack8.front();
                        boxStack8.pop_front();
                        break;
                    case 9:
                        transfer = boxStack9.front();
                        boxStack9.pop_front();
                        break;
                }

                // cout << transfer << endl;
                switch(finalStack) {
                    case 1:
                        boxStack1.push_front(transfer);
                        break;
                    case 2:
                        boxStack2.push_front(transfer);
                        break;
                    case 3:
                        boxStack3.push_front(transfer);
                        break;
                    case 4:
                        boxStack4.push_front(transfer);
                        break;
                    case 5:
                        boxStack5.push_front(transfer);
                        break;
                    case 6:
                        boxStack6.push_front(transfer);
                        break;
                    case 7:
                        boxStack7.push_front(transfer);
                        break;
                    case 8:
                        boxStack8.push_front(transfer);
                        break;
                    case 9:
                        boxStack9.push_front(transfer);
                        break;
                }
            }
        }
        line++;

    }

    cout << boxStack1.front() << boxStack2.front() <<boxStack3.front() << boxStack4.front() << boxStack5.front() << boxStack6.front() << boxStack7.front() << boxStack8.front() << boxStack9.front(); // Answer: VCTFTJQCG
}