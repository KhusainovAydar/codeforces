#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int long long
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

// oxxxy vseravno pobedil

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("cinema.in", "r", stdin);
    //    freopen("cinema.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
//    int n = 50, m = 50;
//    int a[n][m];
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            a[i][j] = 0;
//        }
//    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll cnt0 = 0, cnt1 = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) cnt0++;
            else cnt1++;
        }
        ans += (1ll << cnt0) - 1;
        ans += (1ll << cnt1) - 1;
//        cout << ans << endl;
    }
    for (int j = 0; j < m; j++) {
        ll cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == 0) cnt0++;
            else cnt1++;
        }
        ans += (1ll << cnt0) - 1 - cnt0;
        ans += (1ll << cnt1) - 1 - cnt1;
    }
    cout << ans;
}
