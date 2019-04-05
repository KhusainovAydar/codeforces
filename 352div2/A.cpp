#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;
    string s = "";
    for (int i = 1; i <= n; i++) {
        int x = i;
        string ans = "";
        while (x > 0) {
            ans += (x % 10) + '0';
            x /= 10;
        }
        reverse(ans.begin(), ans.end());
        s += ans;
    }
    cout << s[n - 1];
}
