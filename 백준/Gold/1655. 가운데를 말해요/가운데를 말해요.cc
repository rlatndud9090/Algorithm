#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, less<int>> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;

int mid() {
    if (max_heap.size() == min_heap.size()) {
        return min(max_heap.size() == 0? 0 : max_heap.top(), min_heap.size() == 0? 0 : min_heap.top());
    } else if (max_heap.size() > min_heap.size()) {
        return max_heap.top();
    } else {
        return min_heap.top();
    }
}

void push(int n) {
    if (!max_heap.size() && !min_heap.size()) {
        max_heap.push(n);
    } else if (n > mid()) {
        if (min_heap.size() > max_heap.size()) {
            int prev_min = min_heap.top();
            min_heap.pop();
            max_heap.push(prev_min);
        }
        min_heap.push(n);
    } else {
        if (max_heap.size() > min_heap.size()) {
            int prev_max = max_heap.top();
            max_heap.pop();
            min_heap.push(prev_max);
        }
        max_heap.push(n);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0;
    cin >> n;

    while (n-- > 0) {
        int next_num = 0;
        cin >> next_num;
        push(next_num);
        cout << mid() << '\n';
    }
    return 0;
}