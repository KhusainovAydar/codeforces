#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'

using namespace std;
typedef long long ll;

const int NMAX = 5005;

bool w[NMAX];
bool used[NMAX][NMAX];
int a, b, c, d;

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    if (n == 4) {
        cout << -1;
        return 0;
    }
    if (k < n + 1) {
        cout << -1;
        return 0;
    }
    cin >> a >> b >> c >> d;
    w[a] = w[b] = w[c] = w[d] = true;
    vector<int> first, second;
    first.push_back(a);
    first.push_back(c);
    for (int i = 1; i <= n; i++) {
        if (!w[i]) first.push_back(i);
    }
    first.push_back(d);
    first.push_back(b);
    second.push_back(c);
    second.push_back(a);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!w[i]) second.push_back(i);
    }
    second.push_back(b);
    second.push_back(d);

    for (int i = 0; i < first.size(); i++) {
        cout << first[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < second.size(); i++) {
        cout << second[i] << ' ';
    }

}
