#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000000000
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

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


vector< vector<int> > g;

struct Zapr {
    int num;
    int type;
    int x, y;
};
int n, m;

map<int, int> ans;
vector<Zapr> zap;

int mas[1500][1500];
int sum;

void dfs(int v) {
    //cout << v << ' ' << p << endl;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (zap[to].type == 1) {
            int x = zap[to].x;
            int y = zap[to].y;
            int lastx = x;
            int lasty = y;
            int ch = 0;
            int val = mas[x][y];
            mas[x][y] = 1;
            if (val != mas[x][y])
                sum++, ch--;
            int cnt = sum;
            ans[to] = cnt;
            dfs(to);
            sum += ch;
            mas[lastx][lasty] = val;
        }
        if (zap[to].type == 2) {
            int x = zap[to].x;
            int y = zap[to].y;
            int lastx = x;
            int lasty = y;
            int val = mas[x][y];
            mas[x][y] = 0;
            int ch = 0;
            if (val != mas[x][y])
                sum--, ch++;
            int cnt = sum;
            ans[to] = cnt;
            dfs(to);
            sum += ch;
            mas[lastx][lasty] = val;
        }
        if (zap[to].type == 3) {
            int x = zap[to].x;
            int lastx = x;
            int ch = 0;
            for (int y = 1; y < m; y++) {
                if (mas[x][y] == 1) {
                    sum--, ch++;
                    mas[x][y] = 0;
                } else {
                    sum++, ch--;
                    mas[x][y] = 1;
                }
            }
            ans[to] = sum;
            dfs(to);
            sum += ch;
            for (int y = 1; y < m; y++) {
                if (mas[x][y] == 1) {
                    mas[x][y] = 0;
                } else {
                    mas[x][y] = 1;
                }
            }
        }
        if (zap[to].type == 4) {
            int cnt = sum;
            ans[to] = cnt;
            dfs(to);
        }
    }
}

int main() {
    srand((unsigned int)time(NULL));
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    #if __APPLE__
     freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
     freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
     #endif
    int q;
    n = readInt(), m = readInt(), q = readInt();
    n++, m++;
    zap.resize(q + 1);
    for (int i = 1; i <= q; i++) {
        zap[i].num = i;
        zap[i].type = readInt();
        if (zap[i].type == 1 || zap[i].type == 2)
            zap[i].x = readInt(), zap[i].y = readInt();
        else
            zap[i].x = readInt();
    }
    g.resize(q + 123);
    for (int i = 1; i <= q; i++) {
        if (zap[i].type == 4) {
            g[zap[i].x].push_back(i);
            //g[i].push_back(zap[i].x);
        } else {
            //g[i].push_back(i - 1);
            g[i - 1].push_back(i);
        }
    }
    dfs(0);
    for (int i = 1; i <= q; i++) {
        writeInt(ans[i]);
        writeChar(endl);
    }
}
