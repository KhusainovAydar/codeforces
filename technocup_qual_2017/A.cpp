#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
#define pb push_back
//#define pi 3.1415926535897932384626433832795
#define eps 0.0001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define pb push_back
#define MAX (MIN * (-1) + 100)
#define MOD 1000000007

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
    //    freopen("movetofront.in", "r", stdin);
    //    freopen("movetofront.out", "w", stdout);
#endif
    ll a, b;
    cin >> a >> b;
    vector<ll> ans;
    ans.push_back(b);
    while (b > a) {
        if (b % 10 == 1 && b / 10 >= a) {
            b /= 10;
            ans.push_back(b);
        } else {
            if (b % 2 == 0 && b / 2 >= a) {
                b /= 2;
                ans.push_back(b);
            } else {
                cout << "NO";
                return 0;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
}
