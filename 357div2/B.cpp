#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define mp make_pair
#define INF 1000000000000
#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
#define double long double
#define int ll
using namespace std;

typedef long long ll;

main() {
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	#if __APPLE__ 
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	for (int a = 0; ; a++) {
		for (int b = 0; ; b++) {
			if (a * 1234567 + b * 123456 <= n) {
				if ((n - a * 1234567 - b * 123456) % 1234 == 0) {
					cout << "YES";
					return 0;
				}
			} else break;
		}
		if (a * 1234567 > n) break;
	}
	cout << "NO";
}
