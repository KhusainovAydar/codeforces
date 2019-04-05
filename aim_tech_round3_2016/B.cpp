#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define y1 kekkekekekkek
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;
int const INF = 1 << 30;

const int N = 123456, K = 20;

ll dist(ll a, ll b) {
    return abs(a - b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand((unsigned int)time(NULL));
    /*#if __APPLE__
     freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
     freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
     #endif*/
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 0;
        return 0;
    }
    sort(a.begin(), a.end());
    ll ans = LLONG_MAX;
    int cnt = 0;
    if (dist(a[cnt], x) <= dist(a[a.size() - 2 + cnt], x)) {
        ans = min(ans, dist(a[cnt], x) + dist(a[cnt], a[a.size() - 2 + cnt]));
        //cout << "KEK";
        //cout << ans << endl;
    } else {
        ans = min(ans, dist(a[a.size() - 2 + cnt], x) + dist(a[cnt], a[a.size() - 2 + cnt]));
    }
    cnt++;
    if (dist(a[cnt], x) <= dist(a[a.size() - 2 + cnt], x)) {
        ans = min(ans, dist(a[cnt], x) + dist(a[cnt], a[a.size() - 2 + cnt]));
        //cout << "LOH";
    } else {
        ans = min(ans, dist(a[a.size() - 2 + cnt], x) + dist(a[cnt], a[a.size() - 2 + cnt]));
    }
    cout << ans;
}
