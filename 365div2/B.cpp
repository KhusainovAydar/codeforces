#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
//#define INF 1000000000
#define y1 kek
#define re return
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
#define int ll
using namespace std;

typedef long long ll;

bool term[100005];

 main() {
    srand((unsigned int)time(NULL));
    /*#if __APPLE__
     freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
     freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
     #endif*/
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(k);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> b[i];
        b[i]--;
        term[b[i]] = true;
    }
    ll ans = 0;
    ll sum1 = 0;
    for (int i = 0; i < n; i++) {
        if (term[i]) {
            sum1 += a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (term[i]) {
            ans += (sum - a[i]) * a[i];
        //    cout << ans << endl;
        }
    }
    //cout << b[0] << endl;
    vector<ll> preff(k, 0);
    preff[0] = a[b[0]];
    for (int i = 1; i < k; i++) {
        preff[i] = (preff[i - 1] + a[b[i]]);
    }
    //cout << sum1 << ' ' << preff[0] << endl;
    for (int i = 0; i < k; i++) {
       // cout << (sum1 - preff[i]) * a[b[i]] << endl;
        ans -= (sum1 - preff[i]) * a[b[i]];
    }
    for (int i = 1; i < n; i++) {
        if (!term[i] && !term[i - 1]) {
            ans += a[i] * a[i - 1];
        }
    }
    if (!term[n - 1] && !term[0]) ans += a[0] * a[n - 1];
    cout << ans;
}
