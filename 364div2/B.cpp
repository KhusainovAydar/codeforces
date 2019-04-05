#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    set<long long> x, y;
    for (int i = 1; i <= n; i++) {
        x.insert(i);
        y.insert(i);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (x.find(a) != x.end()) x.erase(a);
        if (y.find(b) != y.end()) y.erase(b);
        cout << (long long)x.size() * (long long)y.size() << endl;
    }
}
