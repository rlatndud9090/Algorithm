#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool check_op(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')');
}

int get_push_prior(char ch) {
    if (ch == '+' || ch == '-')
        return 0;
    if (ch == '*' || ch == '/')
        return 1;
    if (ch == '(')
        return 2;
}

int get_in_prior(char ch) {
    if (ch == '+' || ch == '-')
        return 0;
    if (ch == '*' || ch == '/')
        return 1;
    if (ch == '(')
        return -1;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    string eq;
    cin >> eq;
    int len = eq.length();
    stack<char> char_stack;
    for (int i = 0; i < len; i++) {
        char ch = eq[i];
        if (!check_op(ch)) {
            cout << ch;
        } else if (ch == ')') {
            while (char_stack.top() != '(') {
                cout << char_stack.top();
                char_stack.pop();
            }
            char_stack.pop();
        } else {
            int cur_prior = get_push_prior(ch);
            while (!char_stack.empty() && cur_prior <= get_in_prior(char_stack.top())) {
                cout << char_stack.top();
                char_stack.pop();
            }
            char_stack.push(ch);
        }
    }
    while (!char_stack.empty()) {
        cout << char_stack.top();
        char_stack.pop();
    }
    return 0;
}