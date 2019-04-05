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
	cin >> n >> h;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
}
void kek () {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > h) cnt++;
		cnt++;
	}
	cout << cnt;
}

int main() {
    #ifdef __APPLE__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    init();
    kek();
}
