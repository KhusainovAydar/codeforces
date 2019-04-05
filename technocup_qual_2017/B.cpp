#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
#define pb push_back
//#define pi 3.1415926535897932384626433832795
#define eps 0.0001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define pb push_back
#define MAX (MIN * (-1) + 100)
#define MOD 1000000007

using namespace std;

typedef long long ll;

bool used[100000];

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
    //#else
    //    freopen("movetofront.in", "r", stdin);
    //    freopen("movetofront.out", "w", stdout);
#endif
    string s;
    cin >> s;
    int pos1 = 0;
    vector<string> lol;
    string x = "";
    int n = (int)s.length();
    bool ch = false;
    while (pos1 < n) {
        if (isalpha(s[pos1])) {
            ch = false;
            if (x != "") {
                lol.push_back(x);
                x = "";
            }
        } else {
            ch = true;
            x += s[pos1];
        }
        pos1++;
    }
    if (x != "") {
        lol.push_back(x);
    }
//    cout << lol.size() << endl;
//    for (auto t : lol) {
//        cout << t << endl;
//    }
    int cop = 0;
    for (int i = 0; i < lol.size(); i++) {
        if (lol[i].size() >= 3 && lol[i][lol[i].size() - 3] == '.') {
            used[i] = 1;
            cop += (lol[i][lol[i].size() - 2] - '0') * 10 + (lol[i][lol[i].size() - 1] - '0');
        }
    }
    ll ans = 0;
    for (int i = 0; i < lol.size(); i++) {
        if (used[i]) {
            ll sum = 0;
            for (int j = 0; j < lol[i].size() - 2; j++) {
                if (lol[i][j] == '.') continue;
                sum = sum * 10 + lol[i][j] - '0';
            }
            ans += sum;
        } else {
            ll sum = 0;
            for (int j = 0; j < lol[i].size(); j++) {
                if (lol[i][j] == '.') continue;
                sum = sum * 10 + lol[i][j] - '0';
            }
            ans += sum;
        }
    }
    ans += cop / 100;
    cop %= 100;
    string k = "";
    while (ans > 0) {
        k += ans % 10 + '0';
        ans /= 10;
    }
    string u = "";
    for (int i = 0; i < k.size(); i++) {
        u += k[i];
        if ((i + 1) % 3 == 0) {
            u += '.';
        }
    }
    reverse(u.begin(), u.end());
    for (int i = 0; i < u.size(); i++) {
        if (i == 0 && u[i] == '.') {
            continue;
        }
        cout << u[i];
    }
    if (u == "") {
        cout << 0;
    }
    if (cop != 0) {
        cout << '.';
        if (cop < 10) {
            cout << 0;
        }
        cout << cop;
    }
}
