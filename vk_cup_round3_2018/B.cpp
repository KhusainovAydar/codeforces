#include <bits/stdc++.h>
#define times clock() * 1.0 / CLOCKS_PER_SEC
//#define pi 3.1415926535897932384626433832795
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int long long
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS
#define endl '\n'

// oxxxy vseravno pobedil

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled/input.txt", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled/output.txt", "w", stdout);
#else
//        freopen("lca2.in", "r", stdin);
//    freopen("lca2.out", "w", stdout);
#endif
    int n;
    cin >> n;
    ll x1, x2;
    cin >> x1 >> x2;
    vector<pair<ll, int>> a((unsigned long) n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    bool sw = false;
    bool check = true;

    vector<int> ans1;
    int k1 = 0;
    bool good = false;
    for (int i = (int) (a.size() - 1); i >= 0; i--) {
        k1++;
        ans1.push_back(a[i].second + 1);
        if (a[i].first * k1 >= x1) {
            good = true;
            break;
        }
    }
    if (!good) {
        check = false;
    }
    good = false;
    vector<int> ans2;
    for (int i = 0; i < a.size() - k1; i++) {
        int k2 = (int) ((a.size() - k1) - i);
        if (k2 * a[i].first >= x2) {
            good = true;
            for (int j = i; j < a.size() - k1; j++) {
                ans2.push_back(a[j].second + 1);
            }
            break;
        }
    }
    if (!good) {
        check = false;
    }

    if (check) {
        cout << "Yes" << endl;
        cout << ans1.size() << ' ' << ans2.size() << endl;
        for (auto & t : ans1) {
            cout << t << ' ';
        }
        cout << endl;
        for (auto & t : ans2) {
            cout << t << ' ';
        }
        cout << endl;
        return 0;
    }

    check = true;
    swap(x1, x2);

    ans1.clear();
    ans2.clear();

    k1 = 0;
    good = false;
    for (int i = (int) (a.size() - 1); i >= 0; i--) {
        k1++;
        ans1.push_back(a[i].second + 1);
        if (a[i].first * k1 >= x1) {
            good = true;
            break;
        }
    }
    if (!good) {
        check = false;
    }
    good = false;
    for (int i = 0; i < a.size() - k1; i++) {
        int k2 = (int) ((a.size() - k1) - i);
        if (k2 * a[i].first >= x2) {
            good = true;
            for (int j = i; j < a.size() - k1; j++) {
                ans2.push_back(a[j].second + 1);
            }
            break;
        }
    }
    if (!good) {
        check = false;
    }
    if (!check) {
        cout << "No" << endl;
        return 0;
    }
    swap(ans1, ans2);

    cout << "Yes" << endl;
    cout << ans1.size() << ' ' << ans2.size() << endl;
    for (auto & t : ans1) {
        cout << t << ' ';
    }
    cout << endl;
    for (auto & t : ans2) {
        cout << t << ' ';
    }
    cout << endl;
    return 0;
}
