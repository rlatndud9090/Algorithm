#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> numbers;
vector<int> sequence;
vector<bool> checked;

void backtrack(int depth) {
    if (depth == M) {
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }
    int prev = -1;
    for (int i = 0; i < N; ++i) {
      if (prev != numbers[i] && checked[i] == false) {
        sequence.push_back(numbers[i]);
        checked[i] = true;

        backtrack(depth + 1);        

        sequence.pop_back();
        checked[i] = false;

        prev = numbers[i];
      }
    }
}

int main() {
    cin >> N >> M;

    numbers.resize(N);
    checked.resize(N, false);

    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    backtrack(0);

    return 0;
}