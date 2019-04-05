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

bool cmp(pair<int, int> a, pair<int, int> b) {
    return (a.se - a.fi) < (b.se - b.fi);
}
int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< pair<int, int> > a(m);
    int cnt = 1000000;
    for (int i = 0; i < m; i++) {
        cin >> a[i].fi >> a[i].se;
        cnt = min(cnt, a[i].se - a[i].fi);
    }
    cnt++;
    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
        cout << i % cnt << ' ';
    }
}
