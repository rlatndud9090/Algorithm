#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> stickers(2, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            cin >> stickers[0][i];
        }
        for (int i = 0; i < n; i++) {
            cin >> stickers[1][i];
        }
        /** 각 column에서 위, 아래 스티커중 하나만 뗄 수 있다. 그리고 다음 column에서는
         * 이전에 선택한 위/아래 와 반대로만 가능
         * 즉 위/아래를 선택하는 색칠 문제 -> DP로 풀면 됨
         */
        vector<vector<int>> max_score(3, vector<int>(n,0));
        max_score[0][0] = stickers[0][0];
        max_score[1][0] = stickers[1][0];
        for (int i = 1; i < n; i++) {
            max_score[0][i] = max(max_score[1][i-1], max_score[2][i-1]) + stickers[0][i];
            max_score[1][i] = max(max_score[0][i-1], max_score[2][i-1]) + stickers[1][i];
            max_score[2][i] = max(max_score[0][i-1], max(max_score[1][i-1], max_score[2][i-1]));
        }
        cout << max(max_score[0][n-1], max(max_score[1][n-1], max_score[2][n-1])) << '\n';
    }
    return 0;
}