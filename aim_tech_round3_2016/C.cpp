#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define y1 kekkekekekkek
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;
int const INF = 1 << 30;

const int N = 123456, K = 20;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand((unsigned int)time(NULL));
/*#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#endif*/
    string s;
    cin >> s;
    bool b = true;
    bool check = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 'a') {
            check = true;
            s[i]--;
            b = false;
        } else {
            if (!b) break;
        }
    }
    if (!check) {
        for (int i = 0; i < (int)s.length() - 1; i++) {
            cout << s[i];
        }
        cout << 'z';
        return 0;
    }
    cout << s;
}
