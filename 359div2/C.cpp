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

int cnth, cntm, anss, n, m;

set <int> nums;
int lim = 0;
string a, b;
int ans = 0;

string kek;

void rec(int cur, bool s) {
    if (cur == (int) a.size()) {
        s = 0;
    }
    if (cur < (int) a.size()) {
        if (s) {
            for (int i = 0; i < 7; i++) {
                if (!nums.count(i)) {
                    nums.insert(i);
                    kek += (i + '0');
                    rec(cur + 1, s);
                    kek.pop_back();
                    nums.erase(i);        
                }
            }
        } else {
            if (!nums.count(a[cur] - '0')) {
                int i = a[cur] - '0';
                nums.insert(i);
                kek += (i + '0');
                rec(cur + 1, 0);
                kek.pop_back();
                nums.erase(i);
            }
            for (int i = 0; i < (a[cur] - '0'); i++) {
                if (!nums.count(i)) {
                    nums.insert(i);
                    kek += (i + '0');
                    rec(cur + 1, 1);
                    kek.pop_back();
                    nums.erase(i);
                }
            }
        }
    } else if (cur < (int) b.size()) {
        if (s) {
            for (int i = 0; i < 7; i++) {
                if (!nums.count(i)) {
                    nums.insert(i);
                    kek += (i + '0');
                    rec(cur + 1, s);
                    kek.pop_back();
                    nums.erase(i);        
                }
            }
        } else {
            if (!nums.count(b[cur] - '0')) {
                int i = b[cur] - '0';
                nums.insert(i);
                kek += (i + '0');
                rec(cur + 1, 0);
                kek.pop_back();
                nums.erase(i);
            }
            for (int i = 0; i < (b[cur] - '0'); i++) {
                if (!nums.count(i)) {
                    nums.insert(i);
                    kek += (i + '0');
                    rec(cur + 1, 1);
                    kek.pop_back();
                    nums.erase(i);
                }
            }
        }
    } else {
        ans++;
        //cout << kek << endl;
    }
}

int nemay(int n, int m) {
	a = "";
	b = "";
	ans = 0;
	lim = 0;
	kek = "";
	nums.clear();
	n--, m--;
    if (n == 0) {
        a = "0";
    }
    while (n > 0) {
        a += (n % 7 + '0');
        n /= 7;
    }
    if (m == 0) {
        b = "0";
    }
    while (m > 0) {
        b += (m % 7 + '0');
        m /= 7;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    b = a + b;
    rec(0, 0);
    return ans;
}

int bpow(int x, int n) {
    long long y = x;
    int res = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1)
            res = res * y;
        y = y * y;
    }
    return res;
}

void perm (int id, vector<bool> used, int sum) {
	if (id <= cntm){
		int lol = bpow(7, id - 1);
		for (int i = 0; i < 7; i++) {
			int ke = i * lol;
			if (!used[i] && ke + sum < m) {
				used[i] = true;
				perm(id + 1, used, sum + ke);
				used[i] = false;
			}
		} 
	} else {
		anss++;
		return ;
	}
}
void perh (int id, vector<bool> used, int sum) {
	if (id <= cnth){
		int lol = bpow(7, id - 1);
		for (int i = 0; i < 7; i++) {
			int ke = i * lol;
			if (!used[i] && ke + sum < n) {
				used[i] = true;
				perh(id + 1, used, sum + ke);
				used[i] = false;
			}
		} 
	}else {
		perm(1, used, 0);
		return ;
	}
}

int may (int n, int m) {
	cnth = 0, cntm = 0;
	int x = n;
	while (x > 0) {
		cnth++;
		x /= 7;
	}
	x = m;
	while (x > 0) {
		cntm++;
		x /= 7;
	}
	//cout << cnth << ' ' << cntm << endl << endl;
	vector<bool> used(7, false);
	perh(1, used, 0);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	#if __APPLE__ 
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	cin >> n >> m;
	cout << nemay(n, m);
}
