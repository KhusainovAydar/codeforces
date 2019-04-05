#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000
#define y1 kek
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    srand((unsigned int)time(NULL));
/*#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#endif*/
    ll n;
    cin >> n;
    if (n == 1 || n == 2) {
        cout << -1;
        return 0;
    }
    
    ll p = n * n;
    if (n % 2 == 0) {
        cout << p / 4 - 1 << ' ' << p / 4 + 1 << endl;
    } else {
        cout << p / 2 << ' ' << p / 2 + 1 << endl;
    }
}
