
 #include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = INT_MAX;
    for (int i = 1; i < n; i++) {
        if (s[i] == 'L' && s[i - 1] == 'R') {
            ans = min(ans, (a[i] - a[i - 1]) / 2);
        }
    }
    cout << (ans == INT_MAX ? -1 : ans);
}
