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
    //    freopen("burrow.in", "r", stdin);
//    freopen("burrow.out", "w", stdout);
#endif
    int t;
    cin >> t;
    ll KEK = sqrt(1000000000);
    KEK++;
    while (t--) {
        ll x;
        cin >> x;
        for (ll d = 1; ; d++) {
            ll kor = (ll)sqrt(d * d + x);
            if (kor * kor == d * d + x) {
                ll n = kor;
                ll L = 1, R = n;
                while (R - L > 1) {
                    ll m = (L + R) >> 1;
                    if (n / m <= d) {
                        R = m;
                    } else {
                        L = m;
                    }
                }
                if (n / R == d) {
                    cout << n << ' ' << R << endl;
                    break;
                }
            }
            if (d > 50000) {
                cout << -1 << endl;
                break;
            }
        }
    }
}
