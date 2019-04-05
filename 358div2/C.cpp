#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define int long long 
#define pb push_back
#define mp make_pair
#define INF 1000000000
#define pi 3.14159265359

using namespace std;

typedef long long ll;

int n;
int num[100050];
vector< vector< pair <int, int> > > g;
bool used[100050];
int cnt;

void dfs(int v, int dist, int minn) {
	used[v] = true;
	//cout << v + 1 << ' ' << num[v] << ' ' << dist << ' ' << minn << ' ' << dist - minn << endl << endl;
	if (num[v] < dist - minn) {
		//cout << v + 1 << endl;
		//cout << num[v] << ' ' << dist << ' ' << minn << endl;
		return ;
	} 
	cnt++;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i].fi;
		if (!used[to]) {
			dfs(to, dist + g[v][i].se, min(minn, dist));
		}
	}
}

main() {
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	#if __APPLE__ 
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 1; i < n; i++) {
		int c, p;
		cin >> c >> p;
		g[c - 1].pb({i, p});
		g[i].pb({c - 1, p});
	}
	dfs(0, 0, 0);
	cout << n - cnt;
}
