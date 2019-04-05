#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000
#define y1 kek
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
#define double long double
//#define int ll
using namespace std;

typedef long long ll;

map<ll, bool> used;
map<ll, int> kek;

int main() {
    srand((unsigned int)time(NULL));
/*#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("minonpath.in", "r", stdin);
    freopen("minonpath.out", "w", stdout);
#endif*/
    int n;
    cin >> n;
    vector<int> a(n);
    used[1] = true;
    long long cur = 2;
    //cout << n << endl;
    while (cur < LLONG_MAX) {
        used[cur] = true;
        if (cur * 2 * 1ll > 2 * 1000000000) {
            break;
        } else cur *= 2;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        //cout << a[i] << endl;
        for (auto t : used) {
            int cnt = kek[t.fi - a[i]];
            if (cnt) {
                ans += (ll)cnt;
            }
        }
        kek[a[i]]++;
        //cout << i << endl;
    }
    cout << ans;
}
