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

bool check(ll a, ll b, ll c) {
    return (a + b > c && b + c > a && c + a > b);
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
/*#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#endif*/
    ll x, y;
    cin >> x >> y;
    ll a = y, b = y, c = y;
    ll ans = 0;
    if (x == y) {
        cout << 0;
        return 0;
    }
    ll cnt = 0;
    swap(x, y);
    while (true) {
        vector<ll> v(3, 0);
        v[0] = a;
        v[1] = b;
        v[2] = c;
        sort(v.begin(), v.end());
        a = v[0], b = v[1], c = v[2];
        bool ch = false;
        while (check(a, b, c) && a <= y) {
            if (a != y)
                ch = true;
            a++;
        }
        a--;
        v[0] = a;
        v[1] = b;
        v[2] = c;
        sort(v.begin(), v.end());
        a = v[1], b = v[0], c = v[2];
        //cout << a << ' ' << b << ' ' << c << endl;
        cnt += ch;
        ch = false;
        while (check(a, b, c) && b <= y) {
            if (b != y)
                ch = true;
            b++;
        }
        b--;
        
        //cout << a << ' ' << b << ' ' << c << endl;
        v[0] = a;
        v[1] = b;
        v[2] = c;
        sort(v.begin(), v.end());
        a = v[2], b = v[1], c = v[0];
        cnt += ch;
        ch = false;
        while (check(a, b, c) && c <= y) {
            if (c != y)
                ch = true;
            c++;
        }
        c--;
        
        //cout << a << ' ' << b << ' ' << c << endl;
        cnt += ch;
        if (a == b && b == c && a == y) {
            break;
        }
    }
    cout << cnt;
}
