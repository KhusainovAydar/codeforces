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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand((unsigned int)time(NULL));
/*#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#endif*/
    ll n, k, d;
    cin >> n >> k >> d;
    vector<ll> a(n);
    ll sum = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= k) {
            sum += a[i];
        }
        if (sum > d) {
            sum = 0;
            cnt++;
        }
    }
    cout << cnt;
}
