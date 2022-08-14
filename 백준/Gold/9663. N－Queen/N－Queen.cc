#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void tryPlaceQueen(vector<int>& indexInRow, int row, int& success, int n) {
    if (n == row) {
        success += 1;
        return;
    }

    for (int i = 0; i < n; i++) {
        bool valid = true;
        for (int k = 0; k < row ; k++) {
            if (i == indexInRow[k] 
                || (abs(i - indexInRow[k]) == abs(row - k))) {
                    valid = false;
            }
        }
        if (valid) {
            indexInRow[row] = i;
            tryPlaceQueen(indexInRow, row + 1, success, n);
        }
    }
}

int main() {

    int n = 0;
    cin >> n;

    int success = 0;

    vector<int> indexInRow(n, 0);

    tryPlaceQueen(indexInRow, 0, success, n);

    cout << success;
    return 0;
}