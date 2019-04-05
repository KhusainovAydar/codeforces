#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000
#define y1 kek
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

bool used[100005];

int main() {
    ios_base::sync_with_stdio(false);
    srand((unsigned int)time(NULL));
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    vector< pair<int, pair<int, int> > > v;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, {b, c}});
    }
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        used[a] = true;
    }
    ll ans = INT_MAX;
    for (int i = 0; i < v.size(); i++) {
        ll a = v[i].fi, b = v[i].se.fi, c = v[i].se.se;
        if (used[a] && !used[b]) {
            ans = min(ans, c);
        }
        if (used[b] && !used[a]) {
            ans = min(ans, c);
        }
    }
    if (ans == INT_MAX) {
        cout << -1;
    } else {
        cout << ans;
    }
}
