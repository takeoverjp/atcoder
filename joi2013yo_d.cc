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
  ll D, N;
  cin >> D >> N;
  vector<ll> T(D), A(N), B(N), C(N);
  rep(i, D) { cin >> T[i]; }
  rep(i, N) { cin >> A[i] >> B[i] >> C[i]; }

  vector<vector<ll> > dp(N, vector<ll>(D, 0));
  rep(j, D) {
    rep(i, N) {
      if (T[j] < A[i] || T[j] > B[i]) {
        dp[i][j] = -1;
        continue;
      }
      if (j == 0) {
        dp[i][j] = 0;
        continue;
      }
      rep(k, N) {
        if (dp[k][j - 1] < 0) continue;
        dp[i][j] = max(dp[i][j], dp[k][j - 1] + abs(C[k] - C[i]));
      }
    }
  }

  // rep(i, N) {
  //   rep(j, D) { cout << dp[i][j] << " "; }
  //   cout << endl;
  // }

  ll ans = 0;
  rep(i, N) { ans = max(ans, dp[i][D - 1]); }
  cout << ans << endl;
  return 0;
}
#endif