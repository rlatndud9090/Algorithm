#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 100001;
vector<pair<int, int>> graph[MAX];
bool visited[MAX];
int max_distance, farthest_node;

// BFS로 가장 먼 노드와 거리를 계산
void bfs(int start) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;
    max_distance = 0;

    while (!q.empty()) {
        int current = q.front().first;
        int distance = q.front().second;
        q.pop();

        if (distance > max_distance) {
            max_distance = distance;
            farthest_node = current;
        }

        for (auto& edge : graph[current]) {
            int next = edge.first;
            int cost = edge.second;
            if (!visited[next]) {
                visited[next] = true;
                q.push({next, distance + cost});
            }
        }
    }
}

int main() {
    int V;
    cin >> V;

    for (int i = 0; i < V; ++i) {
        int node;
        cin >> node;
        while (true) {
            int next, cost;
            cin >> next;
            if (next == -1) break;
            cin >> cost;
            graph[node].push_back({next, cost});
        }
    }

    // 첫 번째 BFS: 임의의 노드(1번 노드)에서 가장 먼 노드 찾기
    bfs(1);

    // 두 번째 BFS: 가장 먼 노드에서 다시 가장 먼 노드를 찾아 트리의 지름 계산
    bfs(farthest_node);

    cout << max_distance << endl;
    return 0;
}