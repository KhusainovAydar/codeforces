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
    int a, b;
    cin >> a >> b;
    int sum = 0;
    int cur1 = 1, cur2 = 1;
    if (a > b) {
        swap(a, b);
    }
    while (a != b) {
        if (abs(a - b) > 1) {
            a++; b--;
            sum += cur1 + cur2;
            cur1++;
            cur2++;
        } else {
            sum += cur1;
            a = b;
        }
    }
    cout << sum;
}
