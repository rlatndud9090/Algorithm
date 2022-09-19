#include <math.h>

#include <iostream>
#include <vector>

using namespace std;

class BigInt {
   public:
    BigInt() {
        for (int i = 0; i < 31; i++) {
            digit[i] = 0;
        }
    }

    void setOne() { digit[0] = 1; }
    BigInt operator+(BigInt& bi) {
        for (int i = 0; i < 30; ++i) {
            digit[i] += bi.digit[i];
            digit[i + 1] += digit[i] / 10;
            digit[i] %= 10;
        }
        return *this;
    }
    void print() {
        bool start = false;
        for (int i = 30; i >= 0; i--) {
            if (digit[i] != 0) {
                start = true;
            }
            if (start) {
                printf("%d", digit[i]);
            }
        }
    }

   private:
    int digit[31];
};

BigInt pascal_triangle[101][101];

int main() {
    // freopen("input.txt", "r", stdin);

    int n, m = 0;
    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                pascal_triangle[i][j].setOne();
            else if (i > 0) {
                pascal_triangle[i][j] = pascal_triangle[i - 1][j - 1] + pascal_triangle[i - 1][j];
            }
        }
    }

    pascal_triangle[n][m].print();
    return 0;
}