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
#define endl '\n'

// oxxxy vseravno pobedil

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
  srand((unsigned int) time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#if __APPLE__
  freopen("/Users/macbook/ClionProjects/untitled/input.txt", "r", stdin);
  freopen("/Users/macbook/ClionProjects/untitled/output.txt", "w", stdout);
#else
  //  freopen("duel.in", "r", stdin);
//  freopen("duel.out", "w", stdout);
#endif
  int x;
  cin >> x;
  if (x == 1) {
    cout << -1 << '\n';
  } else {
    for (int i = 2; i <= 100000; i++) {
      for (int j = 1; j * j <= i; ++j) {
        int one = i / j;
        int two = j;
        if (i / one < x && i * one > x) {
          std::cout << i << ' ' << one << '\n';
          return 0;
        }
        if (i / two < x && i * two > x) {
          std::cout << i << ' ' << two << '\n';
          return 0;
        }
      }
    }
    cout << -1 << '\n';
    return 0;
  }
}
