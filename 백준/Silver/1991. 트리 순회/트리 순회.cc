#include <iostream>
#include <vector>

using namespace std;

int get_index(char ch) {
    return (int)(ch - 'A' + 1);
}

char get_char(int i) {
    return (char)(i-1) + 'A';
}

void print_pre(int idx, vector<int>& first_child, vector<int>& second_child) {
    cout << get_char(idx);
    if (first_child[idx] != 0) {
        print_pre(first_child[idx], first_child, second_child);
    }
    if (second_child[idx] != 0) {
        print_pre(second_child[idx], first_child, second_child);
    }
}

void print_mid(int idx, vector<int>& first_child, vector<int>& second_child) {
    if (first_child[idx] != 0) {
        print_mid(first_child[idx], first_child, second_child);
    }
    cout << get_char(idx);
    if (second_child[idx] != 0) {
        print_mid(second_child[idx], first_child, second_child);
    }
}

void print_post(int idx, vector<int>& first_child, vector<int>& second_child) {
    if (first_child[idx] != 0) {
        print_post(first_child[idx], first_child, second_child);
    }
    if (second_child[idx] != 0) {
        print_post(second_child[idx], first_child, second_child);
    }
    cout << get_char(idx);
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> first_child(n + 1, 0);
    vector<int> second_child(n + 1, 0);

    for (int i = 0; i < n; i++) {
        char node, first, second;
        cin >> node >> first >> second;
        int node_idx = get_index(node);
        int first_idx = first == '.' ? 0 : get_index(first);
        int second_idx = second == '.' ? 0 : get_index(second);
        first_child[node_idx] = first_idx;
        second_child[node_idx] = second_idx;
    }

    print_pre(get_index('A'), first_child, second_child);
    cout << '\n';
    print_mid(get_index('A'), first_child, second_child);
    cout << '\n';
    print_post(get_index('A'), first_child, second_child);
    return 0;
}