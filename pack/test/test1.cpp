#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...) (void)0
#endif
 
using i64 = int64_t;
using u64 = uint64_t;
constexpr bool test = false;
constexpr i64 mod = 1000000007;

int countr_zero(u64 x) {
  return x ? __builtin_ctzll(x) : 64;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti += 1) {
    int n;
    cin >> n;
    vector<pair<i64, i64>> stack;
    auto pow = [&](i64 a, i64 r) {
      i64 res = 1;
      for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
      return res;
    };
    i64 sum = 0;
    for (int i = 0, ai; i < n; i += 1) {
      cin >> ai;
      i64 r = countr_zero(u64(ai)), a = ai >> r;
      while (not stack.empty()) {
        if (r >= 30 or stack.back().first <= (a << r)) {
          r += stack.back().second;
          sum += stack.back().first;
          stack.pop_back();
        } else {
          break;
        }
      }
      if (r == 0) {
        sum += a;
      } else {
        stack.emplace_back(a, r);
      }
      i64 res = sum;
      for (auto [a, r] : stack) res += pow(2, r) * a % mod;
      cout << res % mod << " ";
    }
    cout << "\n";
  }
}

