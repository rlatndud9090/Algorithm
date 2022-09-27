#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, max_weight;
    cin >> n >> max_weight;
    vector<pair<int,int>> products(n, make_pair(0, 0));
    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        products[i] = make_pair(w, v);
    }
    vector<vector<int>> max_value(n, vector<int>(max_weight + 1, 0));
    for (int i = 0; i < n; i++) {
        int cur_weight = products[i].first;
        int cur_value = products[i].second;
        for (int left_weight = 0; left_weight < max_weight + 1; left_weight++) {
            if (cur_weight > left_weight) {
                max_value[i][left_weight] = i == 0 ? 0 : max_value[i-1][left_weight];
            } else {
                max_value[i][left_weight] = i == 0 ? cur_value : max(cur_value + max_value[i-1][left_weight - cur_weight], max_value[i-1][left_weight]);
            }
        }
    }

    cout << max_value[n-1][max_weight];
    return 0;
}