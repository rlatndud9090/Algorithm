#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int calcSafeArea(vector<vector<int>> graph, queue<pair<int,int>> pointQueue, int n, int m, int wallCount) {
    int visitCount = 0;
    set<pair<int,int>> visited;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    while (!pointQueue.empty()) {
        auto point = pointQueue.front();
        pointQueue.pop();
        if (visited.find(point) == visited.end()) {
            int x = point.first;
            int y = point.second;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && graph[nx][ny] == 0) {
                    if (visited.find(make_pair(nx,ny)) == visited.end()) {
                        pointQueue.push(make_pair(nx,ny));
                    }
                }
            }
            visitCount++;
            visited.emplace(point);
        }
    }

    return (n*m - visitCount - wallCount - 3);
}

int main() {

    int n, m = 0;
    cin >> n >> m;

    int safeArea = 0;
    int wallCount = 0;

    vector<vector<int>> graph(n, vector<int>(m, 0));

    queue<pair<int,int>> pointQueue;
    vector<pair<int,int>> emptyPlace;

    for (int i = 0; i< n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0) {
                emptyPlace.push_back(make_pair(i, j));
            } else if (graph[i][j] == 2) {
                pointQueue.push(make_pair(i, j));
            } else if (graph[i][j] == 1) {
                wallCount++;
            }
        }
    }

    auto firstWall = emptyPlace.begin();
    for (; firstWall != emptyPlace.end(); firstWall++) {
        graph[(*firstWall).first][(*firstWall).second] = 1;
        auto secondWall = firstWall + 1;
        for (; secondWall != emptyPlace.end(); secondWall++) {
            graph[(*secondWall).first][(*secondWall).second] = 1;
            auto thirdWall = secondWall + 1;
            for (; thirdWall != emptyPlace.end(); thirdWall++) {
                graph[(*thirdWall).first][(*thirdWall).second] = 1;
                safeArea = max(calcSafeArea(graph, pointQueue, n, m, wallCount), safeArea);
                graph[(*thirdWall).first][(*thirdWall).second] = 0;
            }
            graph[(*secondWall).first][(*secondWall).second] = 0;
        }
        graph[(*firstWall).first][(*firstWall).second] = 0;
    }

    cout << safeArea;
    return 0;
}