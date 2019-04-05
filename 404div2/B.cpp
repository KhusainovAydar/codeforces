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
//#define ll ll
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool cmpL(pair<int, int> a, pair<int, int> b) {
    return a.fi < b.fi;
}

bool cmpR(pair<int, int> a, pair<int, int> b) {
    return a.se < b.se;
}
int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
//    freopen("farmer.in", "r", stdin);
//    freopen("farmer.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector< pair<int, int> > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    int m;
    cin >> m;
    vector< pair<int, int> > b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i].fi >> b[i].se;
    }
    sort(all(a), cmpL);
    sort(all(b), cmpR);
    int ans = 0;
    ans = max(ans, a.back().fi - b[0].se);
    sort(all(b), cmpL);
    sort(all(a), cmpR);
    ans = max(ans, b.back().fi - a[0].se);
    cout << ans;
}
