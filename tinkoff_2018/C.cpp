#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define cntbit(x) __builtin_popcount(x)
#define double long double
//#define int long long
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
//typedef long double ld;

const double eps = 1e-11;

double sqr(double x) {
    return x * x;
}

struct Point {
    double x, y;

    void init() {
        cin >> x >> y;
    }

    bool operator==(const Point & a) const {
        return a.x == x && a.y == y;
    }
};

double dist(Point a, Point b) {
    return (sqr(a.x - b.x) + sqr(a.y - b.y));
}

struct Vector {
    double x, y;

    void init(Point a, Point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }

    double len() {
        return sqrt(sqr(x) + sqr(y));
    }

};

double scalmul(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

double vectmul(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

struct Line {
    double a, b, c;
    Vector n;

    void init(Point p1, Point p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = -(a * p1.x + b * p1.y);
        n = {a, b};
    }

    void init(double A, double B, double C) {
        a = A;
        b = B;
        c = C;
        n = {a, b};
    }

    double val(Point p) {
        return a * p.x + b * p.y + c;
    }

    double dist(Point p) {
        double kek = sqrt(sqr(a) + sqr(b));
        double d = fabs(val(p));
        return d / kek;
    }

    bool one_side(Point p1, Point p2) {
        return ((val(p1) * val(p2)) > 0);
    }

    bool match(Line L) {
        return (a * L.b == b * L.a) && (b * L.c == c * L.b) && (a * L.c == L.a * c);
    }

    bool parallel(Line L) {
        return (a * L.b == b * L.a) && (b * L.c != c * L.b) && (a * L.c != L.a * c);
    }

    pair< Line, Line > parallel_line(double R) {
        Line ret, ret2;
        ret.a = a, ret.b = b;
        double e = n.len();
        e *= R;
        ret.c = c + e;
        ret2 = {a, b, c - e};
        return {ret, ret2};
    }

    Point intersec(Line A) {
        Point ans;
        double aa[2] = {a, A.a}, bb[2] = {b, A.b}, cc[2] = {c, A.c};
        ans.y = (aa[1] * cc[0] - cc[1] * aa[0]) / (aa[0] * bb[1] - bb[0] * aa[1]);
        ans.x = (cc[0] * bb[1] - bb[0] * cc[1]) / (aa[1] * bb[0] - bb[1] * aa[0]);
        return ans;
    }

    bool intersec(Point A) {
        return (val(A) == 0);
    }
};

struct Segment {
    Point A, B;
    Line L_AB;
    Vector V_AB, V_BA;

    void init(Point a, Point b) {
        A = a;
        B = b;
        V_AB.init(a, b);
        V_BA.init(b, a);
        L_AB.init(a, b);
    }

    bool check_on_segment(Point P) {
        Vector V_AP, V_BP; V_AP.init(A, P), V_BP.init(B, P);
        return scalmul(V_AB, V_AP) >= 0 && scalmul(V_BA, V_BP) >= 0;
    }

    double dist(Point p) {
        if (check_on_segment(p)) {
            return L_AB.dist(p);
        }
        return min(::dist(p, B), ::dist(p, A));
    }

    bool intersec(Point p) {
        return check_on_segment(p) && L_AB.intersec(p);
    }
};

struct Ray {
    Point st;
    Vector n;
    Line pr;

    void init(Point a, Point b) {
        pr.init(a, b);
        st = a;
        n.init(a, b);
    }

    bool check_on_Ray(Point p) {
        Vector S;
        S.init(st, p);
        return scalmul(S, n) >= 0;
    }

    bool intersec(Point a) {
        Vector S;
        S.init(st, a);
        return check_on_Ray(a) && vectmul(S, n) == 0 && pr.intersec(a);
    }
};

bool ch(Segment a, Segment b) {
    bool val = a.L_AB.one_side(b.A, b.B);
    return (!val && !b.L_AB.one_side(a.A, a.B));
}

bool used[1000000];

bool meme(Point a, Point c, Point P) {
    if (P.x > a.x && P.x < c.x && P.y > a.y && P.y < c.y) {
        return true;
    } else {
        return false;
    }
}

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
    Point a, b, c, d;
    cin >> a.x >> a.y >> c.x >> c.y;
    if (a.x == c.x || a.y == c.y) {
        cout << -1;
        return 0;
    }
//    a.x += eps;
//    a.y += eps;
//    c.x -= eps;
//    c.y -= eps;
    b = {a.x, c.y};
    d = {c.x, a.y};
    vector< Segment > seg(4);
    seg[0].init(a, b);
    seg[1].init(b, c);
    seg[2].init(c, d);
    seg[3].init(a, d);
    vector< pair< Point, Vector > > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi.x >> v[i].fi.y;
        cin >> v[i].se.x >> v[i].se.y;
        if (v[i].se.x == 0 && v[i].se.y == 0) {
            if (v[i].fi.x > a.x && v[i].fi.x < c.x && v[i].fi.y > a.y && v[i].fi.y < c.y) {
                used[i] = 1;
            } else {
                cout << -1;
                return 0;
            }
        }
    }
    bool bad = false;
    for (int i = 0; i < n; i++) {
        if (v[i].fi.x > a.x && v[i].fi.x < c.x && v[i].fi.y > a.y && v[i].fi.y < c.y) {

        } else {
            bad = 1;
        }
    }
    if (!bad) {
        cout << 0;
        return 0;
    }
    bad = 0;

    for (int i = 0; i < n; i++) {
        v[i].fi.x += eps * v[i].se.x;
        v[i].fi.y += eps * v[i].se.y;
    }
    for (int i = 0; i < n; i++) {
        if (v[i].fi.x > a.x && v[i].fi.x < c.x && v[i].fi.y > a.y && v[i].fi.y < c.y) {

        } else {
            bad = 1;
        }
    }
    if (!bad) {
        cout << 0;
        return 0;
    }

    double INF = 100000000;
    double L = 0, R = LDBL_MAX;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        Point A = v[i].fi;
        Point B = {A.x + INF * v[i].se.x, A.y + INF * v[i].se.y};
        for (int j = 0; j < 4; j++) {
            if (seg[j].L_AB.intersec(A) && seg[j].L_AB.intersec(B)) {
                cout << -1;
                return 0;
            }
        }
        double V = v[i].se.x * v[i].se.x + v[i].se.y * v[i].se.y;
        Segment t;
        t.init(A, B);
        vector< Point > per;
        for (int j = 0; j < 4; j++) {
            if (!t.L_AB.parallel(seg[j].L_AB) && ch(t, seg[j]) && ch(t, seg[j])) {
                per.pb(t.L_AB.intersec(seg[j].L_AB));
            }
        }
        if (per.size() == 0) {
            cout << -1;
            return 0;
        }
        if (per.size() == 2) {
            if (per[0] == per[1]) {
                cout << -1;
                return 0;
            }
        }
        double minn = LDBL_MAX;
        double maxx = LDBL_MIN;
        if (per.size() == 1) {
            minn = 0;
            maxx = dist(per[0], A) / V;
        } else {
            for (int j = 0; j < per.size(); j++) {
                minn = min(minn, (dist(per[j], A) / V));
                maxx = max(maxx, (dist(per[j], A) / V));
            }
        }
        L = max(L, minn);
        R = min(R, maxx);
//        cout << minn << ' ' << maxx << endl;
    }
//    if (L > R) {
//        cout << -1;
//        return 0;
//    }
    L = sqrt(L);
//    cout << L << ' ' << R << endl;
    bad = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        v[i].fi.x += v[i].se.x * L;
        v[i].fi.y += v[i].se.y * L;
        if (v[i].fi.x > a.x && v[i].fi.x < c.x && v[i].fi.y > a.y && v[i].fi.y < c.y) {

        } else {
            bad = 1;
        }
//        cout << v[i].fi.x << ' ' << v[i].fi.y << endl;
    }
    if (bad) {
        bad = 0;
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            Point P1 = {v[i].fi.x + eps * v[i].se.x, v[i].fi.y + eps * v[i].se.y};
            if (meme(a, c, P1)) {
                continue;;
            }
            bad = 1;
        }
        if (bad) {
            bad = 0;
            for (int i = 0; i < n; i++) {
                if (used[i]) continue;
                Point P2 = {v[i].fi.x - eps * v[i].se.x, v[i].fi.y - eps * v[i].se.y};
                if (meme(a, c, P2)) {
                    continue;
                }
                cout << -1;
                return 0;
            }
        }
    }
    cout.precision(20);
    cout << L << endl;
}
