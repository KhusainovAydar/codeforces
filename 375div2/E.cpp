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

const int NMAX = 250;
int cnt[NMAX];
int t, n, m;
vector< vector<int> > g;
bool e[NMAX][NMAX];
vector<int> ans;
bool used[NMAX][NMAX];
int in[NMAX], out[NMAX];

void dfs(int v) {
    for (auto t : g[v]) {
        if (e[v][t]) {
            e[v][t] = 0;
            e[t][v] = 0;
            cnt[v]--;
            cnt[t]--;
            dfs(t);
            break;
        }
    }
    ans.push_back(v);
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
    //#else
    //    freopen("distances.in", "r", stdin);
    //    freopen("distances.out", "w", stdout);
#endif
    cin >> t;
    for (int id = 0; id < t; id++) {
        memset(cnt, 0, sizeof(cnt));
        g.clear();
        cin >> n >> m;
        ans.clear();
        g.resize(n + 1);
        for (int i = 0; i < NMAX; i++) {
            memset(e[i], 0, sizeof(e[i]));
            memset(used[i], 0, sizeof(used[i]));
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            used[a][b] = 1;
            used[b][a] = 1;
            g[a].push_back(b);
            g[b].push_back(a);
            e[a][b] = 1;
            e[b][a] = 1;
            cnt[a]++;
            cnt[b]++;
        }
        for (int i = 0; i < n; i++) {
            if (cnt[i] % 2) {
                e[n][i] = 1;
                e[i][n] = 1;
                g[n].push_back(i);
                g[i].push_back(n);
                cnt[i]++;
            }
        }
        vector< pair<int, int> > ANS;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > 0) {
                ans.clear();
                dfs(i);
                for (int j = 1; j < ans.size(); j++) {
                    if (used[ans[j]][ans[j - 1]]) {
                        ANS.push_back({ans[j - 1], ans[j]});
                    }
                }
            }
        }
        for (int i = 0; i < NMAX; i++) {
            memset(used[i], 0, sizeof(used[i]));
        }
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        int kek = 0;
        for (int i = 0; i < ANS.size(); i++) {
            out[ANS[i].fi]++;
            in[ANS[i].se]++;
        }
        for (int i = 0; i < n; i++) {
            if (in[i] == out[i])
                kek++;
        }
        cout << kek << endl;
        for (int i = 0; i < ANS.size(); i++) {
            cout << ANS[i].fi + 1 << ' ' << ANS[i].se + 1 << endl;
        }
    }
}
