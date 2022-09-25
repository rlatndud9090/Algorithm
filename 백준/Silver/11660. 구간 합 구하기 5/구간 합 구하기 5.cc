#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> rect_sum(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int num;
            cin >> num;
            int upper = i == 1? 0 : rect_sum[i-1][j];
            int left = j == 1? 0 : rect_sum[i][j-1];
            int overlap = i == 1 || j == 1 ? 0 : rect_sum[i-1][j-1];
            rect_sum[i][j] = num + upper + left - overlap;
        }
    }
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int big_rect = rect_sum[x2][y2];
        int upper_rect = x1 > 1? rect_sum[x1-1][y2] : 0;
        int left_rect = y1 > 1? rect_sum[x2][y1-1] : 0;
        int overlap_rect = x1 > 1 && y1 > 1 ? rect_sum[x1-1][y1-1] : 0;
        int result = big_rect - upper_rect - left_rect + overlap_rect;
        cout << result << '\n';
    }
    return 0;
}