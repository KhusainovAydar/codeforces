#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000
#define y1 kek
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#d efine double long double
//#define int ll
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    srand((unsigned int)time(NULL));
/*#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("permutation2.in", "r", stdin);
    freopen("permutation2.out", "w", stdout);
#endif*/
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i] - 1;
        cout << !(sum % 2) + 1 << endl;
    }
}
