#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable : 4996)

using namespace std;

long long n, a, b, c;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//freopen("tests.txt", "r", stdin);

	cin >> n >> a >> b >> c;

	if (n % 4 == 0) {
		cout << 0;
		return 0;
	}

	if (n % 4 == 1) {
		cout << min(3 * a, min(b + a, c));
		return 0;
	}
	if (n % 4 == 2) {
		cout << min(2 * a, min(b, 2 * c));
		return 0;
	}
	if (n % 4 == 3) {
		cout << min(a, min(b + c, 3 * c));
		return 0;
	}
	return 0;
}
