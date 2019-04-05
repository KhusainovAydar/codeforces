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

// oxxxy vseravno pobedil

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int NMAX = 300005;
int par[NMAX], rang[NMAX], sz[NMAX];

void make_set(int v) {
    par[v] = v;
    sz[v] = 1;
    rang[v] = 0;
}

int find_set(int v) {
    return (v == par[v]) ? v : (par[v] = find_set(par[v]));
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rang[a] < rang[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        if (rang[a] == rang[b])
            rang[a]++;
    }
}

bool used[NMAX];

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
    make_set(n + 1);
    used[n + 1] = 1;
    cout << 1 << ' ';
    for (int i = 1; i <= n; i++) {
        make_set(i);
    }
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        used[p] = 1;
        if (p > 1) {
            if (used[p - 1])
                union_sets(p, p - 1);
        }
        if (used[p + 1])
            union_sets(p, p + 1);
        cout << i + 2 - sz[find_set(n + 1)] << ' ';
    }
}
