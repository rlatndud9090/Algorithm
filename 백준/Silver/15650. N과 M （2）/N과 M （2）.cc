#include <iostream>
#include <vector>

using namespace std;

void select_num(vector<int>& seq, int n, int m, int idx) {
    if (idx == m) {
        for (int i = 0; i < m; i++) {
            cout << seq[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = seq[idx-1] + 1; i <= n; i++) {
        vector<int> new_seq(seq);
        new_seq[idx] = i;
        select_num(new_seq, n, m, idx + 1);
    }
}

int main() {
    int n, m = 0;
    cin >> n >> m;

    vector<int> seq(m, 0);
    for (int i = 1; i <= n; i++) {
        seq[0] = i;
        select_num(seq, n, m, 1);
    }
    return 0;
}