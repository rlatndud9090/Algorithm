#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
    int n, m = 0;
    cin >> n >> m;

    vector<vector<int>> graph(n+1); // 연결 리스트로 구현한 그래프
    vector<int> in_degree(n+1, 0); // 각 정점의 진입 차수 저장

    for (int i = 0; i < m; i++) {
        int src, dst = 0;
        cin >> src >> dst;
        graph[src].push_back(dst); // 에지 정보 저장
        in_degree[dst] += 1; // 목적 정점의 진입 차수 증가
    }

    queue<int> visit_queue; // 위상 정렬을 수행할 queue
    vector<int> result_vector; // 줄 세우기 결과를 저장할 vector

    for (int i = 1; i < n+1; i++) {
        if (in_degree[i] == 0) {
            visit_queue.push(i); // 진입 차수가 0인 정점들을 queue에 push
        }
    }

    while (!visit_queue.empty()) {
        int cur_p = visit_queue.front();
        visit_queue.pop();
        result_vector.push_back(cur_p);

        for (auto& near_p: graph[cur_p]) {
            // 현재 정점에서부터 나가는 에지들을 제거
            in_degree[near_p] -= 1; // 에지 제거 시, 목적 정점의 진입 차수가 1 줄어듬
            if (in_degree[near_p] == 0) { // 진입 차수가 줄어들어 0이 되었다면, queue에 추가함
                visit_queue.push(near_p);
            }
        }
    }

    for (auto& p: result_vector) {
        cout << p << " ";
    }

    return 0;
}