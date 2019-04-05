#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.0001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define MAX (MIN * (-1) + 100)
#define MOD 1000000007
#define dist pesya

using namespace std;

typedef long long ll;

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
//    freopen("grasshopper.in", "r", stdin);
//    freopen("grasshopper.out", "w", stdout);
#endif
    string s;
    cin >> s;
    s = 'A' + s + 'A';
    int minn = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        for (int j = i + 1; j < (int)s.length(); j++) {
            if (s[j] == 'A' || s[j] == 'E' || s[j] == 'O' || s[j] == 'I' || s[j] == 'Y' || s[j] == 'U') {
                minn = max(minn, j - i);
                i = j - 1;
                break;
            }
        }
    }
    cout << minn;
}
