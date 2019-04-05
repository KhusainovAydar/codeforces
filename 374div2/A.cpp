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
//    freopen("pwgen.in", "r", stdin);
//    freopen("pwgen.out", "w", stdout);
#endif
    int n;
    string s;
    cin >> n >> s;
    vector<int> ans;
    int cnt = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == 'W') {
            if (cnt > 0) {
                ans.push_back(cnt);
            }
            cnt = 0;
        } else  {
            cnt++;
        }
    }
    if (cnt > 0) {
        ans.push_back(cnt);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
}
