#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define mp make_pair
#define INF 1000000000
#define pi 3.14159265359

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	#if __APPLE__ 
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	int cnt = 0;
	ll kek = 0;
	cin >> kek;
	for (int i =0; i < n; i++) {
		char c;
		cin >> c;
		if (c == '+') {
			ll d;
			cin >> d;
			kek += d;
		}
		if (c == '-') {
			ll d;
			cin >> d;
			if (d > kek) {
				cnt++;
			} else {
				kek -= d;
			}
		}
	}
	cout << kek << ' ' << cnt;

}
