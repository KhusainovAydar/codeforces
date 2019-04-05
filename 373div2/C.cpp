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
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    int pos = 0;
    while (pos < n && s[pos] != '.')
        pos++;
    pos++;
    while (pos < n && s[pos] >= '0' && s[pos] <= '4') {
        pos++;
    }
    if (pos == n) {
        cout << s;
        return 0;
    }
    pos--;
    t--;
    int cnt = 0;
    while (s[pos] != '.' && s[pos] >= '4' && s[pos] <= '9' && t > 0) {
        pos--;
        t--;
        cnt = 1;
    }
    if (s[pos] != '.') {
        //cout << pos << endl;
        for (int i = 0; i < pos; i++) {
            cout << s[i];
        }
        cout << char(s[pos] + 1);
        return 0;
    }
    pos--;
    int ans = pos + 1;
    while (s[pos] == '9' && pos > 0) {
        s[pos] = '0';
        pos--;
    }
    if (pos == 0) {
        if (s[pos] == '9') {
            cout << 1;
            for (int i = 0; i < ans; i++) {
                cout << 0;
            }
            return 0;
        } else {
            cout << char(s[pos] + 1);
            for (int i = 1; i < ans; i++) {
                cout << 0;
            }
            return 0;
        }
    } else {
        s[pos] = char(s[pos] + 1);
        for (int i = 0; i < ans; i++) {
            cout << s[i];
        }
        return 0;
    }
}
