#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define mp make_pair
#define INF 1000000000000
#define pi 3.14159265359
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

const int NMAX = 505;

bool dp[NMAX][NMAX][NMAX];
int n;
int a[NMAX];

void kek (int i, int sum, int psum) {
	if (i == n) {
		dp[i][sum][psum] = 1;
	} else {
		if (dp[i][sum][psum]) return;
		dp[i][sum][psum] = 1;
		kek(i + 1, sum, psum);
		if (sum + a[i] < NMAX) {
			kek(i + 1, sum + a[i], psum);
			if (psum + a[i] < NMAX) {
				kek(i + 1, sum + a[i], psum + a[i]);
			}
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
	int k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	kek(0, 0, 0);
	vector<int> ans;
	for (int i = 0; i <= k; i++) {
		if (dp[n][k][i]) ans.pb(i);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
}
