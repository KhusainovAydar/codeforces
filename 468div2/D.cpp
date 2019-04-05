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

// oxxxy vseravno pobedil

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int NMAX = 100005;

vector<int> g[NMAX];
int ans[NMAX];
int n;
int dp[NMAX];

void dfs(int v, int p) {
    for (auto t : g[v]) {
        if (t == p) continue;
        dp[t] = dp[v] + 1;
        dfs(t, v);
    }
}


int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
//    freopen("lca2.in", "r", stdin);
//    freopen("lca2.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        x--;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    dp[0] = 1;
    dfs(0, -1);
    for (int i = 0; i < n; i++) {
        ans[dp[i]]++;
    }
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += ans[i] % 2;
    }
    cout << sum << endl;
}
