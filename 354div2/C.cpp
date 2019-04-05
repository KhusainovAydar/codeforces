#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'b') {
            a[i + 1] = a[i] + 1;
        } else a[i + 1] = a[i];
        if (s[i] == 'a') {
            b[i + 1] = b[i] + 1;
        } else b[i + 1] = b[i];
    }
    int maxxa = 1, maxxb = 1;
    int l = 1, r = 1;
    while (r <= n) {
        if (a[r] - a[l - 1] <= k) {
            maxxa = max(r - l + 1, maxxa);
            //cout << a[r] << ' ' << a[l] << ' ' << l << ' ' << r << ' ' << r - l + 1 << endl;
            r++;
        } else {
            //cout << a[r] << ' ' << a[l] << ' ' << l << ' ' << r << ' ' << r - l + 1 << endl;
            l++;
            maxxa = max(r - l + 1, maxxa);
        }
    }
    l = 1, r = 1;
    while (r <= n) {
        if (b[r] - b[l - 1] <= k) {
            maxxb = max(r - l + 1, maxxb);
            r++;
        } else {
            l++;
            maxxb = max(r - l + 1, maxxb);
        }
    }
    cout << max(maxxa, maxxb);

}
