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

int used[101];

int main() {
	//ios_base::sync_with_stdio(false);
	srand(time(NULL));
	#if __APPLE__ 
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, d;
	cin >> n >> d;
	string a = "";
	for (int i = 0; i < n; i++) {
		a += '1';
	}
	int cnt = 0;
	int maxx = 0;
	for (int i = 0; i < d; i++) {
		string s;
		cin >> s;
		if (s != a) {
			cnt++;
		} else {
			cnt = 0;
		}
		maxx = max(maxx, cnt);
	}
	cout << maxx;
}
