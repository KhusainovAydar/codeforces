#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000000000
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll

using namespace std;

typedef long long ll;

int cnt[27];

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    int n = (int)s.length();
    if (n < 26) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i <= n - 26; i++) {
        for (int j = 0; j < 27; j++) {
            cnt[j] = 0;
        }
        for (int j = i; j < i + 26; j++) {
            cnt[s[j] - 'A']++;
        }
        bool ch = true;
        for (int j = 0; j < 27; j++) {
            if (cnt[j] > 1) ch = false;
        }
        if (!ch) continue;
        for (int j = i; j < i + 26; j++) {
            if (s[j] == '?') {
                for (int y = 0; y < 26; y++) {
                    if (cnt[y] == 0) {
                        s[j] = char(y + 'A');
                        cnt[y]++;
                        break;
                    }
                }
            }
        }
        for (int k = 0; k < n; k++) {
            if (s[k] == '?') {
                s[k] = 'A';
            }
        }
        cout << s;
        return 0;
        break;
    }
    cout << -1;
    return 0;
}
