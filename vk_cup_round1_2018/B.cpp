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


struct Node {
    Node *l, *r;
    ll x, y, sum, sz, del;
    Node(ll key) : l(NULL), r(NULL), x(key), sum(key), y(rand()), sz(1), del(0) {}
};

ll getsize(Node * t) {
    if (t)
        return t->sz;
    else
        return 0;
}


ll sum(Node * t) {
    if (t)
        return t->sum - t->del * getsize(t);
    else
        return 0;
}

void push(Node * t) {
    if (!t)
        return;
    t->x -= t->del;
    if (t->l) {
        t->l->del += t->del;
    }
    if (t->r) {
        t->r->del += t->del;
    }
    t->del = 0;
}

void recalc(Node * t) {
    if (t) {
        push(t);
        t->sum = sum(t->l) + sum(t->r) + t->x;
        t->sz = getsize(t->l) + getsize(t->r) + 1;
    }
}

void Minus(Node * t, ll mis) {
    if (t) {
        t->del += mis;
    }
}


Node * merge(Node * l, Node * r) {
    if (!l || !r)
        return l == NULL ? r : l;
    Node * res;
    recalc(l);
    recalc(r);
    if (l->y > r->y) {
        l->r = merge(l->r, r);
        recalc(l->r);
        res = l;
    } else {
        r->l = merge(l, r->l);
        recalc(r->l);
        res = r;
    }
    recalc(res);
    return res;
}

Node ** split(Node * t, ll x) {
    if (!t)
        return new Node * [2] {NULL, NULL};
    recalc(t);
    Node ** res;
    if (x <= t->x) {
        res = split(t->l, x);
        t->l = res[1];
        res[1] = t;
    } else {
        res = split(t->r, x);
        t->r = res[0];
        res[0] = t;
    }
    recalc(res[0]);
    recalc(res[1]);
    return res;
}

Node * add(Node * t, Node * p) {
    if (!t) {
        t = p;
        return t;
    }
    recalc(t);
    recalc(p);
    if (t->y < p->y) {
        auto k = split(t, p->x);
        p->l = k[0];
        p->r = k[1];
        t = p;
        recalc(t);
        return t;
    }
    if (t->x >= p->x) {
        t->l = add(t->l, p);
        recalc(t->l);
    } else {
        t->r = add(t->r, p);
        recalc(t->r);
    }
    recalc(t);
    return t;
}

ll ans(Node *t, int l, int r) {
    recalc(t);
    auto a = split(t, l);
    auto b = split(a[1], r + 1);
    ll kek = sum(b[0]);
    t = merge(a[0], merge(b[0], b[1]));
    recalc(t);
    return kek;
}

bool find(Node * t, ll x) {
    if (!t) return false;
    if (t->x == x) {
        return true;
    }
    if (t->x > x) {
        return find(t->l, x);
    } else {
        return find(t->r, x);
    }
}

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
    int n;
    cin >> n;
    vector<ll> v(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    Node * T = NULL;
    ll nak = 0;
    for (int i = 0; i < n; i++) {
        nak += v[i];
        T = add(T, new Node(v[i]));
        nak = sum(T);
        Minus(T, t[i]);
        auto k = split(T, 0);
        cout << nak - sum(k[1]) << ' ';
        T = k[1];
    }
}
