#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000
#define y1 kek
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
#define double long double
//#define int ll
using namespace std;

typedef long long ll;

int main() {
    srand((unsigned int)time(NULL));
/*#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("minonpath.in", "r", stdin);
    freopen("minonpath.out", "w", stdout);
#endif*/
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int len = 1;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            cnt++;
            len = max(len, cnt);
        } else {
            len = max(len, cnt);
            cnt = 1;
        }
    }
    cout << len;
}
