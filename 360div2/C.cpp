#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define mp make_pair
#define INF 1000000000000
#define pi 3.14159265359
//#define double long double
using namespace std;

typedef long long ll;

const int NMAX = 1e5 + 5;
vector< vector<int> > g;
bool used[NMAX];
int color[NMAX];

void dfs (int v, int col) {
	used[v] = true;
	color[v] = col;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (color[to] == color[v]) {
			cout << -1;
			exit(0);
		}
		if (!used[to]) {
			dfs(to, ((col - 1) + 1) % 2 + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	#if __APPLE__ 
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i, 1);
		}
	}
	vector<int> ans1, ans2;
	for (int i = 0; i < n; i++) {
		if (color[i] == 1) {
			ans1.pb(i + 1);
		} 
		if (color[i] == 2) {
			ans2.pb(i + 1);
		}
	}
	cout << ans1.size() << endl;
	for (int i = 0; i < ans1.size(); i++) {
		cout << ans1[i] << ' ';
	}
	cout << endl;
	cout << ans2.size() << endl;
	for (int i = 0; i < ans2.size(); i++) {
		cout << ans2[i] << ' ';
	}
}
