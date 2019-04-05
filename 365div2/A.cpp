#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
//#define INF 1000000000
#define y1 kek
#define re return
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

int main() {
    srand((unsigned int)time(NULL));
    /*#if __APPLE__
     freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
     freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
     #endif*/
    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) a++;
        if (y > x) b++;
    }
    if (a > b) {
        cout << "Mishka";
        return 0;
    }
    if (b > a) {
        cout << "Chris";
        return 0;
    }
    cout << "Friendship is magic!^^";
}
