#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int last = -1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            last = -1;
            cnt++;
            continue;
        }
        if (last == -1){
            last = (a[i] == 3 ? -1 : a[i]);
        } else {
            if (a[i] == 1) {
                if (last == 1) {
                    cnt++;
                    last = -1;
                } else {
                    last = 1;
                }
                continue;
            }
            if (a[i] == 2) {
                if (last == 2) {
                    cnt++;
                    last = -1;
                } else {
                    last = 2;
                }
                continue;
            }
            if (a[i] == 3) {
                if (last == 1) {
                    last = 2;
                } else last = 1;
            }
        }
    }
    cout << cnt;
}

