#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define mp make_pair
#define INF 1000000000
#define pi 3.14159265359

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	#if __APPLE__ 
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
        bool swapped = false;
         for (int j = 0; j < n - i - 1; j++) {
             if (a[j] > a[j+1]) {
             	 cout << j + 1 << ' ' << j + 2 << endl;
                 int b = a[j]; 
                 a[j] = a[j+1];
                 a[j+1] = b;
                 swapped = true;
             } 
         }
         if(!swapped)
            break;
     }
}
