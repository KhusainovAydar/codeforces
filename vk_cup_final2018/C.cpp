#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef unsigned int index;

int main()
{
#ifdef ONPC
	//assert(freopen("a.in", "r", stdin));
	//assert(freopen("a.out", "w", stdout));
#else
#endif
	size_t n;
	cin >> n;
	index x = 0, y = 0;
	string ans1, ans2;
	while (n - x - 1 + n - y - 1 > n - 1)
	{
		if (x < n)
		{
			cout << "? " << x + 2 << " " << y + 1 << " " << n << " " << n << endl;
			string ans;
			cin >> ans;
			if (ans == "YES")
			{
				ans1 += "D";
				x++;
			}
			else
			{
				ans1 += "R";
				y++;
			}
		}
		else
		{
			ans1 += "R";
			y++;
		}
	}
	index x2 = (index)n - 1, y2 = (index)n - 1;
	while (x2 + y2 > n - 1)
	{
		if (x2 > 0)
		{
			cout << "? " << 1 << " " << 1 << " " << x2 + 1 << " " << y2 << endl;
			string ans;
			cin >> ans;
			if (ans == "NO")
			{
				ans2 += "D";
				x2--;
			}
			else
			{
				ans2 += "R";
				y2--;
			}
		}
		else
		{
			ans2 += "D";
			x2--;
		}
	}
	reverse(ans2.begin(), ans2.end());
	cout << "! " << ans1 << ans2 << endl;
}
