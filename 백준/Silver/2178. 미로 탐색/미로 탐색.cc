#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<pair<int,int>> next_points(pair<int,int> p, int n, int m) {
    vector<pair<int,int>> nexts;
    if (p.first < n-1) { //right
        nexts.push_back(make_pair(p.first+1, p.second));
    }
    if (p.second < m-1) { //down
        nexts.push_back(make_pair(p.first, p.second+1));
    }
    if (p.first > 0) { //left
        nexts.push_back(make_pair(p.first-1, p.second));
    }
    if (p.second > 0) { //up
        nexts.push_back(make_pair(p.first, p.second-1));
    }

    return nexts;
}

int main() {
    int n, m = 0;
    cin >> n >> m;
    vector<vector<int>> maze(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }

    queue<pair<pair<int,int>,int>> visit_queue;
    map<pair<int,int>,int> visited_map;
    
    visit_queue.push(make_pair(make_pair(0,0),1));

    while(!visit_queue.empty()) {
        auto p = visit_queue.front();
        visit_queue.pop();
        
        if(visited_map.find(p.first) == visited_map.end()) {
            visited_map.emplace(p.first, p.second);
            auto nexts = next_points(p.first, n, m);
            for (auto next_p: nexts) {
                if (maze[next_p.first][next_p.second] == 1) {
                    if(visited_map.find(next_p) == visited_map.end()) {
                        visit_queue.push(make_pair(next_p, p.second+1));
                    }
                }
            }
        }
    }

    cout << visited_map[make_pair(n-1,m-1)];
}