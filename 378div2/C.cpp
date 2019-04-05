#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.0001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define MAX (MIN * (-1) + 100)
#define MOD 1000000007
#define dist pesya

using namespace std;

typedef long long ll;

bool ch(vector<int> a) {
    vector<int> b = a;
    vector<int> mx;
    int maxx = 0;
    for (int i = 0; i < a.size(); i++) {
        maxx = max(maxx, a[i]);
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == maxx) {
            mx.pb(i);
        }
    }
    for (int i = 0; i < mx.size(); i++) {
        int id = mx[i];
        int sum = a[id];
        int id1 = id - 1;
        while (id1 >= 0 && a[id1] < sum) {
            sum += a[id1];
            id1--;
        }
        int id2 = id + 1;
        while (id2 < a.size() && a[id2] < sum) {
            sum += a[id2];
            id2++;
        }
        while (id1 >= 0 && a[id1] < sum) {
            sum += a[id1];
            id1--;
        }
        while (id2 < a.size() && a[id2] < sum) {
            sum += a[id2];
            id2++;
        }
        while (id1 >= 0 && a[id1] < sum) {
            sum += a[id1];
            id1--;
        }
        while (id2 < a.size() && a[id2] < sum) {
            sum += a[id2];
            id2++;
        }
        int sum1 = 0;
        for (int j = 0; j < b.size(); j++) {
            sum1 += b[j];
        }
        if (sum1 == sum) {
            return 1;
        }
    }
    return 0;
}

vector< pair<char, int> > ans(vector<int> a) {
    vector< pair<char, int> > v;
    vector<int> b = a;
    vector<int> mx;
    int maxx = 0;
    for (int i = 0; i < a.size(); i++) {
        maxx = max(maxx, a[i]);
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == maxx) {
            mx.pb(i);
        }
    }
    for (int i = 0; i < mx.size(); i++) {
        v.clear();
        int id = mx[i];
        int sum = a[id];
        int id1 = id - 1;
        int pos = id;
        while (id1 >= 0 && a[id1] < sum) {
            sum += a[id1];
            v.push_back({'L', pos + 1});
            pos--;
            id1--;
        }
        int id2 = id + 1;
        while (id2 < a.size() && a[id2] < sum) {
            sum += a[id2];
            v.push_back({'R', pos + 1});
            id2++;
        }
        while (id1 >= 0 && a[id1] < sum) {
            sum += a[id1];
            v.push_back({'L', pos + 1});
            pos--;
            id1--;
        }
        while (id2 < a.size() && a[id2] < sum) {
            sum += a[id2];
            v.push_back({'R', pos + 1});
            id2++;
        }
        while (id1 >= 0 && a[id1] < sum) {
            sum += a[id1];
            v.push_back({'L', pos + 1});
            pos--;
            id1--;
        }
        while (id2 < a.size() && a[id2] < sum) {
            sum += a[id2];
            v.push_back({'R', pos + 1});
            id2++;
        }
        int sum1 = 0;
        for (int j = 0; j < b.size(); j++) {
            sum1 += b[j];
        }
        if (sum1 == sum) {
//            for (int j = 0; j < a.size(); j++) {
//                cout << a[j] << ' ';
//            }
//            cout << endl;
            return v;
        }
    }
    return v;
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
//    freopen("grasshopper.in", "r", stdin);
//    freopen("grasshopper.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    ll SUM1 = 0, SUM2 = 0;
    for (int i = 0; i < n; i++) {
        SUM1 += a[i];
    }
    for (int i = 0; i < m; i++) {
        SUM2 += b[i];
    }
    if (SUM2 != SUM1) {
        cout << "NO";
        return 0;
    }
    int last = 0;
    for (int id = 0; id < m; id++) {
        int sum = 0;
        vector<int> c;
        for (int i = last; i < n; i++) {
            sum += a[i];
            c.push_back(a[i]);
            if (sum == b[id]) {
                if (!ch(c)) {
                    cout << "NO";
                    return 0;
                }
                last = i + 1;
                break;
            }
            if (sum > b[id]) {
                cout << "NO";
                return 0;
            }
        }
    }
    if (last != n) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    last = 0;
    for (int id = 0; id < m; id++) {
        int sum = 0;
        vector<int> c;
        for (int i = last; i < n; i++) {
            sum += a[i];
            c.push_back(a[i]);
            if (sum == b[id]) {
                vector< pair<char, int> > v = ans(c);
                for (int j = 0; j < v.size(); j++) {
                    cout << v[j].se + id << ' ' << v[j].fi << endl;;
                }
                last = i + 1;
                break;
            }
        }
    }
}
