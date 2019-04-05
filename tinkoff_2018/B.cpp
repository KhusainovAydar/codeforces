#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int long long
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int NMAX = 1005;
char c[NMAX][NMAX];
int used[NMAX][NMAX];
bool win[NMAX][NMAX];
int dist[NMAX][NMAX];
int n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool ch(int x, int y) {
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("cinema.in", "r", stdin);
    //    freopen("cinema.out", "w", stdout);
#endif
    for (int i = 0; i < NMAX; i++) {
        for (int j = 0; j < NMAX; j++) {
            dist[i][j] = INT_MAX;
        }
    }
    cin >> n >> m;
    int start_x = -1, start_y = -1, finish_x = -1, finish_y = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if (c[i][j] == 'S') {
                start_x = i, start_y = j;
            }
            if (c[i][j] == 'T') {
                finish_x = i, finish_y = j;
            }
        }
    }
    win[finish_x][finish_y] = 1;
    for (int i = 0; i < 4; i++) {
        int x = finish_x, y = finish_y;
        for (int j = 0; ; j++) {
            x += dx[i];
            y += dy[i];
            if (ch(x, y) && c[x][y] != '*') {
                win[x][y] = 1;
            } else {
                break;
            }
            for (int i2 = 0; i2 < 4; i2++) {
                if ((i2 % 2) + (i % 2) == 1) {
                    for (int cnt = 0; ; cnt++) {
                        int nx = x + dx[i2] * cnt;
                        int ny = y + dy[i2] * cnt;
                        if (ch(nx, ny) && c[nx][ny] != '*') {
                            win[nx][ny] = 1;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        int x = start_x, y = start_y;
        for (int j = 0; ; j++) {
            x += dx[i];
            y += dy[i];
            if (ch(x, y) && c[x][y] != '*') {
                if (win[x][y]) {
                    cout << "YES";
                    return 0;
                }
            } else {
                break;
            }
        }
    }
    cout << "NO";

}
