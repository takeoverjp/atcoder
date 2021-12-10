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
  ll N;
  cin >> N;
  vector<string> S(5);
  rep(i, 5) { cin >> S[i]; }
  vector<vector<ll> > count(N, vector<ll>(3, 0));
  rep(i, N) {
    rep(k, 5) {
      switch (S[k][i]) {
        case 'R':
          count[i][0]++;
          break;
        case 'B':
          count[i][1]++;
          break;
        case 'W':
          count[i][2]++;
          break;
      }
    }
  }
  // rep(i, N) {
  //   rep(j, 3) { cout << count[i][j] << " "; }
  //   cout << endl;
  // }
  vector<vector<ll> > dp(N + 1, vector<ll>(3, 0));
  for (ll i = 1; i <= N; i++) {
    rep(j, 3) {
      dp[i][j] = 5 - count[i - 1][j];
      if (j == 0) {
        dp[i][j] += min(dp[i - 1][1], dp[i - 1][2]);
      } else if (j == 1) {
        dp[i][j] += min(dp[i - 1][2], dp[i - 1][0]);
      } else if (j == 2) {
        dp[i][j] += min(dp[i - 1][0], dp[i - 1][1]);
      }
    }
  }
  ll ans = INT64_MAX;
  rep(i, 3) { ans = min(ans, dp[N][i]); }
  cout << ans << endl;
  return 0;
}
#endif