#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int n, m, p;
vector< vector< pair<ll, ll> > > g;
ll dp[505][505];


ll mas[500][500];
ll d[505][505];
queue< pair<ll, ll>  > q;

int dist(pair<int, int> a, pair<int, int> b) {
	return abs(a.fi - b.fi) + abs(a.se - b.se);
}

void bfs (int kek) {
	for (int i = 0; i < 500; i++) {
		for (int j = 0; j< 500; j++) {
			if (mas[i][j] != kek) {
				d[i + 1][j + 1] = INT_MAX;
			} else d[i + 1][j + 1] = dp[i + 1][j + 1];
		}
	}
	while (!q.empty()) {
		pair<int, int> v = q.front();
		q.pop();
		if (v.se + 1 <= m && d[v.fi][v.se + 1] > d[v.fi][v.se] + 1) {
			d[v.fi][v.se + 1] = d[v.fi][v.se] + 1;
			q.push({v.fi, v.se + 1});
		}
		if (v.fi + 1 <= n && d[v.fi + 1][v.se] > d[v.fi][v.se] + 1) {
			d[v.fi + 1][v.se] = d[v.fi][v.se] + 1;
			q.push({v.fi + 1, v.se});
		}
		if (v.se - 1 >= 1 && d[v.fi][v.se - 1] > d[v.fi][v.se] + 1) {
			d[v.fi][v.se - 1] = d[v.fi][v.se] + 1;
			q.push({v.fi, v.se - 1});
		}
		if (v.fi - 1 >= 1 && d[v.fi - 1][v.se] > d[v.fi][v.se] + 1) {
			d[v.fi - 1][v.se] = d[v.fi][v.se] + 1;
			q.push({v.fi - 1, v.se});
		}
	}
}
int main() {
	#ifdef __APPLE__ 
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout);
	#endif
	scanf("%d %d %d", &n, &m, &p);
	g.resize(p + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%lld", &mas[i][j]);
			g[mas[i][j]].pb({i + 1, j + 1});
			if (mas[i][j] == 1) {
				dp[i + 1][j + 1] = i + j;
			} else dp[i + 1][j + 1] = INT_MAX;
		}
	}
	for (int i = 2; i <= p; i++) {
		int o = (int) g[i].size() * g[i - 1].size();
		if (o <= n * m) {
			for (int y = 0; y < g[i].size(); y++) {
				for (int j = 0; j < g[i - 1].size(); j++) {
					dp[g[i][y].fi][g[i][y].se] = min(dp[g[i][y].fi][g[i][y].se], 
						dp[g[i - 1][j].fi][g[i - 1][j].se] + dist(g[i - 1][j], g[i][y]));
				}
			}
		} else {
			for (int y = 0; y < g[i - 1].size(); y++) {
				q.push({g[i - 1][y].fi, g[i - 1][y].se});
			}
			bfs(i - 1);
			for (int y = 0; y < g[i].size(); y++) {
				dp[g[i][y].fi][g[i][y].se] = d[g[i][y].fi][g[i][y].se];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mas[i][j] == p) {
				cout << dp[i + 1][j + 1];
				return 0;
			}
		}
	}
}
