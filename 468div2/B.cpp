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

int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
//    freopen("lca2.in", "r", stdin);
//    freopen("lca2.out", "w", stdout);
#endif
    int n, a, b;
    cin >> n >> a >> b;
    int cur = 0;
    vector<int> nums;
    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
    }
    if (a > b) {
        swap(a, b);
    }
    int raun = 0;
    while (n > 1) {
        raun++;
        n /= 2;
    }

    for (int i = 1; i <= raun; i++) {
        vector<int> P;
//        for (int j = 0; j < nums.size(); j++) {
//            cout << nums[j] << ' ';
//        }
//        cout << endl;
        for (int j = 0; j < nums.size(); j += 2) {
            int x = nums[j];
            int y = nums[j + 1];
            if (x == a && y == b) {
                if (i == raun) {
                    cout << "Final!" << endl;
                    return 0;
                } else {
                    cout << i << endl;
                    return 0;
                }
            }
            if (x == a || x == b) {
                P.push_back(x);
            } else {
                P.push_back(y);
            }
        }
        nums = P;
    }

}
