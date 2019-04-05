#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int long long
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
    //    freopen("cinema.in", "r", stdin);
    //    freopen("cinema.out", "w", stdout);
#endif
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x, y;
    cin >> x >> y;
    int a = abs(x1 - x2);
    int b = abs(y1 - y2);
    if (a % x || b % y) {
        cout << "NO";
        return 0;
    }
    a /= x;
    b /= y;
    if (a % 2 == b % 2) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
