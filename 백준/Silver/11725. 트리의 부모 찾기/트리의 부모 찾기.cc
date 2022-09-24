#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    vector<vector<int>> graph(n+1);
    vector<int> parent(n+1, 0);

    for (int i = 0; i < n; i++) {
        int first, second = 0;
        cin >> first >> second;
        graph[first].emplace_back(second);
        graph[second].emplace_back(first);
    }

    stack<int> visit_stack;
    visit_stack.push(1);
    while(!visit_stack.empty()) {
        int cur_node = visit_stack.top();
        visit_stack.pop();
        for (auto next: graph[cur_node]) {
            if (parent[next] == 0) {
                visit_stack.push(next);
                parent[next] = cur_node;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
}