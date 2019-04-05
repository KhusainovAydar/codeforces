#include <bits/stdc++.h>

using namespace std;

int x[1200], y[1200];
int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    char kek[n][m];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> kek[i][j];
            if (kek[i][j] == '*') cnt++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (kek[i][j] == '*') x[i]++;
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (kek[i][j] == '*') y[j]++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (x[i] + y[j] - (kek[i][j] == '*') == cnt) {
                cout << "YES" << endl;
                cout << i + 1 << ' ' << j + 1 << endl;
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
