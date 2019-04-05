#include <bits/stdc++.h>
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
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

int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("burrow.in", "r", stdin);
//    freopen("burrow.out", "w", stdout);
#endif
    unordered_set<char> used{'a', 'o', 'y', 'i', 'e', 'u'};
    int n;
    cin >> n;
    char last;
    cin >> last;
    for (int i = 1; i < n; i++) {
        char c;
        cin >> c;
        if (used.find(c) != used.end() && used.find(last) != used.end()) {
            continue;
        } else {
            cout << last;
            last = c;
        }
    }
    cout << last;
}
