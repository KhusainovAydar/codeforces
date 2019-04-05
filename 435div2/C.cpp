#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int long long
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

// oxxxy vseravno pobedil

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int NMAX = 1000010, K = 1000000;

bool used[NMAX];

int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("cinema.in", "r", stdin);
    //    freopen("cinema.out", "w", stdout);
#endif
    vector<ll> find(K + 1);
    for (int i = 0; i < K; i++) {
        find[i] = i + 1;
    }
    random_shuffle(find.begin(), find.end());
    int n, x;
    cin >> n >> x;
    if (x == 0 && n == 2) {
        cout << "NO";
        return 0;
    }
    vector<int> ans;
    ll kek = 0;
    ll cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        used[find[i]] = 1;
        ans.pb(find[i]);
        kek ^= find[i];
    }
    cnt = ans.size() - 1;

    while (true) {
        ll y = (x ^ kek);
        if (y > K || used[y]) {
            cnt = ans.back();
            used[cnt] = 0;
            kek ^= cnt;
            ans.pop_back();
            cnt = rand() % (K - n) + n;
            while (used[find[cnt]]) {
                assert(false);
            }
            used[find[cnt]] = 1;
            kek ^= find[cnt];
            ans.push_back(find[cnt]);
            swap(find[ans.size()], find[cnt]);
        } else {
            ans.pb(y);
            cout << "YES" << endl;
            for (auto t : ans) {
                cout << t << ' ';
            }
            cout << endl;
            return 0;
        }
    }
    cout << "NO";
    return 0;

}
