#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void select_num(vector<int>& seq, int n, int m, int idx, vector<int>& nums, set<int>& num_set) {
    if (idx == m) {
        for (int i = 0; i < m; i++) {
            cout << seq[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int num: num_set) {
        vector<int> new_seq(seq);
        set<int> new_set(num_set);
        new_seq[idx] = num;
        new_set.erase(num);
        select_num(new_seq, n, m, idx + 1, nums, new_set);
    }
}

int main() {
    int n, m = 0;
    cin >> n >> m;

    vector<int> nums(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    set<int> num_set(nums.begin(), nums.end());

    vector<int> seq(m, -1);
    select_num(seq, n, m, 0, nums, num_set);
    return 0;
}