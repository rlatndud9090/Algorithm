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
    vector<int> in_degree(n+1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        next_q[a].emplace_back(b);
        in_degree[b] += 1;
    }

    priority_queue<int, vector<int>, greater<int>> solve_queue;
    set<int> visited;

    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            solve_queue.push(i);
        }
    }

    while (!solve_queue.empty()) {
        int cur = solve_queue.top();
        solve_queue.pop();
        if (visited.find(cur) == visited.end()) {
            for (int next : next_q[cur]) {
                in_degree[next] -= 1;
                if (in_degree[next] == 0) {
                    solve_queue.push(next);
                }
            }
            visited.emplace(cur);
        }
        cout << cur << " ";
    }

    return 0;
}