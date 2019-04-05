#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define mp make_pair
using namespace std;
 
typedef long long ll;

const int NMAX = 266;

int p[NMAX];

void kek () {
	for (int i = '0'; i <= '9'; i++) {
		p[i] = i - '0';
	}
	for (char c = 'A'; c <= 'Z'; c++) {
		p[c] = c - 'A' + 10;
	}
	for (char c = 'a'; c <= 'z'; c++) {
		p[c] = c - 'a' + 36;
	}
	p['-'] = 62;
	p['_'] = 63;
}

const ll mod = 1e9 + 7;
int main() {
    #ifdef __APPLE__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll ans = 1;
	string s;
	cin >> s;
	kek();
	for (int i = 0; i < (int) s.size(); i++) {
		int cnt = 0;
		for (int a = 0; a < 64; a++) {
			for (int b = 0; b < 64; b++) {
				if ((a & b) == p[s[i]]) {
					cnt++;
				}
			}
		}
		ans *= cnt;
		ans %= mod;
	}
	cout << ans;
}
