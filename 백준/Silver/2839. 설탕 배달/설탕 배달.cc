#include <iostream>

using namespace std;

void calc(int n) {
    int large = 0;  // 큰 봉투(5키로)

    // 최대한 5키로짜리를 많이 가져가본다. 실패하면 하나씩 줄여본다.
    large = n / 5;
    int left = n % 5;  // 5키로에 채우고 남은 양
    while (left % 3 != 0) {
        // 남은 양이 3키로 짜리로 정확히 담아질 때 까지, 5키로 봉투를 한개씩 빼본다.
        if (--large < 0) {
            // 5키로 봉투 갯수가 음수가 되면 불가능한 case이므로 -1 출력
            cout << -1 << endl;
            return;
        }
        left += 5;
    }
    // 3으로 나누는데 성공했다면 최종 갯수를 출력
    cout << (large + left / 3) << endl;
}

int main() {
    int n = 0;
    cin >> n;

    calc(n);
    return 0;  
}