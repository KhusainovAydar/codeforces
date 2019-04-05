#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int main() {
	#ifdef __APPLE__ 
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout);
	#endif
	int cnt = 0;
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	k--;
	if (a[k] == 1) cnt++;
	for (int i = 1; i < n; i++) {
		if (k - i >= 0 && k + i < n) {
			if (a[k - i] == a[k + i] && a[k - i] == 1) cnt += 2;
		}
		if (k - i < 0 && k + i < n) {
			if (a[k + i] == 1) cnt++;
		}
		if (k - i >= 0 && k + i >= n) {
			if (a[k - i] == 1) cnt++;
		}
	}
	cout << cnt;
}
