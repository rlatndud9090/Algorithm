#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> memo(n, 0);

    int res = 0;
    for (int i = 0; i < n; i++) {
        memo[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (nums[j] < nums[i]) {
                memo[i] = max(memo[i], memo[j] + 1);
            }
        }
        res = max(res, memo[i]);
    }

    cout << res;
    return 0;
}