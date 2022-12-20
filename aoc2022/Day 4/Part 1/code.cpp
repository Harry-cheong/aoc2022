#include <iostream>
#include <fstream>
#include <string> 

using namespace std;

int main() {
    string myText;
    
    ifstream myFile("C:\\Users\\User\\Desktop\\Harry\\aoc2022\\aoc2022\\Day 4\\Part 1\\input.txt");

    int noOfRepeatedAssign = 0;
    while (getline(myFile, myText)) {
        string str = myText;
        string separator = ",";
        string period = "-";

        int found = str.find(separator);

        string elf1 = str.substr(0, found);
        string elf2 = str.substr(found + 1);

        // Logic: if the max and min value are found in the list of a single elf, it means that there is a overlap

        found = elf1.find(period);
        int elf1FirstAssign = stoi(elf1.substr(0, found));
        int elf1SecAssign = stoi(elf1.substr(found + 1));
        int elf1AssignSize = elf1SecAssign - elf1FirstAssign;

        found = elf2.find(period);
        int elf2FirstAssign = stoi(elf2.substr(0, found));
        int elf2SecAssign = stoi(elf2.substr(found + 1));
        int elf2AssignSize = elf2SecAssign - elf2FirstAssign;

        if ((elf1FirstAssign > elf2FirstAssign && elf1SecAssign < elf2SecAssign) || (elf2FirstAssign > elf1FirstAssign && elf2SecAssign < elf1SecAssign) ||(elf1FirstAssign == elf2FirstAssign) || (elf1SecAssign == elf2SecAssign)
        ) {
            noOfRepeatedAssign += 1;
            // cout << "Repeat";
        }
 
    }

    cout << noOfRepeatedAssign; // Answer: 477
}