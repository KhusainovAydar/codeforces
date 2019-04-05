#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 10000000
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll

using namespace std;

typedef long long ll;

int n, m;
vector< vector< pair<int, int> > > g;
int T;
int dp[5001][5001];
int pref[5001];
vector<int> ans;
int maxx = 0;
bool used[5001];
int kek[5001][5001];
int p = -1;

void dfs(int v) {
    used[v] = true;
    for (auto t : g[v]) {
        pref[t.fi]++;
        if (used[t.fi]) continue;
        dfs(t.fi);
    }
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//#if __APPLE__
//    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
//    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
////#else
////    freopen("pwgen.in", "r", stdin);
////    freopen("pwgen.out", "w", stdout);
//#endif
    cin >> n >> m >> T;
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].push_back({b, c});
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = T + 1;
        }
    }
    queue<int> q;
    q.push(0);
    dfs(0);
    dp[0][0] = 0;
    kek[0][0] = -1;
    while (q.size()) {
        int v = q.front();
        q.pop();
        for (auto t : g[v]) {
            pref[t.fi]--;
            for (int cnt = 0; cnt < n; cnt++) {
                if (dp[t.fi][cnt + 1] > dp[v][cnt] + t.se) {
                    dp[t.fi][cnt + 1] = dp[v][cnt] + t.se;
                    kek[t.fi][cnt + 1] = v;
                }
            }
            if (pref[t.fi] == 0) {
                q.push(t.fi);
            }
        }
    }
    int x = -1;
    for (int i = 0; i < n; i++) {
        if (dp[n - 1][i] <= T) {
            x = i;
        }
    }
    int last = n - 1;
    ans.push_back(last);
    while (kek[last][x] != -1) {
        last = kek[last][x];
        ans.push_back(last);
        x--;
    }
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (int i =0 ; i < (int)ans.size(); i++) {
        cout << ans[i] + 1 << ' ';
    }
}
