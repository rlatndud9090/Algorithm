#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <set>

const int INF = INT_MAX;

using namespace std;

int calc_min_distance(vector<vector<pair<int, int>>>& graph, int src, int dst) {
    if (src == dst) return 0;

    int n = graph.size();
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> heap;
    set<int> visited;
    vector<int> distance(n, INF);

    distance[src] = 0;
    heap.emplace(make_pair(0, src));

    while(!heap.empty()) {
        auto current = heap.top();
        heap.pop();

        int cur_dist = current.first;
        int cur_p = current.second;

        if (cur_p == dst) return cur_dist;

        if (visited.find(cur_p) == visited.end()) {
            for (auto& e: graph[cur_p]) {
                int next_p = e.first;
                int weight = e.second;
                if (visited.find(next_p) == visited.end()) {
                    int new_dist = distance[cur_p] + weight;
                    if (new_dist < distance[next_p]) {
                        distance[next_p] = new_dist;
                        heap.emplace(make_pair(new_dist, next_p));
                    }
                }
            }
            visited.emplace(cur_p);
        }
    }
}

int main() {
    int n, m, x = 0;
    cin >> n >> m >> x;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        graph[s].push_back(make_pair(d, w));
    }

    int max_dist = 0;
    for (int j = 1; j < n+1; j++) {
        int cur_dist = calc_min_distance(graph, j, x) + calc_min_distance(graph, x, j);
        max_dist = max(max_dist, cur_dist);
    }

    cout << max_dist;
}