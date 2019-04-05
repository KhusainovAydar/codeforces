#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define mp make_pair
#define INF 1000000000000
#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

multiset<int> se;

int main() {
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	#if __APPLE__ 
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	vector< pair<string, int> > ans;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "insert") {
			int x;
			cin >> x;
			se.insert(x);
			ans.pb({s, x});
		}
		if (s == "getMin") {
			int x;
			cin >> x;
			if (se.size() > 0 && *se.begin() == x) {
				ans.pb({s, x});
				continue;
			}
			while (se.size() > 0 && *se.begin() < x) {
				ans.pb({"removeMin", 0});
				se.erase(se.begin());
			}
			if (se.size() == 0 || *se.begin() > x) {
				se.insert(x);
				ans.pb({"insert", x});
			} 
			ans.pb({s, x});
		}
		if (s == "removeMin") {
			if (se.size() == 0) {
				ans.pb({"insert", 1});
				se.insert(1);
			}
			se.erase(se.begin());
			ans.pb({"removeMin", 1});
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i].fi == "removeMin") {
			cout << ans[i].fi << endl;
		} else cout << ans[i].fi << ' ' << ans[i].se << endl;
	}
}
