#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    vector<int> palindromeList;
    int num;
    string numInString, numReversed;

    for (int i1 = 999; i1 > 99; i1--) {
        for (int i2 = 999; i2 > 99; i2--) {
            num = i1 * i2;
            numInString = to_string(num);
            numReversed = "";
            
            for (int is = numInString.size() - 1; is > -1; is--) {
                numReversed += numInString[is];
            }

            if (numInString == numReversed) {
                palindromeList.push_back(num);
            }
        }
    }

    sort(palindromeList.begin(), palindromeList.end());
    cout << palindromeList.back(); // Answer: 906609
}