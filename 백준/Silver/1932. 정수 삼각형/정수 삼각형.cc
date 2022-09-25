#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<vector<int>> triangle(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> triangle[i][j];
        }
    }

    vector<vector<int>> max_distance(n, vector<int>(n, 0));
    max_distance[0][0] = triangle[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            int left_dist = j != 0 ? max_distance[i - 1][j - 1] : 0;
            int right_dist = j != i ? max_distance[i - 1][j] : 0;
            max_distance[i][j] = max(left_dist, right_dist) + triangle[i][j];
        }
    }

    auto max_iter = max_element(max_distance[n - 1].begin(), max_distance[n - 1].end());
    cout << (*max_iter);
    return 0;
}