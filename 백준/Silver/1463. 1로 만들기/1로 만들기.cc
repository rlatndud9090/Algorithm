#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 1000000;

vector<int> memo(MAX_SIZE, 0);

int calc(int n) {
    if ( n == 1 ) return 0;

    if (memo[n] > 0) return memo[n];

    int smallest = calc(n-1);
    if (n%3 == 0) {
        smallest = min(smallest, calc(n/3));
    }
    if (n%2 == 0) {
        smallest = min(smallest, calc(n/2));
    }
    memo[n] = ++smallest;
    return smallest;
}

int main() {
    int n = 0;
    cin >> n;
    cout << calc(n) << endl;
}