#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<vector<int>> cost(n+1, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        int cost_r, cost_g, cost_b = 0;
        cin >> cost_r >> cost_g >> cost_b;
        cost[i+1][0] = cost_r;
        cost[i+1][1] = cost_g;
        cost[i+1][2] = cost_b;
    }
    vector<vector<int>> total_cost(n+1, vector<int>(3,0));
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            copy(cost[i].begin(), cost[i].end(), total_cost[i].begin());
        } else {
            total_cost[i][0] = min(total_cost[i-1][1], total_cost[i-1][2]) + cost[i][0];
            total_cost[i][1] = min(total_cost[i-1][0], total_cost[i-1][2]) + cost[i][1];
            total_cost[i][2] = min(total_cost[i-1][0], total_cost[i-1][1]) + cost[i][2];
        }
    }

    cout << *(min_element(total_cost[n].begin(), total_cost[n].end()));

    return 0;
}