#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void tracking(vector<vector<char>>& board, int alphBit, int x, int y, int r, int c, int& max_distance, int call_count) {
    call_count++;
    max_distance = max(max_distance, call_count);
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        // valid한 방향에 대해 나아갈 수 있는지 체크.
        if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
            auto next_alph_bit = board[nx][ny] - 'A';
            // 더 나아갈 수 있으려면, 지금까지 지나온 알파벳과 겹치지 않아야 함.
            if (!(alphBit & (1<<next_alph_bit))) {
                tracking(board, alphBit + (1<<next_alph_bit), nx, ny, r, c, max_distance, call_count); // 더 나아가기.
            }
        }
    }
}

int main() {
    // 입력 단계
    int r, c = 0;
    cin >> r >> c;
    vector<vector<char>> board(r, vector<char>(c, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }

    int max_distance = 0; // 가장 멀리 간 거리를 저장
    int alphBit = 0; // 지나온 알파벳을 저장할 bit 값
    alphBit += 1<<(board[0][0] - 'A');

    tracking(board, alphBit, 0, 0, r, c, max_distance, 0); // 재귀 함수로 DFS 구현

    cout << max_distance;
}