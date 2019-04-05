#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.0001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define MAX (MIN * (-1) + 100)
#define MOD 1000000007

using namespace std;

typedef long long ll;

struct v {
    int a, b, c;
    int num;
    void init(int i) {
        cin >> a >> b >> c;
        num = i + 1;
    }
    int minn() {
        return min({a, b, c});
    }
};

map< pair<int, int>, pair< pair<int, int> , pair<int, int> > > mp;

pair<int, int> kek(int a, int b) {
    return {min(a, b), max(a, b)};
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    //    freopen("grasshopper.in", "r", stdin);
    //    freopen("grasshopper.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<v> a(n);
    for (int i = 0; i < n; i++) {
        a[i].init(i);
    }
    int maxx = 0;
    for (int i = 0; i < n; i++) {
        maxx = max(maxx, a[i].minn());
    }
    for (int i = 0; i < n; i++) {
        auto k = mp[kek(a[i].a, a[i].b)];
        if (k.fi.fi == 0) {
            k.fi = {a[i].num, a[i].c};
        } if (a[i].c > k.fi.se) {
            k.fi = {a[i].num, a[i].c};
        } else if ((k.se.fi == 0 || a[i].c > k.se.se) && k.fi.fi != a[i].num) {
            k.se = {a[i].num, a[i].c};
        }
        mp[kek(a[i].a, a[i].b)] = k;
        
        k = mp[kek(a[i].c, a[i].b)];
        if (k.fi.fi == 0) {
            k.fi = {a[i].num, a[i].a};
        } if (a[i].a > k.fi.se) {
            k.fi = {a[i].num, a[i].a};
        } else if ((k.se.fi == 0 || a[i].a > k.se.se) && k.fi.fi != a[i].num) {
            k.se = {a[i].num, a[i].a};
        }
        mp[kek(a[i].c, a[i].b)] = k;
        
        k = mp[kek(a[i].a, a[i].c)];
        if (k.fi.fi == 0) {
            k.fi = {a[i].num, a[i].b};
        } if (a[i].b > k.fi.se) {
            k.fi = {a[i].num, a[i].b};
        } else if ((k.se.fi == 0 || a[i].b > k.se.se) && k.fi.fi != a[i].num) {
            k.se = {a[i].num, a[i].b};
        }
        mp[kek(a[i].a, a[i].c)] = k;
    }
    
    int ans = 0;
    pair<int, int> k = {-1, -1};
    for (int i = 0; i < n; i++) {
        auto q = mp[kek(a[i].a, a[i].b)];
        
        if (q.fi.fi == a[i].num) {
            if (q.se.fi != 0) {
                int lol = min({a[i].a, a[i].b, a[i].c + q.se.se});
                if (lol > ans) {
                    ans = lol;
                    k.fi = i + 1;
                    k.se = q.se.fi;
                }
            }
        } else {
            int lol = min({a[i].a, a[i].b, a[i].c + q.fi.se});
            if (lol > ans) {
                ans = lol;
                k.fi = i + 1;
                k.se = q.fi.fi;
            }
        }
        
        q = mp[kek(a[i].c, a[i].b)];
        
        if (q.fi.fi == a[i].num) {
            if (q.se.fi != 0) {
                int lol = min({a[i].c, a[i].b, a[i].a + q.se.se});
                if (lol > ans) {
                    ans = lol;
                    k.fi = i + 1;
                    k.se = q.se.fi;
                }
            }
        } else {
            int lol = min({a[i].c, a[i].b, a[i].a + q.fi.se});
            if (lol > ans) {
                ans = lol;
                k.fi = i + 1;
                k.se = q.fi.fi;
            }
        }
        
        q = mp[kek(a[i].a, a[i].c)];
        
        if (q.fi.fi == a[i].num) {
            if (q.se.fi != 0) {
                int lol = min({a[i].a, a[i].c, a[i].b + q.se.se});
                if (lol > ans) {
                    ans = lol;
                    k.fi = i + 1;
                    k.se = q.se.fi;
                }
            }
        } else {
            int lol = min({a[i].a, a[i].c, a[i].b + q.fi.se});
            if (lol > ans) {
                ans = lol;
                k.fi = i + 1;
                k.se = q.fi.fi;
            }
        }
    }
    
    if (maxx > ans) {
        cout << 1 << endl;
        for (int i = 0; i < n; i++) {
            if (a[i].minn() == maxx) {
                cout << i + 1;
                return 0;
            }
        }
    } else {
        cout << 2 << endl;
        cout << k.fi << ' ' << k.se << endl;
    }
}
