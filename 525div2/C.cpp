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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
//  for (int i = 1; i <= 2000; i++) {
//    for (int j = 0; ; j++) {
//      if ((7727) % (i + j) == i - 1) {
//        std::cout << i + j << ' ' << 7727 % (i + j) << '\n';
//        break;
//      }
//    }
//  }

  cout << n + 1 << '\n';
  cout << 2 << ' ' << n << ' ' << 1 << '\n';
  cout << 1 << ' ' << n << ' '  << 7727 << '\n';
  for (int i = 1; i < n; i++) {
    int val = i;
    for (int j = 0; ; j++) {
      if (7727 % (i + j) == i - 1) {
        val += j;
        break;
      }
    }
    cout << 2 << ' ' << i << ' ' << val << '\n';
  }
}
