#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int DP(vector<vector<int>>& map, vector<vector<int>>& memo, int m, int n, int x, int y) {
    if (x == m-1 && y == n-1) return 1;
    if (memo[x][y] != -1) return memo[x][y];

    int result = 0;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
            if (map[x][y] > map[nx][ny]) {
                result += DP(map, memo, m, n, nx, ny);
            }
        }
    }

    memo[x][y] = result;
    return result;
}

int main() {
    int m, n = 0;
    cin >> m >> n;

    vector<vector<int>> map(m, vector<int>(n, 0));
    vector<vector<int>> memo(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    cout << DP(map, memo, m, n, 0, 0);

    return 0;
}