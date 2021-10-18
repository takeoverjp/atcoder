#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t N, W;
  cin >> N >> W;
  vector<int64_t> w(N), v(N);
  for (int64_t i = 0; i < N; i++) {
    cin >> w[i] >> v[i];
  }
  vector<vector<int64_t>> dp(N + 1, vector<int64_t>(W + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= W; j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      if (j < w[i - 1]) {
        continue;
      }
      dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
      // cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
    }
  }
  cout << dp[N][W] << endl;
  return 0;
}