#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ai, bi;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) ai = i + 1;
        if (a[i] == n) bi = i + 1;
    }
    cout << max(max(bi - 1, n - ai), max(ai - 1, n - bi));

}
