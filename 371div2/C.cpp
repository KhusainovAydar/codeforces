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

map<string, int> cnt;

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
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            ll a;
            cin >> a;
            string s = "";
            while (a > 0) {
                s += a % 2 + '0';
                a /= 10;
            }
            reverse(s.begin(), s.end());
            while (s.length() < 18) {
                s = '0' + s;
            }
            cnt[s]++;
        } else if (c == '-') {
            ll a;
            cin >> a;
            string s = "";
            while (a > 0) {
                s += a % 2 + '0';
                a /= 10;
            }
            reverse(s.begin(), s.end());
            while (s.length() < 18) {
                s = '0' + s;
            }
            cnt[s]--;
        } else if (c == '?') {
            string s;
            cin >> s;
            while ((int)s.length() < 18) {
                s = '0' + s;
            }
            cout << cnt[s] << endl;
        }
    }
}
