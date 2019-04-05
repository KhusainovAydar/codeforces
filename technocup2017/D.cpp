#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double lld;

const int NMAX = 1001;

int p[NMAX];

int find_set(int v) {
    if (p[v] == v) {
        return v;
    }
    return p[v] = find_set(p[v]);
}

void make_set(int v) {
    p[v] = v;
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rand() & 1) {
            p[a] = b;
        } else {
            p[b] = a;
        }
    }
}

string a[NMAX], b[NMAX], ans[NMAX];
unordered_set<string> used;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        a[i] = ""; b[i] = "";
        a[i] += s1[0];
        a[i] += s1[1];
        a[i] += s1[2];
        b[i] += s1[0];
        b[i] += s1[1];
        b[i] += s2[0];
    }
    for (int i = 0; i < n; i++) {
        make_set(i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                union_set(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        vector<int> id;
        for (int j = 0; j < n; j++) {
            if (find_set(j) == i) {
                id.pb(j);
            }
        }
        if (id.size() <= 1) continue;
        for (auto t : id) {
            if (used.find(b[t]) != used.end()) {
                cout << "NO";
                return 0;
            }
            used.insert(b[t]);
            ans[t] = b[t];
        }
    }

    for (int i = 0; i < n; i++) {
        if (ans[i].size()) continue;
        if (a[i] == b[i]) {
            if (used.find(a[i]) != used.end()) {
                cout << "NO";
                return 0;
            }
            ans[i] = a[i];
            used.insert(a[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans[i].size()) continue;
        if (used.find(b[i]) != used.end()) {
            if (used.find(a[i]) != used.end()) {
                cout << "NO";
                return 0;
            }
            ans[i] = a[i];
            used.insert(a[i]);
        } else {
            ans[i] = b[i];
            used.insert(b[i]);
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
}
