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

// oxxxy vseravno pobedil

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int NMAX = 200003;

vector<int> ans[NMAX];

int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
//    freopen("lca2.in", "r", stdin);
//    freopen("lca2.out", "w", stdout);
#endif
    string s;
    cin >> s;
    int cnt = 0;
    set<int> s0, s1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (s1.size() == 0) {
                s0.insert(cnt);
                ans[cnt].push_back(i + 1);
                cnt++;
            } else {
                int k = *s1.begin();
                ans[k].push_back(i + 1);
                s1.erase(s1.begin());
                s0.insert(k);
            }
        } else {
            if (s0.size() == 0) {
                cout << -1;
                return 0;
            } else {
                int k = *s0.begin();
                ans[k].push_back(i + 1);
                s0.erase(s0.begin());
                s1.insert(k);
            }
        }
    }
    if (s1.size()) {
        cout << -1;
        return 0;
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << ans[i].size() << ' ';
        for (auto t : ans[i]) {
            cout << t << ' ';
        }
        cout << endl;
    }
}
