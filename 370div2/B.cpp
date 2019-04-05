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
    string s;
    cin >> s;
    int n = (int)s.length();
    if (n % 2 != 0) {
        cout << -1;
        return 0;
    }
    int x = 0, y = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == 'L') {
            x--;
        }
        if (s[i] == 'R') {
            x++;
        }
        if (s[i] == 'U') {
            y++;
        }
        if (s[i] == 'D') {
            y--;
        }
    }
    cout << (abs(x) + abs(y)) / 2;
}
