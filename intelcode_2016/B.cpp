#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
#define pb push_back
#define INF 10000000
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define MAX (MIN * (-1) + 100)

using namespace std;

typedef long long ll;


int mas[25][25], ans[25][25], a[25];

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mas[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        a[i] = i + 1;
    }
    bool check = 1;
    for (int x = 0; x < n; x++) {
        int val = 0;
        for (int y = 0; y < m; y++) {
            if (mas[x][y] != a[y])
                val++;
        }
        if (val > 2) {
            check = 0;
        }
    }
    if (check) {
        cout << "YES";
        return 0;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    ans[x][y] = mas[x][y];
                }
            }
            for (int x = 0; x < n; x++) {
                swap(ans[x][i], ans[x][j]);
            }
            bool check = 1;
            for (int x = 0; x < n; x++) {
                int val = 0;
                for (int y = 0; y < m; y++) {
                    if (ans[x][y] != a[y])
                        val++;
                }
                if (val > 2) {
                    check = 0;
                }
            }
            if (check) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}
