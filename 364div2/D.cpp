#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000
#define y1 kek
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
#define double long double
//#define int ll
using namespace std;

typedef long long ll;

double fun(int n, double s, double v1, double v2, int k, double dist) {
    double tim = 0;
    double ans = dist / v2 + (s - dist) / v1;
    n = max(0, n - k);
    tim += dist / v2;
    double tek = min(s, tim * v1);
    double kek = tim;
    while (n > 0) {
        double tm = (dist - (kek) * v1) / (v1 + v2);
        tek = min(tek + tm * v1, s);
        tim += tm;
        n = max(0, n - k);
        kek = (min(dist, s - tek)) / v2;
        tim += kek;
    }
    return max(ans, tim);
}

int main() {
    srand((unsigned int)time(NULL));
/*#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("minonpath.in", "r", stdin);
    freopen("minonpath.out", "w", stdout);
#endif*/
    int n, k;
    double s, v1, v2;
    cin >> n >> s >> v1 >> v2 >> k;
    double L = 0, R = s + eps;
    double ans = 0;
    while (R - L > eps) {
        double M1 = L + (R - L) / 3;
        double M2 = R - (R - L) / 3;
        if (fun(n, s, v1, v2, k, M1) > fun(n, s, v1, v2, k, M2)) {
            L = M1;
            ans = fun(n, s, v1, v2, k, M1);
        } else {
            R = M2;
            ans = fun(n, s, v1, v2, k, M2);
        }
    }
    cout.precision(20);
    cout << ans;
}
