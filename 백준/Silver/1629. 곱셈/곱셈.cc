#include <iostream>
using namespace std;
#define ll long long

ll get_pow(ll a, ll b, ll c) {
    if (b == 0)
        return 1;
    ll half_pow = get_pow(a, b/2, c);
    if (b % 2 == 0) {
        return half_pow % c * half_pow % c;
    } else {
        return half_pow % c * half_pow % c * (a % c) % c;
    }
}

int main() {
    ll a, b, c = 0;
    cin >> a >> b >> c;
    cout << get_pow(a, b, c);
    return 0;
}