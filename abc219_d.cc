#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n, x, y;
  cin >> n;
  cin >> x >> y;
  vector<pair<int64_t, int64_t>> bentos(n);
  for (int i = 0; i < n; i++) {
    cin >> bentos[i].first >> bentos[i].second;
  }

  uint64_t dp[n + 1][x + 1][y + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      for (int k = 0; k <= y; k++) {
        dp[i][j][k] = UINT64_MAX;
      }
    }
  }

  dp[0][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      for (int k = 0; k <= y; k++) {
        int tmp_j = min(j + bentos[i - 1].first, x);
        int tmp_k = min(k + bentos[i - 1].second, y);
        dp[i][tmp_j][tmp_k] = std::min(
            dp[i][tmp_j][tmp_k],
            (dp[i - 1][j][k] == UINT64_MAX) ? UINT64_MAX : dp[i - 1][j][k] + 1);
        dp[i][j][k] = std::min(dp[i][j][k], dp[i - 1][j][k]);
      }
    }
  }

  if (dp[n][x][y] == UINT64_MAX) {
    cout << -1 << endl;
  } else {
    cout << dp[n][x][y] << endl;
  }
  return 0;
}