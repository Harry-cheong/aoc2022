#include <iostream> 
#include <cstring>
#include <vector>
#include <set>

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
    long long int n = 600851475143;

    vector<int> primeList;
    vector<int> primeFactor;
    primeList = SieveOfEratosthenes(10000);
    
    for (int i: primeList) {
        while (n % i == 0) {
            n /= i;
            primeFactor.push_back(i);
        }
    }
    
    cout << primeFactor.back() << endl; // Answer: 6857
}