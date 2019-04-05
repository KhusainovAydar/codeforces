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
    int n, k, l;
    cin >> n >> k >> l;
    int m = n * k;
    vector<pair<int, int>> a((unsigned long) m);
    set<pair<int, int>> M;
    for (int i = 0; i < m; i++) {
        cin >> a[i].first;
        a[i].second = i;
        M.insert(a[i]);
    }
    sort(a.begin(), a.end());
    int cur = 0;
    ll sum = 0;
    vector<pair<int, int>> b;
    for (int i = 0; i < m; i++) {
        if (a[i].first - a[0].first <= l) {
            b.push_back(a[i]);
        }
    }
    if (b.size() < n) {
        cout << 0 << endl;
        return 0;
    }
    sort(b.rbegin(), b.rend());
    set<pair<int, int>> used;
    for (int i = 0; i < b.size(); i++) {
        if (used.find(b[i]) != used.end()) {
            continue;
        }
        int val = b[i].first;
        used.insert(b[i]);
        M.erase(b[i]);
        for (int j = 0; j + 1 < k; j++) {
            val = min(val, M.rbegin()->first);
            used.insert(*M.rbegin());
            M.erase(*M.rbegin());
        }
        sum += val;
    }
    cout << sum;
}
