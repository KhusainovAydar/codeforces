#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define mp make_pair
#define INF 1000000000000
#define pi 3.14159265359
//#define double long double
#define int ll
using namespace std;

typedef long long ll;

const int NMAX = 1e6 + 5;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

main() {
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	#if __APPLE__ 
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, k;
	cin >> n >> k;
	int z = 1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		z = gcd(x, k) * z / gcd(z, gcd(x, k));
	}
	if (z == k) cout << "Yes";
	else
	cout << "No";
	return 0;
}
