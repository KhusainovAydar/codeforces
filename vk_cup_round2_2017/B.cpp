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
//#define int long long
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct Point {
    ld x, y;
    void init() {
        cin >> x >> y;
    }
};

struct Vector {
    ld x, y;
    void init(Point A, Point B) {
        x = B.x - A.x;
        y = B.y - A.y;
    }
};

ld sqr(ld x) {
    return x * x;
}

struct Line {
    ld a, b, c;
    Vector n;

    void init(Point p1, Point p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = -(a * p1.x + b * p1.y);
        n = {a, b};
    }

    ld val(Point p) {
        return a * p.x + b * p.y + c;
    }

    ld dist(Point p) {
        ld kek = sqrt(sqr(a) + sqr(b));
        ld d = fabs(val(p));
        return d / kek;
    }
};
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
    int n;
    cin >> n;
    vector< Point > v(n);
    for (int i = 0; i < n; i++) {
        v[i].init();
    }
    ld L = 0, R = 1000000000;
    for (int it = 0; it < 1000; it++) {
        ld M = (L + R) * 0.5;
        bool ch = false;

        for (int i = 0; i < n; i++) {
            Point p1 = v[i], p2 = v[(i + 1) % n], p3 = v[(i + 2) % n];
            Line A;
            A.init(p1, p3);
            if (M * 2 > A.dist(p2)) {
                ch = 1;
            }
        }
        if (ch) {
            R = M;
        } else {
            L = M;
        }
    }
    cout.precision(20);
    cout << R << endl;
}
