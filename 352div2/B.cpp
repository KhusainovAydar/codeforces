#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'

using namespace std;

int mas[100];
int main() {
    string s;
    int n;
    cin >> n;
    if (n > 26) {
        cout << -1;
        return 0;
    }
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        mas[s[i] - 'a']++;
    }
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        if (mas[i] != 0) cnt++;
        ans += max(0, mas[i] - 1);
    }
    cout << ans;
}
