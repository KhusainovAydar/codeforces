#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
#define pb push_back
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

map< pair<ll, ll> , int> ans;

struct Hash {
    vector<ll> h, h1, step, step2;
    ll p = 259;
    ll p1 = 29;
    ll mod1 = 1000000007;
    ll mod = 1000000009;
    void init (const string & s) {
        int n = (int)s.length();
        h.resize(n), step.resize(n + 1);
        step2.resize(n + 1);
        step2[0] = 1;
        h1.resize(n);
        h1[0] = s[0];
        h[0] = s[0]; step[0] = 1;
        for (int i = 1; i < n; i++) {
            h[i] = h[i - 1] * p + s[i];
            h1[i] = h1[i - 1] * p1 + s[i];
            if (h[i] >= mod) h[i] %= mod;
            if (h1[i] >= mod1) h1[i] %= mod1;
            step[i] = step[i - 1] * p;
            step2[i] = step2[i - 1] * p1;
            if (step2[i] >= mod) step2[i] %= mod1;
            if (step[i] >= mod) step[i] %= mod;
        }
        step[n] = step[n - 1] * p;
        step2[n] = step2[n - 1] * p1;
        if (step2[n] >= mod1) step2[n] %= mod1;
        if (step[n] >= mod) step[n] %= mod;
    }
    pair<ll, ll> get_hash(int l, int r) {
        ll ret = h[r] - (l ? (h[l - 1] * step[r - l + 1]) % mod : 0);
        if (ret < 0) ret += mod;
        ll ret2 = h1[r] - (l ? (h1[l - 1] * step2[r - l + 1]) % mod1 : 0);
        if (ret2 < 0) ret2 += mod1;
        return {ret, ret2};
    }
};


int main() {
    //srand((unsigned int)time(NULL));
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
//#if __APPLE__
//    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
//    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
//    //#else
//    //    freopen("movetofront.in", "r", stdin);
//    //    freopen("movetofront.out", "w", stdout);
//#endif
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    int sz = (int)s.length();
    s = s + s;
    Hash sh;
    sh.init(s);
    int q;
    cin >> q;
    vector<Hash> ha(q);
    for (int i = 0; i < q; i++) {
        string S;
        cin >> S;
        ha[i].init(S);
        ans[ha[i].get_hash(0, (int)S.length() - 1)] = i + 1;
    }
    for (int i = 0; i < k; i++) {
        bool ch = false;
        vector<int> lol;
        unordered_set<int> se;
        se.clear();
        for (int j = i; j + k <= sz + i; j += k) {
            int mem = ans[sh.get_hash(j, j + k - 1)];
            if (!mem || se.find(mem) != se.end()) {
                ch = true;
            } else {
                se.insert(mem);
                lol.push_back(mem);
            }
        }
        if (!ch) {
            cout << "YES" << endl;
            for (auto t : lol) {
                cout << t << ' ';
            }
            return 0;
        }
    }
    cout << "NO";
}
