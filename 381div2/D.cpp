#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
//#define pi 3.1415926535897932384626433832795
#define eps 0.0001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define pb push_back
#define MAX (MIN * (-1) + 100)
#define MOD 1000000007

using namespace std;

typedef long long ll;

const int NMAX = 2 * 1e5 + 5, K = 20;

int a[NMAX];
vector< pair<int, int> > g[NMAX];
int n;

int parent[NMAX];
ll dist[NMAX];
int ans[NMAX];
int dp[NMAX];
int tin[NMAX], tout[NMAX];
int go[K][NMAX];
int T = 1;

void dfs(int v, int p) {
    tin[v] = T++;
    for (auto t : g[v]) {
        if (t.fi == p) continue;
        parent[t.fi] = v;
        dist[t.fi] = dist[v] + t.se;
        dfs(t.fi, v);
    }
    tout[v] = T;
}

ll get_dist(int v, int u) {
    return dist[u] - dist[v];
}

bool anc(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

void dfs2(int v, int p, int cur) {
    for (auto t : g[v]) {
        if (t.fi == p) continue;
        dfs2(t.fi, v, cur);
        ans[v] += ans[t.fi] + dp[t.fi];
        //dp[t.fi] = 0;
    }
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        g[i].push_back({x, y});
        g[x].push_back({i, y});
    }
    dfs(0, -1);
    for (int i = 0; i < n; i++) {
        go[0][i] = parent[i] < 0 ? i : parent[i];
    }
    for (int i = 1; i < K; i++) {
        for (int j = 0; j < n; j++) {
            go[i][j] = go[i - 1][go[i - 1][j]];
        }
    }
    for (int i = 1; i < n; i++) {
        int v = i;
        for (int j = K - 1; j >= 0; j--) {
            //cerr << j << ' ' << go[j][v] << ' ' << a[i] << ' ' << get_dist(go[j][v], i) << ' ' << parent[v] << endl;
            if (get_dist(go[j][v], i) <= a[i]) {
                v = go[j][v];
            }
        }
        if (i != v) {
            dp[v]--;
            dp[i]++;
        }
    }
    dfs2(0, -1, 0);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}
