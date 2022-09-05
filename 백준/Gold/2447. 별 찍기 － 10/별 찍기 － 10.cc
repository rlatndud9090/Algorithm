#include <iostream>
#include <vector>

using namespace std;

void fill_result(int n, int x, int y, vector<vector<int>>& result) {
    if (n == 3) {
        result[x][y] = 1;
        result[x][y + 1] = 1;
        result[x][y + 2] = 1;
        result[x + 1][y] = 1;
        result[x + 1][y + 2] = 1;
        result[x + 2][y] = 1;
        result[x + 2][y + 1] = 1;
        result[x + 2][y + 2] = 1;
        return;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != 1 || j != 1) {
                fill_result(n / 3, x + n / 3 * i, y + n / 3 * j, result);
            }
        }
    }
}

int main() {
    int n = 0;
    cin >> n;

    vector<vector<int>> result(n, vector<int>(n, 0));
    fill_result(n, 0, 0, result);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (result[i][j] == 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}