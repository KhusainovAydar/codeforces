#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

map<int, int> mp;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int> > a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back({x, i + 1});
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n / 2; i++) {
        cout << a[i].se << ' ' << a[n - i - 1].se << endl;
    }
}
