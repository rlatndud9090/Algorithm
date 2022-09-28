#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_pre_order(int start, int end, int post_start, int post_end, vector<int>& in_order, vector<int>& post_order) {
    if (start >= end) {
        return;
    }
    if (end - start == 1) {
        cout << in_order[start] << ' ';
        return;
    }
    auto root_iter = find(in_order.begin() + start, in_order.begin() + end, post_order[post_end-1]);
    int root_index = (int)(root_iter - in_order.begin());
    int left_length = root_index - start;
    // print root
    cout << post_order[post_end-1] << ' ';
    // print left
    print_pre_order(start, root_index, post_start, post_start + left_length, in_order, post_order);
    // print right
    print_pre_order(root_index + 1, end, post_start + left_length, post_end-1, in_order, post_order);
}

int main() {
    int n;
    cin >> n;
    vector<int> in_order(n);
    vector<int> post_order(n);
    for (int i = 0; i < n; i++) {
        cin >> in_order[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> post_order[i];
    }
    print_pre_order(0, n, 0, n, in_order, post_order);
}