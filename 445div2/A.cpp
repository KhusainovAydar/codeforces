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
    //    freopen("cinema.in", "r", stdin);
    //    freopen("cinema.out", "w", stdout);
#endif
    int n = 6;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    do {
        if (a[0] + a[1] + a[2] == a[3] + a[4] + a[5]) {
            cout << "YES";
            return 0;
        }
    } while (next_permutation(a.begin(), a.end()));
    cout << "NO";
    return 0;
}
