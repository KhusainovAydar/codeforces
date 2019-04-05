#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000000000
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
//audarsosethui
using namespace std;

typedef long long ll;

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        if (a[0] == 15) {
            cout << "DOWN";
            return 0;
        }
        if (a[0] == 0) {
            cout << "UP";
            return 0;
        }
        cout << -1;
        return 0;
    }
    int last = a.back();
    int lastlast = a[a.size() - 2];
    if (last > lastlast) {
        if (last == 15) {
            cout << "DOWN";
            return 0;
        } else {
            cout << "UP";
            return 0;
        }
    } else {
        if (last == 0) {
            cout << "UP";
        } else {
            cout << "DOWN";
        }
        return 0;
    }
}
