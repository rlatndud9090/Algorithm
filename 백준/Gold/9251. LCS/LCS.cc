#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string first_str, second_str;
    cin >> first_str >> second_str;
    int first_len = first_str.length();
    int second_len = second_str.length();
    auto first_chars = first_str.c_str();
    auto second_chars = second_str.c_str();
    vector<vector<int>> lcs(first_len, vector<int>(second_len, 0));
    for (int i = 0; i < first_len; i++) {
        for (int j = 0; j < second_len; j++) {
            if (first_chars[i] == second_chars[j]) {
                lcs[i][j] = i == 0 || j == 0 ? 1 : lcs[i - 1][j - 1] + 1;
            } else {
                lcs[i][j] = max(i == 0 ? 0 : lcs[i - 1][j], j == 0 ? 0 : lcs[i][j - 1]);
            }
        }
    }
    cout << lcs[first_len-1][second_len-1];
    return 0;
}