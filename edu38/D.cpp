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

const int NMAX = 2 * 100005;

vector< pair<int, ll> > g[NMAX];
int n, m;
ll value[NMAX];
ll dp[NMAX];


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
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].push_back({b, c * 2});
        g[b].push_back({a, c * 2});
    }
    for (int i = 0; i < n; i++) {
        cin >> value[i];
        dp[i] = value[i];
    }
    set< pair<ll, int> > s;
    for (int i = 0; i < n; i++) {
        s.insert({dp[i], i});
    }
    while (s.size()) {
        auto t = *s.begin();
        int v = t.second;
        ll sum = t.first;
        for (auto u : g[v]) {
            int to = u.first;
            ll val = u.second;
            if (dp[to] > sum + val) {
                if (s.find({dp[to], to}) != s.end()) {
                    s.erase({dp[to], to});
                }
                dp[to] = sum + val;
                s.insert({dp[to], to});
            }
        }
        s.erase(t);
    }

    for (int i = 0; i < n; i++) {
        cout << dp[i] << ' ';
    }
}
