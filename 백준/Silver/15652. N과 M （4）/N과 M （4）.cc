#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> resultVector;

void backtrack(int start, int depth) {
    if (depth == M) {
        for (int num : resultVector) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; ++i) {
        resultVector.push_back(i);
        backtrack(i, depth + 1);
        resultVector.pop_back();
    }
}

int main() {
    cin >> N >> M;

    backtrack(1, 0);

    return 0;
}