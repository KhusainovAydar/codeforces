#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000000000
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll

using namespace std;

typedef long long ll;

const int NMAX = 55;

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#endif
    ll l1, r1, l2, r2, k;
    cin >> l1 >> r1 >> l2 >> r2 >> k;
    if (l2 > r1 || l1 > r2) {
        cout << 0;
        return 0;
    }
    ll sum = min(r1, r2) - max(l1, l2);
    if (sum < 0) {
        cout << 0;
        return 0;
    }
    if (k <= min(r1, r2) && k >= max(l1, l2)) {
        cout << sum;
    } else {
        cout << sum + 1;
    }
}
