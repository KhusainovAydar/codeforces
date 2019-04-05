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

const int NMAX = 1e5 + 50;

vector<int> g[NMAX];
int col[NMAX];
bool dp[2][NMAX];
int n;

void dfs(int v, int p) {
    dp[0][v] = 0;
    dp[1][v] = 0;
    for (auto t : g[v]) {
        if (t == p) continue;
        dfs(t, v);
    }
    set<int> s;
    bool bad = false;
    for (auto t : g[v]) {
        if (t == p) continue;
        s.insert(col[t]);
        if (dp[1][t] == 0) {
            bad = true;
        }
    }
    if (!bad) {
        dp[0][v] = 1;
    } else {
        return;
    }
    if (s.size() == 1 && *s.begin() == col[v]) {
        dp[1][v] = 1;
    }
    if (s.size() == 0) {
        dp[1][v] = 1;
    }
}

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
    cin >> n;
    vector< pair<int, int> > v;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
        v.pb({a, b});
    }
    for (int i = 0; i < n; i++) {
        cin >> col[i];
    }
    for (int i = 0; i < v.size(); i++) {
        int a = v[i].fi, b = v[i].se;
        if (col[a] != col[b]) {
            dfs(a, -1);
            if (dp[0][a]) {
                cout << "YES" << endl << a + 1;
                return 0;
            }
            dfs(b, -1);
            if (dp[0][b]) {
                cout << "YES" << endl << b + 1;
                return 0;
            }
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    cout << 1;
}
