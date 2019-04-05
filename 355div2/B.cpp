#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define mp make_pair
using namespace std;
 
typedef long long ll;

ll n, h, k, ans, i, j;
vector<int>a;

void init() {
	cin >> n >> h >> k;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
}
void kek () {
	ll ans = 0;
	ll i = 0, j = 0;
	while (i < n) {
		while (i < n && j + a[i] <= h) {
			j += a[i];
			i++;
		}
		j -= min(k, j);
		ans++;
		ans += j / k;
		j = j % k;
	}
	ans += (j + k - 1) / k;
	cout << ans;
}

int main() {
    #ifdef __APPLE__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    init();
    kek();
}
