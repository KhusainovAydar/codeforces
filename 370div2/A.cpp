#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000000000
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
/*#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#endif*/
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> b(n);
    reverse(a.begin(), a.end());
    b[0] = a[0];
    for (int i = 1; i < n; i++) {
        if (i % 2)
            b[i] = a[i - 1] + a[i];
        else
            b[i] = a[i - 1] + a[i];
    }
    reverse(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        cout << b[i] << ' ';
    }
}
