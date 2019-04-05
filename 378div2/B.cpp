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
#define dist pesya

using namespace std;

typedef long long ll;

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
    vector< pair<int, int> > a(n);
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
        sum1 += a[i].fi;
        sum2 += a[i].se;
    }
    ll maxx = abs(sum1 - sum2);
    int id = 0;
    for (int i = 0; i < n; i++) {
        ll sum3 = sum1 - a[i].fi + a[i].se;
        ll sum4 = sum2 - a[i].se + a[i].fi;
        if (abs(sum3 - sum4) > maxx) {
            maxx = abs(sum3 - sum4);
            id = i + 1;
        }
    }
    cout << id;
}
