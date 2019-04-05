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

char mas[150][150];
bool used[150][150];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
bool ch = false;

vector< pair<int, pair<int, int> > > d;

int val = 0;
void dfs(int x, int y) {
    if (x == n - 1 || y == m - 1 || x == 0 || y == 0) {
        ch = false;
    }
    val++;
    used[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && !used[nx][ny] && mas[nx][ny] == '.') {
            dfs(nx, ny);
        }
    }
}

void dfs2(int x, int y) {
    val++;
    used[x][y] = 1;
    mas[x][y] = '*';
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && !used[nx][ny] && mas[nx][ny] == '.') {
            dfs2(nx, ny);
        }
    }
}

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
    int k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mas[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!used[i][j] && mas[i][j] == '.') {
                val = 0;
                ch = true;
                dfs(i, j);
                if (ch) {
                    cnt++;
                    d.push_back({val, {i, j}});
                }
            }
        }
    }
    for (int i = 0; i < 150; i++) {
        for (int j = 0; j < 150; j++) {
            used[i][j] = false;
        }
    }
    sort(d.begin(), d.end());
    val = 0;
    //cout << cnt << ' ' << k << endl;
    for (int i = 0; i < cnt - k; i++) {
        dfs2(d[i].se.fi, d[i].se.se);
    }
    cout << val << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mas[i][j];
        }
        cout << endl;
    }
}
