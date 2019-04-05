#include <bits/stdc++.h>
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
//    freopen("snowmen.in", "r", stdin);
//    freopen("snowmen.out", "w", stdout);
#endif
    ld k, d, t;
    cin >> k >> d >> t;
    if ((ll)k % (ll)d == 0) {
        d = k;
    } else {
        d = (ll)(k / d) * d + d;
    }
    ld L = 0, R = 5 * t;
    for (int i = 0; i < 10000; i++) {
        ld M = (L + R) * 0.5;
        ld cnt = (ll)(M / d) + 1;
        ld cur = cnt * k;
        if ((ll)(M / d) * d + k >= M) {
            cur -= -(M - ((ll)(M / d) * d + k));
        }
        if ((cur + M) >= 2 * t) {
            R = M;
        } else {
            L = M;
        }
    }
    cout.precision(20);
    cout << R;
}
