#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>

using namespace std;

int main() {
    int m, n = 0;
    cin >> m >> n;

    vector<vector<int>> box(n, vector<int>(m, 0));
    vector<vector<int>> min_day(n, vector<int>(m, 0));
    deque<pair<int,int>> visit_queue;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int k = 0;
            cin >> k;
            box[i][j] = k;
            min_day[i][j] = -1;
            if (k == 1) {
                visit_queue.push_back(make_pair(i,j));
                min_day[i][j] = 0;
            }
        }
    }

    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0 ,-1, 0};

    while (!visit_queue.empty()) {
        auto p = visit_queue.front();
        visit_queue.pop_front();
        auto cur_min_day = min_day[p.first][p.second];
        for (int k = 0; k < 4; k++) {
            int ni = p.first + di[k];
            int nj = p.second + dj[k];
            if (ni >= 0 && ni <= n-1 && nj >= 0 && nj <= m-1) {
                if (box[ni][nj] == 0 && min_day[ni][nj] == -1) {
                    visit_queue.push_back(make_pair(ni,nj));
                    min_day[ni][nj] = cur_min_day + 1;
                }
            }
        }
    }

    int max_min_day = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (box[i][j] == 0 && min_day[i][j] == -1) {
                cout << -1;
                return 0;
            }
            max_min_day = max(max_min_day, min_day[i][j]);
        }
    }

    cout << max_min_day;

    return 0;
}