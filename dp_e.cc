#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t N, W;
  cin >> N >> W;
  vector<int64_t> w(N), v(N);
  for (int64_t i = 0; i < N; i++) {
    cin >> w[i] >> v[i];
  }
  int64_t V = accumulate(v.begin(), v.end(), 0);
  vector<vector<int64_t>> dp(N + 1, vector<int64_t>(V + 1, INT64_MAX / 2));
  dp[0][0] = 0;
  for (int64_t i = 1; i <= N; i++) {
    for (int64_t j = 0; j <= V; j++) {
      dp[i][j] = min(dp[i][j], dp[i - 1][j]);
      dp[i][j] = min(dp[i][j], dp[i - 1][max(j - v[i - 1], 0L)] + w[i - 1]);
      // cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
    }
  }
  for (int64_t j = V; j >= 0; j--) {
    if (dp[N][j] <= W) {
      cout << j << endl;
      break;
    }
  }
  return 0;
}