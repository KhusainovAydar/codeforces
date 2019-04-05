#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 10000000
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll

using namespace std;

typedef long long ll;

map<int, int> cnt;

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
    //#else
    //    freopen("distances.in", "r", stdin);
    //    freopen("distances.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        cnt[a[i]]++;
    }
    int ans = 0;
    int kek = n / m;
    set< pair<int, int> > s;
    for (int i = 1; i <= m; i++) {
        s.insert({cnt[i], i});
    }
    
    for (int i = 0; i < n; i++) {
        if (a[i] > m) {
            int num = s.begin()->se;
            int val = s.begin()->fi;
            val++;
            cnt[a[i]]--;
            a[i] = num;
            cnt[num]++;
            ans++;
            s.erase(s.begin());
            s.insert({val, num});
        }
    }
    int sum = 0;
    for (auto t : s) {
        sum += t.fi;
    }
    for (int i = 0; i < n; i++) {
        int num = s.begin()->se;
        int val = s.begin()->fi;
        if (val == kek) break;
        if (num == a[i]) continue;
        if (cnt[a[i]] > kek) {
            cnt[a[i]]--;
            cnt[num]++;
            a[i] = num;
            ans++;
            s.erase(s.begin());
            val++;
            s.insert({val, num});
        }
    }
    for (int i = 0; i < n; i++) {
        if (b[i] > m) {
            if (cnt[a[i]] > kek) {
                cnt[a[i]]--;
                a[i] = b[i];
                ans--;
            }
        }
    }
    cout << s.begin()->fi << ' ' << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}
