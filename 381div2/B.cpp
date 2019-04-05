#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
//#define pi 3.1415926535897932384626433832795
#define eps 0.0001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define pb push_back
#define MAX (MIN * (-1) + 100)
#define MOD 1000000007

using namespace std;

typedef long long ll;

bool used[10000];
int cnt[10000];

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);

#endif
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector< pair<int, int> > mas(m);
    for (int i = 0; i < m; i++) {
        cin >> mas[i].fi >> mas[i].se;
    }
    for (int i = 0; i < m; i++) {
        int l = mas[i].fi, r = mas[i].se;
        l--, r--;
        int sum = 0;
        for (int j = l; j <= r; j++) {
            sum += a[j];
        }
        if (sum > 0) {
            used[i] = 1;
        }
        if (sum > 0)
        for (int j = l; j <= r; j++) {
            cnt[j]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] * cnt[i];
    }
    cout << ans;
}
