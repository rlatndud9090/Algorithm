#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void DFS(vector<set<int>>& graph, vector<bool>& is_entered, int start_pos) {
    cout << start_pos << " ";
    is_entered[start_pos-1] = true;
    auto near_nodes = graph[start_pos-1];
    for (auto node: near_nodes) {
        if (is_entered[node-1] == false) {
            // 방문한 적이 없는 node가 있으면, 방문 상태를 true로 하고 해당 node부터 탐색 진행
            DFS(graph, is_entered, node);
        }
    }
}

void BFS(vector<set<int>>& graph, vector<bool>& is_entered, int start_pos) {
    queue<int> node_queue;
    is_entered[start_pos-1] = true;
    node_queue.push(start_pos);

    while(!node_queue.empty()) {
        auto node = node_queue.front();
        node_queue.pop();
        cout << node << " ";

        auto near_nodes = graph[node-1];
        for (auto near_node: near_nodes) {
            if (is_entered[near_node-1] == false) {
                is_entered[near_node-1] = true;
                node_queue.push(near_node);
            }
        }
    }
}

int main() {
    int nodes_num, edge_num, start_pos = 0;
    cin >> nodes_num >> edge_num >> start_pos;

    vector<set<int>> graph(nodes_num, set<int>());

    for (int i = 0; i < edge_num; i++) {
        int first_node, second_node = 0;
        cin >> first_node >> second_node;
        graph[first_node-1].emplace(second_node);
        graph[second_node-1].emplace(first_node);
    }

    // DFS
    vector<bool> is_entered(nodes_num, false);
    DFS(graph, is_entered, start_pos);

    cout << endl;

    //BFS
    is_entered = vector<bool>(nodes_num, false);
    BFS(graph, is_entered, start_pos);
}