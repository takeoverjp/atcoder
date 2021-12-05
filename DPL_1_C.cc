#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
static vector<vector<ll>> dp;

int main() {
  ll N, W;
  cin >> N >> W;
  vector<ll> v(N, 0);
  vector<ll> w(N, 0);
  rep(i, N) { cin >> v[i] >> w[i]; }
  dp.resize(N + 1);
  rep(i, N + 1) { dp[i].assign(W + 1, 0); }
  rep(i, N) {
    for (ll j = 1; j <= W; j++) {
      dp[i + 1][j] = dp[i][j];
      if (w[i] <= j) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - w[i]] + v[i]);
        dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
      }
    }
  }
  // rep(i, N + 1) {
  //   rep(j, W + 1) { cout << dp[i][j] << " "; }
  //   cout << endl;
  // }
  cout << dp[N][W] << endl;
  return 0;
}