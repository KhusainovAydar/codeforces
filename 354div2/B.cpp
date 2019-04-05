#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'

using namespace std;
const int NMAX = 565;
double m[20][NMAX * 2];
 int n, t;

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    int kk = 0;
    while (kk < t){
        m[0][0] += 1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j <= i; j++){
                m[i+1][j] += max(double(0), (m[i][j] - 1) / 2);
                m[i+1][j+1] += max(double(0), (m[i][j] - 1) / 2);
                m[i][j] -= max(double(0), (m[i][j] - 1));
            }
        }
        kk++;
    }
    double res = 0;
    for (int i = 0; i < n; i++){
    for (int j = 0; j <= i; j++){
    res += (m[i][j] >= 1);
    }
    }
    cout << res;
}
