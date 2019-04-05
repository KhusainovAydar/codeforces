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

vector<int> a, t;

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


void upd(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t[v] = val;
    } else {
        int tm = (tl + tr) >> 1;
        if (pos <= tm) {
            upd(2 * v + 1, tl, tm, pos, val);
        } else {
            upd(2 * v + 2, tm + 1, tr, pos, val);
        }
        t[v] = (t[2 * v + 1] ^ t[2 * v + 2]);
    }
}

int getxor(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (tl == l && tr == r) {
        return t[v];
    }
    int tm = (tl + tr) >> 1;
    int A = getxor(2 * v + 1, tl, tm, l, min(tm, r));
    int B = getxor(2 * v + 2, tm + 1, tr, max(tm + 1, l), r);
    return (A ^ B);
}


struct Z {
    int fi, se, num;
};

bool cmp(Z A, Z B) {
    return A.se < B.se;
}

map<int, int> last;
int ans[1234567];

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*#if __APPLE__
     freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
     freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
     #endif*/
    int n = readInt();
    a.resize(n + 1);
    t.resize(n * 4, 0);
    for (int i = 1; i <= n; i++) {
        a[i] = readInt();
    }
    vector<int> prefsum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefsum[i] = prefsum[i - 1] ^ a[i];
    }
    vector< Z > srt;
    int m = readInt();
    srt.resize(m);
    for (int i = 0; i < m; i++) {
        srt[i].fi = readInt();
        srt[i].se = readInt();
        srt[i].num = i;
    }
    sort(srt.begin(), srt.end(), cmp);
    int x = 1;
    for (int i = 0; i < m; i++) {
        for (; x <= srt[i].se; x++) {
            //cnt[last[a[x]]] = 0;
            int val = last[a[x]];
            if (val != 0)
                upd(0, 0, n - 1, val - 1, 0);
            last[a[x]] = x;
            //cnt[x] = a[x];
            upd(0, 0, n - 1, x - 1, a[x]);
        }
        int kek = getxor(0, 0, n - 1, srt[i].fi - 1, srt[i].se - 1);
        //int lol = 0;
        //for (int j = srt[i].fi; j <= srt[i].se; j++) {
        //    lol ^= cnt[j];
        //}
        //cout << kek << ' ' << lol << endl;
        ans[srt[i].num] = (kek ^ (prefsum[srt[i].se] ^ prefsum[srt[i].fi - 1]));
    }
    for (int i = 0; i < srt.size(); i++) {
        writeInt(ans[i]);
        writeChar(endl);
    }
}
