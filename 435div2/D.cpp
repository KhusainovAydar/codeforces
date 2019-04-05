#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
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

// oxxxy vseravno pobedil

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//#if __APPLE__
//    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
//    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
//#else
//    //    freopen("cinema.in", "r", stdin);
//    //    freopen("cinema.out", "w", stdout);
//#endif
    int n;
    cin >> n;
    string s = "";
    for (int i = 0; i < n; i++) {
        s += '1';
    }
    cout << "? " << s << endl;
    int sum1;
    cin >> sum1;
    s[0] = '0';
    cout << "? " << s << endl;
    int sum;
    cin >> sum;
    int L = 1, R = n;
    if (sum > sum1) {
        while (R - L > 1) {
            int M = (L + R) >> 1;
            string s2 = "";
            for (int i = 0; i < M; i++) {
                s2 += '1';
            }
            for (int i = M; i < n; i++) {
                s2 += '0';
            }
            cout << "? " << s2 << endl;
            int sum2;
            cin >> sum2;
            int sz = n - M;
            int x = (sum1 + sum2 - sz) / 2;
            if (x == 0) {
                L = M;
            } else {
                R = M;
            }
        }
        cout << "! " << R  << ' ' << R - 1 << endl;
    } else {
        sum1 = n - sum1;
        while (R - L > 1) {
            int M = (L + R) >> 1;
            string s2 = "";
            for (int i = 0; i < M; i++) {
                s2 += '0';
            }
            for (int i = M; i < n; i++) {
                s2 += '1';
            }
            cout << "? " << s2 << endl;
            int sum2;
            cin >> sum2;
            int sz = n - M;
            int x = (sum1 + sum2 - sz) / 2;
            if (x == 0) {
                L = M;
            } else {
                R = M;
            }
        }
        cout << "! " << R - 1 << ' ' << R << endl;
    }

}
