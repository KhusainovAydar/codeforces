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

int n, k, x;
vector<ll> a;

void ans() {
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    exit(0);
}

int main(int argc, char* argv[]) {
    srand((unsigned int)time(NULL));
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    //    freopen("grasshopper.in", "r", stdin);
    //    freopen("grasshopper.out", "w", stdout);
#endif
    cin >> n >> k >> x;
    a.resize(n);
    int ch = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            ch *= -1;
        }
    }
    if (ch == 1) {
        set< pair<ll, int> > s;
        for (int i = 0; i < n; i++) {
            if (a[i] >= 0) {
                s.insert({abs(-1 - a[i]), i});
            } else {
                s.insert({abs(1 - a[i]), i});
            }
        }
        auto q = * s.begin();
        int id = q.se;
        if (a[id] >= 0) {
            while (a[id] >= 0) {
                a[id] -= x;
                k--;
                if (k == 0) {
                    ans();
                }
            }
        } else {
            while (a[id] <= 0) {
                a[id] += x;
                k--;
                if (k == 0) {
                    ans();
                }
            }
        }
    }
    set< pair<ll, int> > s;
    for (int i = 0; i < n; i++) {
        s.insert({abs(a[i]), i});
    }
    while (k > 0) {
        auto q = * s.begin();
        s.erase(s.begin());
        int id = q.se;
        if (a[id] >= 0) {
            a[id] += x;
        } else {
            a[id] -= x;
        }
        k--;
        s.insert({abs(a[id]), id});
    }
    ans();
}
