#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <complex>


#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int long long
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS
//#define endl '\n'

// oxxxy vseravno pobedil

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;


map<pair<int, int>, int> mp;
int f(int a, int b) {
  if (mp.count({a, b})) {
    return mp[{a, b}];
  }
  cout << "? " << a << ' ' << b << endl;
  cout.flush();
  int ans;
  cin >> ans;
  if (ans == -2) {
    assert(false);
  }
  mp[{a, b}] = ans;
  return ans;
}

int main() {
//  srand((unsigned int) time(NULL));
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);
//  cout.tie(NULL);
#if __APPLE__
//  freopen("/Users/macbook/ClionProjects/untitled/input.txt", "r", stdin);
//  freopen("/Users/macbook/ClionProjects/untitled/output.txt", "w", stdout);
#else
  //  freopen("duel.in", "r", stdin);
//  freopen("duel.out", "w", stdout);
#endif
  int a = 0, b = 0;
  int last = f(a, b);
  for (int i = 29; i >= 0; i--) {
    int val = (1 << i);
    a += val;
    b += val;

    int news = f(a, b);

    if (last < 0) {
      if (news > 0) {
        a -= val;
      }
      if (news < 0) {
        a -= val;
        int k = f(a, b);
        if (k < 0) {
          b -= val;
        }
        if (k > 0) {
          a += val;
        }
      }
    }
    if (last > 0) {
      if (news < 0) {
        b -= val;
      }
      if (news > 0) {
        b -= val;
        int k = f(a, b);
        if (k > 0) {
          a -= val;
        }
        if (k < 0) {
          b += val;
        }
      }
    }
    if (last == 0) {
      a -= val;
      int k = f(a, b);
      if (k > 0) {
        a += val;
      } else {
        b -= val;
      }
    }
    last = f(a, b);
  }
  cout << "! " << a << ' ' << b << endl;
}
