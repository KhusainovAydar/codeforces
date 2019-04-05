#include <bits/stdc++.h>
#define times clock() * 1.0 / CLOCKS_PER_SEC
//#define pi 3.1415926535897932384626433832795
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int long long
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS
#define endl '\n'

// oxxxy vseravno pobedil

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const int NMAX = 200005;
const int alp = 26;

struct Hash {
    vector<ll> h, step;
    ll p = 29;
    ll mod = 42424243;
    void init (const string & s) {
        int n = (int)s.length();
        h.resize(n), step.resize(n + 1);
        h[0] = s[0]; step[0] = 1;
        for (int i = 1; i < n; i++) {
            h[i] = h[i - 1] * p + s[i];
            if (h[i] >= mod) h[i] %= mod;
            step[i] = step[i - 1] * p;
            if (step[i] >= mod) step[i] %= mod;
        }
        step[n] = step[n - 1] * p;
        if (step[n] >= mod) step[n] %= mod;
    }
    ll get_hash(int l, int r) {
        ll ret = h[r] - (l ? (h[l - 1] * step[r - l + 1]) % mod : 0);
        if (ret < 0) ret += mod;
        return ret;
    }
};


int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled/input.txt", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled/output.txt", "w", stdout);
#else
    //        freopen("lca2.in", "r", stdin);
//    freopen("lca2.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = '$' + s;
    vector<Hash> vh;
    for (char c = 'a'; c <= 'z'; c++) {
        string to_hash = "$";
        for (int i = 1; i <= n; i++) {
            if (s[i] == c) {
                to_hash += '1';
            } else {
                to_hash += '0';
            }
        }
        Hash hh;
        hh.init(to_hash);
        vh.push_back(hh);
    }
    unordered_map<int, int> mp;
    while (m--) {
        int x, y, len;
        cin >> x >> y >> len;
        for (int i = 0; i < alp; i++) {
            ++mp[vh[i].get_hash(x, x + len - 1)];
            --mp[vh[i].get_hash(y, y + len - 1)];
        }
        bool bad = false;
        for (int i = 0; i < alp; i++) {
            if (mp[vh[i].get_hash(x, x + len - 1)] != 0) {
                bad = true;
                break;
            }
        }
        if (bad) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
        mp.clear();
    }
}
