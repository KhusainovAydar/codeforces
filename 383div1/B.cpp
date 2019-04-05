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
#define MIN -2147483648
#define pb push_back
#define MAX (MIN * (-1) + 100)
#define MOD 1000000007

using namespace std;

typedef long long ll;

int n, m, x;

const int NMAX = 3005;

vector<int> g[NMAX];

int w[NMAX], b[NMAX];

ll dp[NMAX][NMAX];
bool dpus[NMAX][NMAX];
bool used[NMAX];
vector<int> push;
int cnt;

int W, B;
vector< vector<int> > comp;

void dfs(int v) {
    used[v] = 1;
    W += w[v];
    B += b[v];
    for (auto t : g[v]) {
        if (!used[t]) {
            dfs(t);
        }
    }
    push.push_back(v);
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#endif
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cnt = n;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        cnt++;
        W = 0;
        B = 0;
        push.clear();
        dfs(i);
        w[cnt] = W;
        b[cnt] = B;
        push.push_back(cnt);
        comp.push_back(push);
    }
    for (int i = 0; i < comp.size(); i++) {
        dpus[i][0] = 1;
    }
    for (int i = 0; i < comp.size(); i++) {
        for (int j = 0; j <= x; j++) {
            for (int y = 0; y < comp[i].size(); y++) {
                int id = comp[i][y];
                if (j + w[id] <= x && dpus[i][j]) {
                    dp[i + 1][j + w[id]] = max(dp[i + 1][j + w[id]], dp[i][j] + b[id]);
                    dpus[i + 1][j + w[id]] = 1;
                }
                if (dpus[i][j]) {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                    dpus[i + 1][j] = 1;
                }
            }
        }
    }
    ll maxx = 0;
    for (int i = 0; i <= comp.size(); i++) {
        for (int j = 0; j <= x; j++) {
            maxx = max(maxx, dp[i][j]);
        }
    }
    cout << maxx;
}
