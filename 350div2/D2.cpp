#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;
const ll INF = 1488228228;
vector<ll> a, b;
ll n;
ll k;

bool ch(ll x) {
    ll t = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] * x > b[i]) {
            t += a[i] * x - b[i];
        }
    }
    return t <= k;
}

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    cin >> n >> k;
    a.resize(n);
    b.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
        cin >> b[i];

    ll l = 0, r = 2ll * INF;

    for (int i = 0; i < n; i++) {
        r = min(r, (b[i] + k) / a[i] + 7);
    }

    while (r - l > 1) {
        ll s = (l + r) / 2;
        if (ch(s)) {
            l = s;
        }
        else {
            r = s;
        }
    }
    cout << l;
    return 0;
}
