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
//#define ll ll
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll mod = 1000000007;

const int NMAX = 400005;

ll fact[NMAX], refact[NMAX];

ll c(ll n, ll k) {
    return (((fact[n] * (ll) refact[k]) % mod * (ll) refact[n - k]) % mod);
}

ll bin(ll a, ll n) {
    if (n == 0) {
        return 1;
    }
    if (!(n & 1)) {
        ll t = bin(a, n / 2);
        return (t * (ll) t) % mod;
    } else {
        ll t = bin(a, n - 1);
        return (t * (ll) a) % mod;
    }
}

ll suff[NMAX], pref[NMAX];

int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
//    freopen("farmer.in", "r", stdin);
//    freopen("farmer.out", "w", stdout);
#endif
    fact[0] = 1;
    refact[0] = 1;
    for (ll i = 1; i < NMAX; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        refact[i] = bin(fact[i], mod - 2);
    }
    string s;
    cin >> s;
    s = '#' + s;
    int n = (int)s.size();
    for (int i = 1; i < n; i++) {
        if (s[i] == '(') {
            pref[i] = pref[i - 1] + 1;
        } else {
            pref[i] = pref[i - 1];
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        if (s[i] == ')') {
            suff[i] = suff[i + 1] + 1;
        } else {
            suff[i] = suff[i + 1];
        }
    }

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == '(') {
            ll N = suff[i] + pref[i] - 1;
            ll K = pref[i];
            ans = (ans + c(suff[i] + pref[i] - 1, pref[i])) % mod;
        }
    }

    cout << ans;
}
