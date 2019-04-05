#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'

using namespace std;
typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    if (a[0] > 15) {
        cout << 15;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] > 15) {
            cout << a[i - 1] + 15;
            return 0;
        }
    }
    if (90 - a[n - 1] > 15) {
        cout << a[n - 1] + 15;
        return 0;
    }
    cout << 90;
    return 0;
}
