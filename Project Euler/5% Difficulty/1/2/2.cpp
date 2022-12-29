#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> FibonacciSeq = {1, 2};

    while (FibonacciSeq.back() < 4000000) {
        FibonacciSeq.push_back(FibonacciSeq[FibonacciSeq.size() - 1] + FibonacciSeq[FibonacciSeq.size() - 2]);
    }

    int sum = 0;
    for (int value: FibonacciSeq) {
        if (value % 2 == 0) {
            sum += value;
        }
    }

    cout << sum; // Answer: 4613732
}