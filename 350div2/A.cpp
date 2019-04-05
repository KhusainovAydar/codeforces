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
    int minans = 0, maxans = 0;
    if (n == 1) {
        cout << 0 << ' ' << 1;
        return 0;
    }
    for (int i = 5; i <= n; i += 5) {
        if (i + 2 <= n) {
            i += 2;
            minans += 2;
        } else {
            if (i + 1 <= n) {
                i++;
                minans++;
            } else break;
        }
    }
    for (int i = 0; i <= n; i += 5) {
        if (i + 2 <= n) {
            i += 2;
            maxans += 2;
        } else {
            if (i + 1 <= n) {
                i++;
                maxans++;
            } else break;
        }
    }
    cout << minans << ' ' << maxans;

}
