#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int main() {
    int n = 0;
    cin >> n;

    int shark_pos = -1;
    int shark_size = 2;
    int fish_count = 0;
    vector<int> map(n*n, 0);

    for (int i = 0; i < n*n; i++) {
        cin >> map[i];
        if (map[i] == 9) {
            shark_pos = i;
        } else if(map[i] != 0) {
            fish_count++;
        }
    }

    int dx[4] = {-n, -1, 1, n};

    int total_disatnce = 0;
    int eat_count = 0;

    while (fish_count != 0) {
        queue<int> visit_queue;
        visit_queue.push(shark_pos);
        set<int> visited;

        vector<int> distance(n*n, INF);
        distance[shark_pos] = 0;

        int top_left_fish_pos = INF;

        while (!visit_queue.empty()) {
            auto cur_pos = visit_queue.front();
            visit_queue.pop();

            if (top_left_fish_pos != INF && distance[cur_pos] > distance[top_left_fish_pos])
                break;

            if (map[cur_pos] < shark_size && map[cur_pos] > 0 && map[cur_pos] != 9) {
                if (top_left_fish_pos == INF) {
                    top_left_fish_pos = cur_pos;
                } else {
                    if (distance[cur_pos] < distance[top_left_fish_pos]) {
                        top_left_fish_pos = cur_pos;
                    } else if (distance[cur_pos] == distance[top_left_fish_pos] && cur_pos < top_left_fish_pos) {
                        top_left_fish_pos = cur_pos;
                    }
                }
            }

            if (visited.find(cur_pos) == visited.end()) {
                for (int i = 0; i < 4; i++) {
                    auto near_pos = cur_pos + dx[i];
                    bool valid_direction = (i == 0 || i == 3) ? true : (cur_pos / n == near_pos / n);
                    if (near_pos >= 0 && near_pos < n*n && valid_direction && shark_size >= map[near_pos]) {
                        if (visited.find(near_pos) == visited.end()) {
                            distance[near_pos] = distance[cur_pos] + 1;
                            visit_queue.push(near_pos);
                        }
                    }
                }
                visited.insert(cur_pos);
            }
        }

        if (top_left_fish_pos != INF) {
            map[top_left_fish_pos] = 9;
            map[shark_pos] = 0;

            total_disatnce += distance[top_left_fish_pos];
            shark_pos = top_left_fish_pos;
            fish_count--;

            if (++eat_count == shark_size) {
                shark_size++;
                eat_count = 0;
            }
        } else
            break;
    }

    cout << total_disatnce;

    return 0;
}