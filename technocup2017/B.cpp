#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double lld;


const int NMAX = 60001;

lld v[NMAX], x[NMAX];
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    lld L = 0, R = 1000000000000;
    for (int it = 0; it < 100; it++) {
        vector< pair<lld, int> > sca;
        lld M = (L + R) * 0.5;
        for (int i = 0; i < n; i++) {
            sca.pb({x[i] - v[i] * M, 0});
            sca.pb({x[i] + v[i] * M, 1});
        }
        sort(sca.begin(), sca.end());
        bool ch = false;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (sca[i].se == 0) {
                cnt++;
            } else {
                cnt--;
            }
            if (cnt == n) {
                ch = 1;
            }
        }
        if (ch) {
            R = M;
        } else {
            L = M;
        }
    }
    cout.precision(20);
    cout << R;
}
