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

ll size(ll num) {
    ll l = 0, r = INT_MAX;
    while (r - l > 1) {
        ll m = (r + l) >> 1;
        if ((m * (m - 1)) / 2 > num) {
            r = m;
        } else {
            l = m;
        }
    }
    return l;
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*#if __APPLE__
     freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
     freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
     #endif*/
    ll a00, a01, a10, a11;
    cin >> a00 >> a01 >> a10 >> a11;
    if (a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0) {
        cout << 0;
        return 0;
    }
    ll c0 = size(a00), c1 = size(a11);
    
    if ((c0 * (c0 - 1)) / 2 != a00 || (c1 * (c1 - 1)) / 2 != a11) {
        cout << "Impossible";
        return 0;
    }

    if (a00 == 0 && a01 == 0 && a10 == 0) {
        string s = "";
        if (c1 > 1000000) {
            cout << "Impossble";
            return 0;
        }
        for (int i = 0; i < c1; i++) {
            s += '1';
        }
        cout << s;
        return 0;
    }
    if (a10 == 0 && a01 == 0 && a11 == 0) {
        string s = "";
        if (c0 > 1000000) {
            cout << "Impossible";
            return 0;
        }
        for (int i = 0; i < c0; i++) {
            s += '0';
        }
        cout << s;
        return 0;
    }
    if (c1 + c0 > 1000000) {
        cout << "Impossible";
        return 0;
    }
    {
        if (a01 + a10 != c0 * c1) {
            cout << "Impossible";
            return 0;
        }
        string b = "";
        if (a01 >= a10) {
            for (int i = 0; i < c0; i++) {
                b += '0';
            }
            for (int i = 0; i < c1; i++) {
                b += '1';
            }
            ll first = c0 - 1, second = (int)b.size() - 1;
            ll cnt = 0;
            while (cnt + c1 <= a10) {
                swap(b[first], b[second]);
                first--, second--;
                cnt += c1;
            }
            while (cnt + c1 > a10) {
                c1--;
                second--;
            }
            swap(b[first], b[second]);
            cout << b;
            return 0;
        } else {
            for (int i = 0; i < c1; i++) {
                b += '1';
            }
            for (int i = 0; i < c0; i++) {
                b += '0';
            }
            ll first = c1 - 1, second = (int)b.size() - 1;
            ll cnt = 0;
            while (cnt + c0 <= a01) {
                swap(b[first], b[second]);
                first--;
                second--;
                cnt += c0;
            }
            while (cnt + c0 > a01) {
                c0--;
                second--;
            }
            swap(b[first], b[second]);
            cout << b;
            return 0;
        }
    }
}
