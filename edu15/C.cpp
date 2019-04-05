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

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.fi == b.fi) {
        return a.se > b.se;
    } else {
        return a.fi < b.fi;
    }
}

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
    int m;
    cin >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    ll L = -1, R = 2 * (ll)INT_MAX;
    while (R - L > 1) {
        ll M = (L + R) >> 1;
        vector< pair<ll, ll> > scan;
        for (int i = 0; i < m; i++) {
            scan.push_back({b[i] - M, 1});
            scan.push_back({b[i] + M + 1, -1});
        }
        for (int i = 0; i < n; i++) {
            scan.push_back({a[i], 2});
        }
        sort(scan.begin(), scan.end());
        int bal = 0;
        bool check = true;
        for (int i = 0; i < scan.size(); i++) {
            if (scan[i].se == 2) {
                if (bal <= 0) {
                    check = false;
                    break;
                }
            } else {
                bal += scan[i].se;
            }
        }
        /*for (int i = 0; i < scan.size(); i++) {
            cout << scan[i].fi << ' ' << scan[i].se << "   ";
        }
        cout << endl << M << endl;;*/
        if (check) R = M;
        else L = M;
    }
    cout << R;
}
