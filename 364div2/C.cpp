#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int used[10000];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!used[s[i]]) {
            used[s[i]] = true;
            cnt++;
        }
    }
    int minn = INT_MAX - 1;
    memset(used, 0, sizeof used);
    int ans = 0;
    int l = 0, r = 0;
    while (r < n) {
        if (ans < cnt || l == r) {
            if (!used[s[r]]) {
                used[s[r]]++;
                ans++;
                r++;
            } else {
                used[s[r]]++;
                r++;
            }
        } else {
            used[s[l]]--;
            l++;
            if (used[s[l - 1]] == 0) ans--;
        }
        if (ans >= cnt) {
            minn = min(r - l, minn);
        }
    }
    while(l < r) {
        used[s[l]]--;
        l++;
        if (used[s[l - 1]] == 0) ans--;
        if (ans >= cnt) {
            minn = min(r - l, minn);
        }
    }
    cout << minn;
}
