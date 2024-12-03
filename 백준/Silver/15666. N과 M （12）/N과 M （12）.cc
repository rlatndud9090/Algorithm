#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> numbers;
vector<int> sequence;

void backtrack(int start, int depth) {
    if (depth == M) {
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }
    for (auto it = numbers.begin() + start; it != numbers.end(); it++) {
        sequence.push_back(*it);

        backtrack(distance(numbers.begin(), it), depth + 1);        

        sequence.pop_back();
    }
}

int main() {
    cin >> N >> M;

    numbers.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());
    auto new_end = unique(numbers.begin(), numbers.end());
    numbers.erase(new_end, numbers.end());

    backtrack(0, 0);

    return 0;
}