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

int cnt[150];

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
    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int sz = (int)a[i].size();
        cnt[sz]++;
    }
    string ans;
    cin >> ans;
    int kek = (int)ans.size();
    ll A = 0, B = 0;
    for (int i = 1; i <= 150; i++) {
        if (i == kek) {
            A++;
            B += cnt[i] - 0;
            
            cout << (A - 1) / k * 5 + A << ' ' << (B - 1) / k * 5 + B;
            return 0;
        }
        A += cnt[i];
        B += cnt[i];
    }
    assert(false);
}
