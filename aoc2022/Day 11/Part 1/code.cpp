#include <iostream>
#include <fstream>
#include <queue> 
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

class Monkey {
    private:
        int monkeyNo;
        char operationOperator; 
        int operationValue;
        int testDivisibleByValue;
        int throwToIfTrue;
        int throwToIfFalse;
        vector<reference_wrapper<Monkey>> monkeyList;
    
    public:
        queue<int> items;
        int inspectionNo = 0; 

        // Initialisation 
        Monkey(int monkeyNo) 
        {
            this -> monkeyNo = monkeyNo;
        }

        void addMonkeyList(vector<reference_wrapper<Monkey>> monkeyList) {
            this -> monkeyList = monkeyList;
        }

        void addNewItem(int item) {
            items.push(item);
        }

        void addItems(string line) {
            // cout << line << endl;
            int indexOfcolon = line.find(":");
            items.push(stoi(line.substr(indexOfcolon + 2, 2)));
            int starting_pos = 0;
            vector<int> indexOfCommas;

            while (true) {
                size_t indexOfComma = line.find(',', starting_pos);
                if (indexOfComma == string::npos) {
                    break;
                }
                indexOfCommas.push_back(indexOfComma);
                starting_pos = indexOfComma + 1;
            }

            if (!indexOfCommas.empty()) {
                for (int i: indexOfCommas) {
                    items.push(stoi(line.substr(i + 2, 2)));
                };
                indexOfCommas.clear();
            } else {
                return;
            };
        };

        void addOperation(string line) {
            int indexOfold = line.find("old");

            operationOperator = line.substr(indexOfold + 4, 1)[0];

            string value = line.substr(indexOfold + 6, 3);
            if (value == "old") {
                operationOperator = 'N';
                operationValue = 0;
            } else {
                operationValue = stoi(value);
            }

        }

        int operationNew() {
            return items.front();
        }

        void addTest(string line) {
            int indexofby = line.find("by");
            this -> testDivisibleByValue = stoi(line.substr(indexofby + 3, 2));
        }

        void addIfTrue(string line) {
            int indexOfMonkey = line.find("monkey");
            this -> throwToIfTrue = stoi(line.substr(indexOfMonkey + 7, 1));
        }

        void addIfFalse(string line) {
            int indexOfMonkey = line.find("monkey");
            this -> throwToIfFalse = stoi(line.substr(indexOfMonkey + 7, 1));
        }

        void giveToMonkey(ofstream &outFile, int monkeyNo, int item) {
            this -> monkeyList[monkeyNo].get().addNewItem(item);
            outFile << "        Item with worry level " << item << " is thrown to monkey " << monkeyNo << endl;
        }

        // Execution 
        void inspect(ofstream &outFile) {
            int retrievedItem = items.front();
            outFile << "  Monkey inspects an item with a worry level of " <<  retrievedItem << "."<< endl;
            items.pop();

            // Operation
            switch(this -> operationOperator) {
                case '+':
                    retrievedItem += this -> operationValue;
                    break;
                case '-':
                    retrievedItem -= this -> operationValue;
                    break;
                case '*':
                    retrievedItem *= this -> operationValue;
                    break;
                case '/':
                    retrievedItem /= this -> operationValue;
                    break;
                case 'N':
                    retrievedItem *= retrievedItem;
                    break;
            }
            outFile << "        Worry level is multiplied by " << this -> operationValue << " to " << retrievedItem << endl;

            // Monkey gets bored
            outFile << "        Monkey gets bored with item. Worry level is divided by 3 to " << retrievedItem / 3 << endl;
            retrievedItem /= 3;

            // Check condition
            if (retrievedItem % testDivisibleByValue == 0) {
                outFile << "        Current worry level is divisible by " << this -> testDivisibleByValue << endl;
                giveToMonkey(outFile, throwToIfTrue, retrievedItem);
            } else {
                outFile << "        Current worry level is not divisible by " << this -> testDivisibleByValue << endl;
                giveToMonkey(outFile, throwToIfFalse, retrievedItem);
            }
            inspectionNo++;
        }

        void doRound(ofstream &outFile) {
            while (!items.empty()) {
                inspect(outFile);
            }
        }
};


int main() {
    string myText;
    
    ifstream myFile("C:\\Users\\harry\\Desktop\\Computing\\aoc2022\\aoc2022\\Day 11\\Part 1\\input.txt");
    ofstream outFile("C:\\Users\\harry\\Desktop\\Computing\\aoc2022\\aoc2022\\Day 11\\Part 1\\output.txt");

    vector<reference_wrapper<Monkey>> monkeyList;

    // Monkeys
    Monkey monkey0(0), monkey1(1), monkey2(2), monkey3(3), monkey4(4), monkey5(5), monkey6(6), monkey7(7);

    // MonkeyList
    monkeyList.push_back(monkey0);
    monkeyList.push_back(monkey1);
    monkeyList.push_back(monkey2);
    monkeyList.push_back(monkey3);
    monkeyList.push_back(monkey4);
    monkeyList.push_back(monkey5);
    monkeyList.push_back(monkey6);
    monkeyList.push_back(monkey7);

    // Add MonkeyList
    for (reference_wrapper<Monkey> monkey : monkeyList) {
        monkey.get().addMonkeyList(monkeyList);
    }

    int line = 0;
    int monkeyNo = 0;
    while (getline(myFile, myText)) {
        line++;
        if (line == 2) {
            monkeyList.at(monkeyNo).get().addItems(myText);
        } 
    
        else if (line == 3) {
            monkeyList.at(monkeyNo).get().addOperation(myText);
        } 
        
        else if (line == 4) {
            monkeyList.at(monkeyNo).get().addTest(myText);
        } 
        
        else if (line == 5) {
            monkeyList.at(monkeyNo).get().addIfTrue(myText);
        } 
        
        else if (line == 6) {
            monkeyList.at(monkeyNo).get().addIfFalse(myText);
            // cout << "Monkey " << monkeyNo << " done" << endl;
        } 
        
        else if (line == 7) {
            line = 0;
            monkeyNo++; 
        }
    }

    // 20 Rounds
    for (int i = 0; i < 20; i++) {
        for (int monkeyNo = 0; monkeyNo < monkeyList.size() ; monkeyNo++) {
            outFile << "Monkey " << monkeyNo << ":" << endl;
            monkeyList.at(monkeyNo).get().doRound(outFile);
            outFile << endl;
        }
    }

    // Results
    outFile << endl << endl << "Results:" << endl;
    vector<int> results;
    cout << "Results" << endl;
    for (reference_wrapper<Monkey> monkey : monkeyList) {
        results.push_back(monkey.get().inspectionNo);
        outFile << monkey.get().inspectionNo << endl;
        cout << monkey.get().inspectionNo << endl;
    }

    // Final Result
    sort(results.begin(), results.end(), greater<int>());
    cout << results.at(0) << " * " << results.at(1) << " = " << results.at(0) * results.at(1); // Answer: 259 * 216 = 55944
    
}