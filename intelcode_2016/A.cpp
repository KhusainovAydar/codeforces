#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
#define pb push_back
#define INF 10000000
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define MAX (MIN * (-1) + 100)

using namespace std;

typedef long long ll;

int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#endif
    string a, b;
    cin >> a >> b;
    int n1, n2;
    if (a == "monday") {
        n1 = 1;
    }
    if (a == "tuesday") {
        n1 = 2;
    }
    if (a == "wednesday") {
        n1 = 3;
    }
    if (a == "thursday") {
        n1 = 4;
    }
    if (a == "friday") {
        n1 = 5;
    }
    if (a == "saturday") {
        n1 = 6;
    }
    if (a == "sunday") {
        n1 = 7;
    }
    
    if (b == "monday") {
        n2 = 1;
    }
    if (b == "tuesday") {
        n2 = 2;
    }
    if (b == "wednesday") {
        n2 = 3;
    }
    if (b == "thursday") {
        n2 = 4;
    }
    if (b == "friday") {
        n2 = 5;
    }
    if (b == "saturday") {
        n2 = 6;
    }
    if (b == "sunday") {
        n2 = 7;
    }
    n1--, n2--;
    for (int i = 0; i < 11; i++) {
        int sum = n1 + day[i];
        sum %= 7;
        if (sum == n2) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
