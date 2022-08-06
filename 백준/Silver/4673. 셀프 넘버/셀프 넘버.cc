#include <iostream>

using namespace std;

int d(int n) {
    int res = n;
    int q = n;
    while (q != 0) {
        res += q % 10;
        q = q / 10;
    }
    return res;
}

int main() {
    bool not_self_number[10000] = {false, };
    for (int i = 1; i <= 10000; i++) {
        int k = d(i);
        if (k <= 10000)
            not_self_number[k-1] = true;
    }
    for (int i = 0 ; i < 10000; i++) {
        if(!not_self_number[i])
            cout << i+1 << endl;
    }
    return 0;
}