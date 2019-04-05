#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
#define pb push_back
#define INF 10000000
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define MAX (MIN * (-1) + 100)

using namespace std;

typedef long long ll;

const int NMAX = 100000;

int cnt[27];

set<int> used[27];

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#endif
    int m;
    cin >> m;
    string s;
    cin >> s;
    int n = (int)s.length();
    int L = 0, R = 0;
    vector< pair<int, int> > a;
    while (R < m) {
        int c = s[R] - 'a';
        used[c].insert(R);
        cnt[c]++;
        R++;
    }
    R--;
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            a.push_back({i, *used[i].rbegin()});
            break;
        }
    }
    while (R < n - 1) {
        //cout << L << ' ' << R << ' ' << R - L + 1 << endl;
        int c = s[L] - 'a';
        cnt[c]--;
        used[c].erase(L);
        L++;
        R++;
        c = s[R] - 'a';
        cnt[c]++;
        used[c].insert(R);
        for (int i = 0; i < 26; i++) {
            if (cnt[i]) {
                int last = *used[i].rbegin();
                pair<int, int> x = {i, *used[i].begin()};
                if (x.fi < a.back().fi) {
                    a.push_back({x.fi, last});
                } else if (x.fi == a.back().fi) {
                    if (a.back().se < x.se) {
                        a.push_back({x.fi, last});
                    }
                } else if (x.fi > a.back().fi) {
                    a.push_back({x.fi, last});
                }
                break;
            }
        }
    }
    sort(a.begin(), a.end());
    int val = 0;
    for (int i = 1; i < (int)a.size(); i++) {
        if (a[i].fi != a[i - 1].fi) val++;
    }
    sort(s.begin(), s.end());
    int last = a.back().fi;
    for (int i = 0; i < n; i++) {
        if (s[i] < last + 'a') {
            cout << s[i];
        }
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i].fi == last) {
            cout << char(last + 'a');
        }
    }
    return 0;
    if (!val) {
        for (int i = 0; i < (int)a.size(); i++) {
            cout << char(a[i].fi + 'a');
        }
    } else {
        int cur[27];
        for (int i = 0; i < 26; i++) {
            cur[i] = 0;
        }
        int last = 0;
        for (int i = 0; i < n; i++) {
            cur[s[i] - 'a']++;
        }
        last = a.back().fi;
        for (int i = 0; i < cur[a[0].fi]; i++) {
            cout << char(a[0].fi + 'a');
        }
        for (int i = 1; i < a.size(); i++) {
            if (a[i].fi != a[i - 1].fi && a[i].fi != a.back().fi) {
                for (int j = 0; j < cur[a[i].fi]; j++) {
                    cout << char(a[i].fi + 'a');
                }
            }
        }
        for (int i = 0; i < a.size(); i++) {
            if (a[i].fi == a.back().fi) {
                cout << char(a[i].fi + 'a');
            }
        }
    }
}
