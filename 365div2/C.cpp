#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
//#define INF 1000000000
#define y1 kek
#define re return
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

struct Point {
    double x, y;
    void init() {
        cin >> x >> y;
    }
};

int main() {
    srand((unsigned int)time(NULL));
    /*#if __APPLE__
     freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
     freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
     #endif*/
    int n;
    cin >> n;
    double w, v, u;
    cin >> w >> v >> u;
    vector<Point> mn(n);
    double minn = DBL_MAX;
    double kek = 0;
    double xmax = DBL_MIN;
    for (int i = 0; i < n; i++) {
        mn[i].init();
        xmax = max(xmax, mn[i].x);
        if (mn[i].y < minn) {
            minn = mn[i].y;
            kek = mn[i].x;
        }
    }
    double tim = w / u;
    bool check = true;
    for (int i = 0; i < n; i++) {
        double x = mn[i].x;
        double y = mn[i].y;
        if (y / u - x / v > eps)
            check = false;
    }
    cout.precision(20);
    if (check) {
        cout << tim;
        return 0;
    }
    int idmx = -1;
    int id = 0;
    for (int i = 0; i < mn.size(); i++) {
        if (xmax == mn[i].x && idmx == -1)
            idmx = i;
        if (mn[i].x == kek && mn[i].y == minn) {
            id = i;
        }
    }
    tim = kek / v;
    double y = 0;
    if (kek / v < minn / u) {
        y = kek / v * u;
    } else {
        y = minn;
    }
    if (id > idmx) {
        idmx += n;
    }
    for (int j = id + 1; j <= idmx; j++) {
        int i = j % n;
        double dist = mn[i].x - mn[(i ? (i - 1) : (n - 1))].x;
        tim += dist / v;
        double dist2 = mn[i].y - y;
        if (dist / v >= dist2 / u) {
            y = mn[i].y;
        } else {
            y += dist / v * u;
        }
    }
    cout.precision(20);
    cout << tim + (w - y) / u;
}
