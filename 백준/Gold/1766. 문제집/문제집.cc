#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
    int n, m = 0;
    cin >> n >> m;

    int start_q = 1;

    vector<vector<int>> next_q(n+1);
    vector<set<int>> prev_q(n+1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        next_q[a].emplace_back(b);
        prev_q[b].emplace(a);
    }

    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 1; i <= n; i++) {
        if (prev_q[i].size() == 0) {
            min_heap.push(i);
        }
    }

    int count = n;
    while (count-- > 0) {
        int cur = min_heap.top();
        min_heap.pop();
        cout << cur << " ";
        for (int next: next_q[cur]) {
            prev_q[next].erase(cur);
            if (prev_q[next].size() == 0) {
                min_heap.push(next);
            }
        }
    }

    return 0;
}