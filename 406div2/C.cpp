#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define ll ll
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x );
inline void writeWord( const char *s );

/** Read */

static const int buf_size = 4096;

inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len)
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    if (pos == len)
        return -1;
    return buf[pos++];
}

inline int readChar() {
    int c = getChar();
    while (c <= 32)
        c = getChar();
    return c;
}

template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
    if (write_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt( T x, char end ) {
    if (x < 0)
        writeChar('-'), x = -x;

    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}

inline void writeWord( const char *s ) {
    while (*s)
        writeChar(*s++);
}

struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;

const int NMAX = 10000;

int n;
int sz[2];
int a[2][NMAX], used[2][NMAX], sos[2][NMAX], deg[2][NMAX];;

void dfs(int v, int u) {
    used[v][u] = 1;

    int nid = v ^ 1;
    for (int i = 0; i < sz[v ^ 1]; ++i) {
        int nu = (u - a[v ^ 1][i] + n) % n;
        if (!used[nid][nu]) {
            if (sos[v][u] == -1) {
                sos[nid][nu] = 1;
                dfs(nid, nu);
            } else {
                if (--deg[nid][nu] == 0) {
                    sos[nid][nu] = -1, dfs(nid, nu);
                }
            }
        }
    }
}


int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
//    freopen("alligator.in", "r", stdin);
//    freopen("alligator.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < 2; i++) {
        cin >> sz[i];
        for (int j = 0; j < sz[i]; j++) {
            cin >> a[i][j];
        }
    }
    fill(deg[0], deg[0] + n - 1, sz[0]);
    fill(deg[1], deg[1] + n - 1, sz[1]);
    sos[0][n - 1] = -1;
    used[0][n - 1] = 1;
    sos[1][n - 1] = -1;
    used[0][n - 1] = 1;
    dfs(1, n - 1);
    dfs(0, n - 1);
    for (int i = 0; i < n - 1; i++) {
        if (sos[0][i] == -1) {
            cout << "Lose" << ' ';
        } else if (sos[0][i] == 1) {
            cout << "Win" << ' ';
        } else {
            cout << "Loop" << ' ';
        }
    }
    cout << endl;
    for (int i = 0; i < n - 1; i++) {
        if (sos[1][i] == -1) {
            cout << "Lose" << ' ';
        } else if (sos[1][i] == 1) {
            cout << "Win" << ' ';
        } else {
            cout << "Loop" << ' ';
        }
    }
    cout << endl;
}
