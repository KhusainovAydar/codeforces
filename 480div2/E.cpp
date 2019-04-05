#include <bits/stdc++.h>
#define times clock() * 1.0 / CLOCKS_PER_SEC
//#define pi 3.1415926535897932384626433832795
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int long long
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS
#define endl '\n'

// oxxxy vseravno pobedil

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int NMAX = 1000005;
const int K = 32;

vector<int> g[NMAX];
int dp[NMAX];
int up[K][NMAX];
int dist[NMAX];
bool used[NMAX];
int n, m;

void dfs(int v, int p) {
    dp[v] = v;
    up[0][v] = p;
    for (auto t : g[v]) {
        if (t == p) {
            continue;
        }
        dist[t] = dist[v] + 1;
        dfs(t, v);
        dp[v] = max(dp[v], dp[t]);
    }
}

int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled/input.txt", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled/output.txt", "w", stdout);
#else
    //        freopen("lca2.in", "r", stdin);
//    freopen("lca2.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    used[n] = true;
    dfs(n - 1, n);
    for (int i = 0; i < K; i++) {
        up[i][n] = n;
    }
    for (int i = 1; i < K; i++) {
        for (int j = 0; j < n; j++) {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
    int sum = 0;
    vector<int> ans;
    for (int v = n - 1; v >= 0; v--) {
        if (used[v]) continue;
        int u = v;
        int plus = 0;
        for (int i = K - 1; i >= 0; i--) {
            if (used[up[i][u]]) {
                continue;
            }
            u = up[i][u];
        }
        plus = dist[v] - dist[u] + 1;
        if (plus + sum <= n - m) {
            sum += plus;
            int go = v;
            while (go != u) {
                used[go] = true;
                go = up[0][go];
            }
            used[go] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            cout << i + 1 << ' ';
        }
    }
}
