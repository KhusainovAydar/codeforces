#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define mp make_pair
#define INF 1000000000000
#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

const int NMAX = 1e3 + 2, KMAX = 11 + 2, endMAX = 2;

int dp[NMAX][NMAX][KMAX][endMAX];

int main() {
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	#if __APPLE__ 
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, m, k;
	cin >> n >> m >> k;
	string a, b;
	cin >> a >> b;
	//a = '(' + a;
	//b = ')' + b;
	for (int cnt = 1; cnt <= k; cnt++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j][cnt][0] = max(max(dp[i - 1][j][cnt][0], dp[i - 1][j][cnt][1]), max(dp[i][j - 1][cnt][0], dp[i][j - 1][cnt][1]));
				if (a[i - 1] == b[j - 1]) {
					dp[i][j][cnt][1] = max(dp[i - 1][j - 1][cnt][1] + 1, dp[i - 1][j - 1][cnt - 1][0] + 1);
				}
			}
		}
	}
	cout << max(dp[n][m][k][0], dp[n][m][k][1]);
}
