#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
//#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define pb push_back
#define MAX (MIN * (-1) + 100)
#define MOD 1000000007

using namespace std;

typedef long long ll;

vector< vector<int> > g;

int cnt;
const int NMAX = 105;

int used[NMAX];

bool dfs(int v, int last) {
    used[v] = 1;
    cnt++;
    bool ch = false;
    for (auto t : g[v]) {
        if (t == last) {
            cnt++;
            return true;
        }
        if (used[t]) return false;
        ch = (ch || dfs(t, last));
    }
    return ch;
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
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
    g.resize(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        g[i].pb(a[i]);
    }
    int val = -1;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        cnt = 0;
        bool ans = dfs(a[i], i);
        if (a[i] == i)
            cnt = 1;
        if (!ans) {
            cout << -1;
            return 0;
        }
        //cout << cnt << endl;
        if (cnt % 2 == 0) {
            cnt /= 2;
        }
        if (val == -1) {
            val = cnt;
        } else {
            val = lcm(val, cnt);
        }
    }
    cout << val;
}
