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

int mas[10];
int ans[10];

bool used[100005];

int main() {
    //srand((unsigned int)time(NULL));
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
//#if __APPLE__
//    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
//    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
//    //#else
//    //    freopen("movetofront.in", "r", stdin);
//    //    freopen("movetofront.out", "w", stdout);
//#endif
    for (int i = 0; i < 6; i++) {
        cin >> mas[i];
    }
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == ',') {
                used[i] = 1;
            }
        }
    }
    vector<string> a(n);
    for (int i = 0; i < n;i++) {
        if (used[i]) continue;
        if (v[i] == "S") {
            ans[0]++;
        } else if (v[i] == "M") {
            ans[1]++;
        } else if (v[i] == "L") {
            ans[2]++;
        } else if (v[i] == "XL") {
            ans[3]++;
        } else if (v[i] == "XXL") {
            ans[4]++;
        } else if (v[i] == "XXXL") {
            ans[5]++;
        }
        a[i] = v[i];
    }
    for (int i = 0; i < 6; i++) {
        if (ans[i] > mas[i]) {
            cout << "NO";
            return 0;
        }
    }
    vector< pair< pair<int, int>, int> > scan;
    for (int i = 0; i < n; i++) {
        if (!used[i]) continue;
        int x1 = -1, x2 = -1;
        string s = "";
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == ',') {
                if (s == "S") {
                    x1 = 0;
                } else if (s == "M") {
                    x1 = 1;
                } else if (s == "L") {
                    x1 = 2;
                } else if (s == "XL") {
                    x1 = 3;
                } else if (s == "XXL") {
                    x1 = 4;
                } else if (s == "XXXL") {
                    x1 = 5;
                }
                s = "";
            } else {
                s += v[i][j];
            }
        }
        if (s == "S") {
            x2 = 0;
        } else if (s == "M") {
            x2 = 1;
        } else if (s == "L") {
            x2 = 2;
        } else if (s == "XL") {
            x2 = 3;
        } else if (s == "XXL") {
            x2 = 4;
        } else if (s == "XXXL") {
            x2 = 5;
        }
        s = "";
        scan.push_back({{x1, x2}, i});
    }
    sort(scan.begin(), scan.end());
    for (int i = 0; i < scan.size(); i++) {
        int x1 = scan[i].fi.fi;
        int x2 = scan[i].fi.se;
        if (ans[x1] + 1 > mas[x1]) {
            ans[x2]++;
            string kek = "";
            if (x2 == 0) {
                kek = "S";
            } else if (x2 == 1) {
                kek = "M";
            } else if (x2 == 2) {
                kek = "L";
            } else if (x2 == 3) {
                kek = "XL";
            } else if (x2 == 4) {
                kek = "XXL";
            } else if (x2 == 5) {
                kek = "XXXL";
            }
            a[scan[i].se] = kek;
        } else {
            ans[x1]++;
            string kek = "";
            if (x1 == 0) {
                kek = "S";
            } else if (x1 == 1) {
                kek = "M";
            } else if (x1 == 2) {
                kek = "L";
            } else if (x1 == 3) {
                kek = "XL";
            } else if (x1 == 4) {
                kek = "XXL";
            } else if (x1 == 5) {
                kek = "XXXL";
            }
            a[scan[i].se] = kek;
        }
    }
    for (int i = 0; i < 6; i++) {
        if (ans[i] > mas[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << endl;
    }
}
