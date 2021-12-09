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
  ll N, M;
  cin >> N >> M;
  vector<ll> D(N, 0), C(M, 0);
  rep(i, N) { cin >> D[i]; }
  rep(j, M) { cin >> C[j]; }
  vector<vector<ll> > dp(N + 1, vector<ll>(M + 1, INT64_MAX));
  rep(j, M + 1) { dp[0][j] = 0; }
  rep(i, N) {
    rep(j, M) {
      if (i > j) continue;
      dp[i + 1][j + 1] = min(dp[i][j] + C[j] * D[i], dp[i + 1][j]);
    }
  }
  // rep(i, N) {
  //   rep(j, M) { cout << dp[i][j] << " "; }
  //   cout << endl;
  // }
  cout << dp[N][M] << endl;
  return 0;
}
#endif