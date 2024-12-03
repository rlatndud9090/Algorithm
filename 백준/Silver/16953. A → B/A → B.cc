#include <iostream>

using namespace std;

int A, B;

void calcReverse(int number, int count) {
  if (number < A) {
    // 연산 결과 A보다 작아졌다면 불가능
    cout << -1;
    return;
  }
  if (number == A) {
    // A에 도달했을 때 count를 출력하고 return
    cout << ++count;
    return;
  }
  if (number % 2 == 0) {
    // 짝수인 경우 2로 나누어본다.
    calcReverse(number / 2, ++count);
  } else if (number % 10 == 1) {
    // 끝자리가 1이라면, 1을 제거해본다.
    calcReverse(number / 10, ++count);
  } else {
    // 끝자리가 1이 아닌 홀수는 만들어낼 수 없음.
    cout << -1;
  }
}

int main() {
  cin >> A >> B;

  calcReverse(B, 0);
}