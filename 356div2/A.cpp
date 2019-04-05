#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int mas[110];

int main() {
	#ifdef __APPLE__ 
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout);
	#endif
	int sum = 0;
	int minn = INT_MAX;
	for (int i = 0; i < 5; i++) {
		int x;
		cin >> x;
		sum += x;
		mas[x]++;
	}
	minn = sum;
	for (int i = 0; i < 110; i++) {
		if (mas[i] >= 2) {
			minn = min(minn, sum - min(mas[i], 3) * i);
		}
	}
	cout << minn;
}
