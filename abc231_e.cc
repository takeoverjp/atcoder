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

static ll solve(ll X, vector<ll>& A, ll coin) {
  static unordered_map<ll, ll> memo;
  if (memo.count(X)) return memo[X];
  if (X == 0) return 0;
  if (coin == (ll)A.size() - 1) return X / A.back();
  ll curr = A[coin];
  ll next = A[coin + 1];

  // pay
  ll floor = X / next * next;
  ll ans = solve(floor, A, coin + 1) + (X % next) / curr;

  // charge
  ll ceil = (X + next - 1) / next * next;
  ans = min(ans, solve(ceil, A, coin + 1) + (next - (X % next)) / curr);
  memo[X] = ans;
  return ans;
}

int main() {
  ll N, X;
  cin >> N >> X;
  vector<ll> A(N);
  rep(i, N) { cin >> A[i]; }
  cout << solve(X, A, 0) << endl;

  return 0;
}
#endif