#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> SieveOfEratosthenes(int n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    
    vector<int> primeList;
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            primeList.push_back(p);
        }
    }
    return primeList;
}

int main() {
    vector<int> primeList = SieveOfEratosthenes(2000000);

    long long int sum = 0;

    for (long long int primeNum : primeList) {
        sum += primeNum;
    }

    cout << sum; // Answer: 142913828922
}