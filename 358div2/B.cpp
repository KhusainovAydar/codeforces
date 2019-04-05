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
	while (cin >> n) {
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		a[0] = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] == a[i - 1]) continue;
			a[i] = a[i - 1] + 1;
		}
		cout << a.back() + 1 << endl;
	}
}
