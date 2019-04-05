#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
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
//    freopen("farmer.in", "r", stdin);
//    freopen("farmer.out", "w", stdout);
#endif
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "Tetrahedron") {
            ans += 4;
        }
        if (s == "Cube") {
            ans += 6;
        }
        if (s == "Octahedron") {
            ans += 8;
        }
        if (s == "Dodecahedron") {
            ans += 12;
        }
        if (s == "Icosahedron") {
            ans += 20;
        }
    }
    cout << ans;
}
