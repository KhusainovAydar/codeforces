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
    int n, m;
    cin >> n >> m;
    vector<set<int>> s(m);
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '1') {
                s[j].insert(i);
            }
        }
    }
    set<int> ans;
    for (int i = 0; i < n; i++) {
        ans.insert(i);
    }
    for (int i = 0; i < m; i++) {
        if (s[i].size() == 1) {
            ans.erase(*s[i].begin());
        }
    }
    if (ans.size()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
