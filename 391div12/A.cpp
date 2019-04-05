#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define rand() ((rand() << 16) + rand())
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
//#define MIN -2147483648
//#define MAX (MIN * (-1) + 100)
//#define MOD 1000000007

using namespace std;

typedef unsigned long long ll;

string s;

string a = "Bulbasaur";

int cnt[100];

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] - 'A']++;
    }
    int minn = 10000000;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 'a' || a[i] == 'u') {
            minn = min(minn, cnt[a[i] - 'A'] / 2);
        } else {
            minn = min(minn, cnt[a[i] - 'A']);
        }
    }
    cout << minn;
}
