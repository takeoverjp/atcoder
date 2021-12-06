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

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> c(m);
  rep(i, m) cin >> c[i];
  vector<vector<ll> > dp(m, vector<ll>(n + 1, 0));
  rep(j, n + 1) { dp[0][j] = j; }
  for (ll i = 1; i < m; i++) {
    rep(j, n + 1) {
      if (j >= c[i]) {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - c[i]] + 1);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  cout << dp[m - 1][n] << endl;
  return 0;
}
#endif