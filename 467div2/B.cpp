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

bool ch(ll x, ll p) {
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0 && i > p && x / i > p) {
            continue;
        } else if (x % i == 0) {
            return false;
        }
    }
    return true;
}

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
    int p, y;
    cin >> p >> y;
    for (ll i = y; i > p; i--) {
        if (ch(i, p)) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}
