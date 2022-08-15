#include <iostream>
#include <limits>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
    int v, e, start = 0;
    cin >> v >> e >> start;

    // 그래프 구성 단계 시작
    vector<vector<pair<int,int>>> edges(v+1);

    for (int i = 0; i < e; i++) {
        int src, dst, weight = 0;
        scanf("%d %d %d", &src, &dst, &weight);
        edges[src].emplace_back(make_pair(dst, weight));
    }
    // 그래프 구성 단계 끝

    // 다익스트라 알고리즘 단계 시작
    set<int> visited; // 방문한 정점 번호 목록
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> heap; // 다익스트라 알고리즘 적용을 위한, distance로 정렬된 최소 힙 (distance, id pair)
    vector<int> distance(v + 1, numeric_limits<int>::max()); // 정점별 거리 정보. 무한대로 초기화됨.

    // 시작 정점의 거리를 0으로 하여 최소 힙에 추가
    distance[start] = 0;
    heap.emplace(make_pair(0, start));

    // 다익스트라 알고리즘을 이용한 순회 시작
    while (!heap.empty()) {
        auto cur_v = heap.top();
        heap.pop();

        // 방문한 적이 없는 정점인 경우
        if (visited.find(cur_v.second) == visited.end()) {
            auto edges_from_cur = edges[cur_v.second];
            // 이웃 정점들 순회
            for (int k = 0; k < edges_from_cur.size(); k++) {
                auto near_point = edges_from_cur[k];
                // 현 정점에서 이웃 정점으로 갈 때의 거리(new_distance)와 기존에 저장돼있던 거리(distance[near_v])를 비교
                auto new_distance = cur_v.first + near_point.second;
                if (new_distance < distance[near_point.first]) {
                    // 새 거리값이 더 작다면 갱신하고 최소 힙에 추가
                    heap.emplace(new_distance, near_point.first);
                    distance[near_point.first] = new_distance;
                }
            }
            // 방문 표시
            visited.emplace(cur_v.second);
        }
    }
    // 다익스트라 알고리즘 단계 끝

    // 출력 단계 시작
    for (int j = 1; j < v + 1; j++) {
        if (distance[j] == numeric_limits<int>::max()) {
            printf("INF\n");
        } else {
            printf("%d\n", distance[j]);
        }
    }
    // 출력 단계 끝

    return 0;
}