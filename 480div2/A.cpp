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
    string s;
    cin >> s;
    vector<int> ans;
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {
            cur++;
        } else {
            ans.push_back(cur);
            cur = 0;
        }
    }
    if (ans.size() == 0) {
        ans.push_back(cur);
    } else {
        ans[0] += cur;
    }
    int sum = 0;
    for (int i = 0; i < ans.size(); i++) {
        sum += ans[i];
    }
    if (sum % ans.size() == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
