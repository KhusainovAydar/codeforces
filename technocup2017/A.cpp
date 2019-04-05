#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back

using namespace std;

typedef long long ll;

const int NMAX = 200005;

bool used[NMAX];
int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++){
        cin >> a[i];
    }
    int cnt = 0;
    int maxx = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (!used[a[i]]) {
            used[a[i]] = 1;
            cnt++;
        } else {
            cnt--;
        }
        maxx = max(maxx, cnt);
    }
    cout << maxx;
}
