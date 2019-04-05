#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
//#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int NMAX = 1050, K = 15;
int a[28];
int sum[NMAX][28];
ll dp[NMAX];

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("tram.in", "r", stdin);
//    freopen("tram.out", "w", stdout);
#endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '!' + s;
    for (int i = 0; i < 26; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            sum[i][j] = sum[i - 1][j];
        }
        sum[i][s[i] - 'a']++;
    }
    dp[0] = 1;
    int maxx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int cur[26];
            bool bad = false;
            for (int y = 0; y < 26; y++) {
                cur[y] = sum[i][y] - sum[j][y];
//                cout << cur[y] << ' ';
                if (cur[y] && i - j > a[y]) {
                    bad = true;
                }
                if (bad) break;
            }
            if (bad)
                continue;
            maxx = max(maxx, i - j);
            dp[i] += dp[j];
            dp[i] %= 1000000007;
        }
    }
    cout << dp[n] << endl;
    cout << maxx << endl;
    for (int i = 0; i <= n; i++) {
        dp[i] = 1000000000;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int cur[26];
            bool bad = false;
            for (int y = 0; y < 26; y++) {
                cur[y] = sum[i][y] - sum[j][y];
                if (cur[y] && i - j > a[y]) {
                    bad = true;
                }
            }
            if (bad) {
                continue;
            }
            if (dp[j] != 1000000000) {
                dp[i] = min(dp[j] + 1, dp[i]);
            }
        }
    }
    cout << dp[n];
}
