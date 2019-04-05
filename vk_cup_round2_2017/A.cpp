#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int long long
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

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
    int n;
    cin >> n;
    ld p;
    cin >> p;
    vector< pair<ld, ld> > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
    }
    ld MAX = 10000000000;
    ld L = 0, R = MAX;
    for (int it = 0; it < 1000; it++) {
        ld M = (L + R) * 0.5;
        ld sum = p * M;
        for (int i = 0; i < n; i++) {
            if (v[i].se - v[i].fi * M < 0) {
                sum += v[i].se - v[i].fi * M;
            }
        }
        if (sum < 0) {
            R = M;
        } else {
            L = M;
        }
    }
    if (L == MAX) {
        cout << -1;
        return 0;
    }
    cout.precision(20);
    cout << L << endl;
}
