#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<long long> values;

void findPair() {
  int left = 0;
  int right = values.size() - 1;

  int res_left = left;
  int res_right = right;
  long long min_sum = INFINITY;

  while (left < right) {
    long long cur_sum = values[left] + values[right];
    if (abs(cur_sum) < abs(min_sum)) {
      min_sum = cur_sum;
      res_left = left;
      res_right = right;
    }
    if (cur_sum < 0) {
      // 음수 절대값이 더 크다 -> 음수 절대값을 낮춰서 0에 더 가깝게
      left++;
    } else {
      // 양수 절대값이 더 크다 -> 양수 절대값을 낮춰서
      right--;
    }
  }
  cout << values[res_left] << " " << values[res_right];
}


int main() {
  cin >> N;
  values.resize(N);
  for (int i = 0 ; i < N; i++) {
    cin >> values[i];
  }

  findPair();
  return 0;
}