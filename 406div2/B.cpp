#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
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

int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
//    freopen("alligator.in", "r", stdin);
//    freopen("alligator.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector< vector<int> > a(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        set<int> s;
        bool bad = false;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            if (s.find(-x) != s.end()) {
                bad = 1;
            }
            s.insert(x);
        }
        if (!bad) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
