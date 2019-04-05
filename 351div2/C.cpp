#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'

using namespace std;
typedef long long ll;

const int NMAX = 5005;

int ans[NMAX];
int b[NMAX];

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        memset(b, 0, sizeof b);
        int j = i;
        int cur = j;
        for (j = i; j < n; j++) {
            b[a[j]]++;
            if (b[a[j]] > b[a[cur]] || (b[a[j]] == b[a[cur]] && a[cur] > a[j])) {
                cur = j;
            }
            ans[a[cur]]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}
