#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u].emplace_back(v, cost);
    }

    int start, end;
    cin >> start >> end;

    vector<int> dist(N + 1, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int current_cost = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (current_cost > dist[current_node]) continue;

        for (const auto& next_pair : graph[current_node]) {
            int next_node = next_pair.first;
            int next_cost = next_pair.second;
            int new_cost = current_cost + next_cost;

            if (new_cost < dist[next_node]) {
                dist[next_node] = new_cost;
                pq.emplace(new_cost, next_node);
            }
        }
    }

    cout << dist[end] << endl;

    return 0;
}