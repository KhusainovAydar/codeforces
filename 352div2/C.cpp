#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'

using namespace std;
typedef long long ll;

const int NMAX = 1e5;

int x[NMAX], y[NMAX];
bool used[NMAX];
int ax, ay, bx, by, tx, ty, n;
double ans = 0;
double t;

double dist(double a, double b, double c, double d) {
    return sqrt((a - c)*(a - c) + (b - d) * (b - d));
}

void init () {
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        ans += 2 * dist(tx, ty, x[i], y[i]);
    }
}
double res = LLONG_MAX;

void kek () {
    int j = -1;


    for (int i = 0; i < n; i++) {
        double bounsss = ans - dist(tx, ty, x[i], y[i]) + dist(ax, ay, x[i], y[i]);
        if ((j == -1 || bounsss < res)) {
            j = i;
            res = bounsss;
        }
    }
    int cnt = 0;

    if (j != -1) {
        ans = res;
        used[j] = 1;
        cnt = 1;
    }
    res = ans;


    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            ans = min(ans, res - dist(tx, ty, x[i], y[i]) + dist(bx, by, x[i], y[i]));
            if (ans == res - dist(tx, ty, x[i], y[i]) + dist(bx, by, x[i], y[i])) {
                cnt = 1;
            }
        }
    }
}
void one() {
    t = ans;
    bool can = false;
    kek();
}

void two () {
    for (int i = 0; i < NMAX; i++) used[i] = 0;
    bool can = false;
    int j = -1;
    double res = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        double bounsss = t - dist(tx, ty, x[i], y[i]) + dist(bx, by, x[i], y[i]);
        if ((j == -1 || bounsss < res)) {
            j = i;
            res = bounsss;
        }
    }
    if (j != -1) {
        t = res;
        used[j] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            t = min(t, res - dist(tx, ty, x[i], y[i]) + dist(ax, ay, x[i], y[i]));
        }
    }
}

int main() {
    cout.precision(20);
    init();
    one();
    two();
    cout << min(ans, t) << endl;
}
