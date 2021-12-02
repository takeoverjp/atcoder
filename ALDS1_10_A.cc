#include <bits/stdc++.h>
// #include <atcoder/all>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
#if defined(TEST)
#include <lassert.h>
int main() {
  ASSERT_EQ(0, 0);
  return 0;
}
#else

static unordered_map<ll, ll> memo;
static ll fib(ll n) {
  if (memo.count(n) > 0) return memo[n];
  memo[n] = fib(n - 1) + fib(n - 2);
  return memo[n];
}

int main() {
  ll N;
  cin >> N;
  memo[0] = 1;
  memo[1] = 1;
  cout << fib(N) << endl;
  return 0;
}
#endif