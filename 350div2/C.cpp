#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;

map<int, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    int k;
    cin >> k;
    vector<pair<int, int> > mas(k);
    vector<pair<int, int> > ans;
    for (int i = 0; i < k; i++) {
        cin >> mas[i].fi;
    }
    for (int i = 0; i < k; i++) {
        cin >> mas[i].se;
    }
    for (int i = 0; i < k; i++) {
        int ans1 = mp[mas[i].fi];
        int ans2 = mp[mas[i].se];
        ans.push_back({ans1, ans2});
    }
    sort(ans.rbegin(), ans.rend());
    for (int i = 0; i < k; i++) {
        if (mp[mas[i].fi] == ans[0].fi && mp[mas[i].se] == ans[0].se) {
            cout << i + 1;
            return 0;
        }
    }
}
