#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

bool prime(int x) {
	if (x == 2 || x == 3) return true;
	for (int i = 2; i < x; i++) {
		if (x % i == 0) 
			return false;
	}
	return true;
}

int main() {
	#ifdef __APPLE__ 
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout);
	#endif
	vector<int> kek;
	for (int i = 2; i <= 50; i++) {
		if (prime(i)) kek.pb(i);
	}
	kek.pb(4);
	kek.pb(9);
	kek.pb(25);
	kek.pb(49);
	int cnt = 0;
	for (int i = 0; i < kek.size(); i++) {
		cout << kek[i] << endl;
		string s;
		cin >> s;
		if (s == "yes") {
			cnt++;
			if (cnt == 2) {
				cout << "composite";
				return 0;
			}
		}
	}
	cout << "prime";
	return 0;
}
