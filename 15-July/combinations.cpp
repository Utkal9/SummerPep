#include <iostream>
using namespace std;

int solve(int index, string &s) {

    // Successfully decoded whole string
    if (index == s.length())
        return 1;

    // String starting with 0 is invalid
    if (s[index] == '0')
        return 0;

    // Take one digit
    int ways = solve(index + 1, s);

    // Take two digits if valid
    if (index + 1 < s.length()) {

        int num = (s[index] - '0') * 10 + (s[index + 1] - '0');

        if (num >= 10 && num <= 26)
            ways += solve(index + 2, s);
    }

    return ways;
}

int combination(int n, string s) {

    return solve(0, s);
}

int main() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    cout << combination(n, s);

    return 0;
}