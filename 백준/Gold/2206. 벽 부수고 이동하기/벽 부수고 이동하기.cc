#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << 1;
        return 0;
    }
    vector<vector<int>> graph(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            if(str[j] == '0')
                graph[i][j] = 0;
            else
                graph[i][j] = 1;
        }
    }

    vector<vector<vector<int>>> distance(n, vector<vector<int>>(m, vector<int>(2, -1)));
    vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(2, 0)));
    queue<pair<pair<int, int>, int>> node_q;

    node_q.push(make_pair(make_pair(0, 0), 1));
    distance[0][0][1] = 1;
    visited[0][0][1] = 1;
    while (!node_q.empty()) {
        auto cur_node = node_q.front();
        node_q.pop();
        int x = cur_node.first.first;
        int y = cur_node.first.second;
        int chance = cur_node.second;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (nx == n-1 && ny == m-1) {
                    cout << distance[x][y][chance] + 1;
                    return 0;
                }
                if (graph[nx][ny] == 1 && chance == 1) {
                    distance[nx][ny][0] = distance[x][y][chance] + 1;
                    node_q.push(make_pair(make_pair(nx, ny), 0));
                    visited[nx][ny][0] = 1;
                } else if (graph[nx][ny] == 0) {
                    if ((chance == 1 && visited[nx][ny][1] == 0) || (chance == 0 && visited[nx][ny][0] == 0 && visited[nx][ny][1] == 0)) {
                        distance[nx][ny][chance] = distance[x][y][chance] + 1;
                        node_q.push(make_pair(make_pair(nx, ny), chance));
                        visited[nx][ny][chance] = 1;
                    }
                }
            }
        }
    }
    cout << -1;
    return 0;
}