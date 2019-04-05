#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 10000000
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll

using namespace std;

typedef long long ll;

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
    //#else
    //    freopen("distances.in", "r", stdin);
    //    freopen("distances.out", "w", stdout);
#endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    int maxx = 0;
    int minn = 0;
    int cnt = 0;
    bool ch = false;
    for (int i = 0; i < (int)s.length(); i++) {
        if (!ch && ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))) {
            cnt++;
        } else {
            maxx = max(maxx, cnt);
            cnt = 0;
        }
        if (s[i] == '(') {
            ch = true;
        }
        if (s[i] == ')') {
            ch = false;
        }
    }
    maxx = max(maxx, cnt);
    cout << maxx;
    ch = false;
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (ch && ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))) {
            cnt++;
        } else {
            if (ch && cnt > 0) {
                minn++;
                cnt = 0;
            }
        }
        if (s[i] == '(') {
            ch = true;
            continue;
        }
        if (s[i] == ')') {
            ch = false;
            continue;
        }
    }
    cout << ' ' << minn;
}
