#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int l = -1;
    int r = n + 1;
    if (m == 0) {
        cout << n - 1 << endl;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) {
            swap(u, v);
        }
        l = max(l, u);
        r = min(r, v);
    }
    if (l > r) {
        cout << 0 << endl;
    } else {
        cout << r - l << endl;
    }
}
