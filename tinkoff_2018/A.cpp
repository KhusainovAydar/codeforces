#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int long long
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
//    freopen("cinema.in", "r", stdin);
//    freopen("cinema.out", "w", stdout);
#endif
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    int minn = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        minn = min(minn, a[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] - minn) % k) {
            cout << -1;
            return 0;
        }
        ans += (a[i] - minn) / k;
    }
    cout << ans;
}
