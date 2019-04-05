#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000
#define y1 kek
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#d efine double long double
//#define int ll
using namespace std;

typedef long long ll;


bool ch (const string & a, const string & b) {
    int sz = min((int)a.length(), (int)b.length());
    for (int i = 0; i < sz; i++) {
        if (a[i] > b[i]) {
            return true;
        }
        if (b[i] > a[i]) {
            return false;
        }
    }
    if ((int)a.length() == (int)b.length()) {
        return true;
    }
    if ((int)a.length() == sz) {
        return false;
    } else {
        return true;
    }
}

ll dp[100005][2];

int main() {
    ios_base::sync_with_stdio(false);
    srand((unsigned int)time(NULL));
    /*#if __APPLE__
     freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
     freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
     #else
     freopen("permutation2.in", "r", stdin);
     freopen("permutation2.out", "w", stdout);
     #endif*/
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector< pair<string, string> > S;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string rev = s;
        reverse(rev.begin(), rev.end());
        bool check = false;
        /*for (int j = 0; j < (int)s.length(); j++) {
            if (s[j] < rev[j]) {
                S.push_back({{s, rev}, 0});
                check = true;
                break;
            }
            if (s[j] > rev[j]) {
                S.push_back({{rev, s}, 1});
                check = true;
                break;
            }
        }*/
        if (!check) {
            S.push_back({s, rev});
        }
    }
    for (int i = 0; i < 100000; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            string s;
            if (j == 0) {
                s = S[i].fi;
            } else {
                s = S[i].se;
            }
            bool tr = false;
            if (ch(s, S[i - 1].fi) && dp[i - 1][0] != -1) {
                ll cnt = (dp[i][j] == -1 ? LLONG_MAX : dp[i][j]);
                dp[i][j] = min(cnt, dp[i - 1][0]);
                tr = true;
            }
            if (ch(s, S[i - 1].se) && dp[i - 1][1] != -1) {
                ll cnt = (dp[i][j] == -1 ? LLONG_MAX : dp[i][j]);
                dp[i][j] = min(cnt, dp[i - 1][1] + a[i - 1]);
                tr = true;
            }
            if (!tr) {
                dp[i][j] = -1;
            }
        }
    }
    if (dp[n - 1][0] == -1 && dp[n - 1][1] == -1) {
        cout << -1;
        return 0;
    }
    if (dp[n - 1][0] == -1 && dp[n - 1][1] != -1) {
        cout << dp[n - 1][1] + a[n - 1];
        return 0;
    }
    if (dp[n - 1][0] != -1 && dp[n - 1][1] == -1) {
        cout << dp[n - 1][0];
        return 0;
    }
    cout << min(dp[n - 1][0], dp[n - 1][1] + a[n - 1]);
    
}
