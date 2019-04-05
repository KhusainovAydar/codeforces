#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define rand() ((rand() << 16) + rand())
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
//#define MIN -2147483648
//#define MAX (MIN * (-1) + 100)
//#define MOD 1000000007

using namespace std;

typedef unsigned long long ll;

int cnt[1000000];

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        for (int j = 2; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                cnt[j]++;
                if (a[i] / j != j) {
                    cnt[a[i] / j]++;
                }
            }
        }
    }
    int maxx = 1;
    for (int i = 2; i < 1000000; i++) {
        maxx = max(maxx, cnt[i]);
    }
    cout << maxx;
}
