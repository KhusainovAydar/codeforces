#include <bits/stdc++.h>
#define times clock() * 1.0 / CLOCKS_PER_SEC
//#define pi 3.1415926535897932384626433832795
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int long long
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

// oxxxy vseravno pobedil

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int NMAX = 55;
int n, m;
char a[NMAX][NMAX], b[NMAX][NMAX];

bool usedA[NMAX], usedB[NMAX];

bool check(vector<int> & A, vector<int> & B) {
    for (auto t : A) {
        if (usedA[t]) {
            return false;
        }
    }
    for (auto t : B) {
        if (usedB[t]) {
            return false;
        }
    }
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            if (a[A[i]][B[j]] == '.') {
                return false;
            }
            b[A[i]][B[i]] = '#';
        }
    }
    for (auto t : A) {
        usedA[t] = true;
    }
    for (auto t : B) {
        usedB[t] = true;
    }
    return true;
}

int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
//        freopen("lca2.in", "r", stdin);
//    freopen("lca2.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <=n ;i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            b[i][j] = '.';
        }
    }

    for (int fir = 1; fir <= n; fir++) {
        if (usedA[fir]) {
            continue;
        }
        vector<int> A, B;
        for (int sec = 1; sec <= m; sec++) {
            if (usedB[sec]) continue;
            if (a[fir][sec] == '#') {
                for (int thi = 1; thi <= n; thi++) {
                    if (usedA[thi]) continue;
                    if (a[thi][sec] == '#') {
                        A.push_back(thi);
                        B.push_back(sec);
                    }
                }
            }
        }
        if (!check(A, B)) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != b[i][j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
