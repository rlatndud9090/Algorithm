#include <iostream>
#include <math.h>

using namespace std;

int checkPrime(int num) {
    // 1은 소수가 아님
    if (num == 1) return 0;
    // 해당 수의 제곱근 이하의 수로만 나누어 떨어지는지 확인하면 됨
    int sr = sqrt(num);
    for ( int i = 2 ; i <= sr ; i++)
        //나누어 떨어지는 경우(나머지가 0인 경우), 소수가 아니므로 0 return
        if ( num % i == 0)
            return 0;
    //어떠한 수로도 나누어 떨어지지 않을 경우 1 return
    return 1;
}

int main() {
    int n = 0;
    int count = 0;
    cin >> n;
    for (int i = 0; i < n ; i++) {
        int number = 0;
        cin >> number;
        //소수인 경우 count 1 증가
        count += checkPrime(number);
    }
    cout << count << endl;

    return 0;
}