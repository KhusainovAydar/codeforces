#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
#define pb push_back
//#define pi 3.1415926535897932384626433832795
#define eps 0.0001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define pb push_back
#define MAX (MIN * (-1) + 100)
#define MOD 1000000007

using namespace std;

typedef long long ll;

int mas[10000];

int main() {
    //srand((unsigned int)time(NULL));
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
//#if __APPLE__
//    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
//    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
//    //#else
//    //    freopen("movetofront.in", "r", stdin);
//    //    freopen("movetofront.out", "w", stdout);
//#endif
    int n;
    cin >> n;
    int val = n / 3;
    for (int i = 0; i < val; i++) {
        int a = i * 3;
        int b = i * 3 + 1;
        int c = i * 3 + 2;
        cout << '?' << ' ' <<  (a + 1) << ' ' << (b + 1) << endl;
        fflush(stdout);
        int x;
        cin >> x;
        cout <<  '?' << ' ' << (b + 1) << ' ' << (c + 1) << endl;
        fflush(stdout);
        int y;
        cin >> y;
        cout << '?' << ' ' << (a + 1) << ' ' << (c + 1) << endl;
        fflush(stdout);
        int z;
        cin >> z;
        mas[c] = (z + y - x) / 2;
        mas[b] = y - mas[c];
        mas[a] = x - mas[b];
    }
    if (val * 3 < n) {
        int z = val * 3;
        int a = val * 3;
        cout << '?' << ' ' << (a) << ' ' << (z + 1) << endl;
        fflush(stdout);
        int x;
        cin >> x;
        mas[z] = x - mas[a - 1];
    }
    if (val * 3 + 1 < n) {
        int z = val * 3 + 1;
        int a = val * 3;
        cout << '?' << ' ' << (a) << ' ' << (z + 1) << endl;
        fflush(stdout);
        int x;
        cin >> x;
        mas[z] = x - mas[a - 1];
    }
    cout << '!' << ' ';
    for (int i = 0; i < n; i++) {
        cout << mas[i] << ' ';
    }
    cout << endl;
}
