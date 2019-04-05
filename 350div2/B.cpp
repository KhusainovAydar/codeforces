include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;

map<int, int> mp;

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i <n ; i++) {
        cin >> a[i];
        mp[i + 1] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (k > i) {
            k -= i;
        } else {
            cout << mp[k] << endl;
            return 0;
        }
    }
}
