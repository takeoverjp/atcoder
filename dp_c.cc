#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n;
  cin >> n;
  vector<int64_t> a(n), b(n), c(n);
  for (int64_t i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }

  vector<vector<int64_t>> dp(n + 1, vector<int64_t>(3, 0));
  for (int64_t i = 1; i <= n; i++) {
    dp[i][0] = max(dp[i][0], max(dp[i - 1][1], dp[i - 1][2]) + a[i - 1]);
    dp[i][1] = max(dp[i][1], max(dp[i - 1][2], dp[i - 1][0]) + b[i - 1]);
    dp[i][2] = max(dp[i][2], max(dp[i - 1][0], dp[i - 1][1]) + c[i - 1]);
  }

  int64_t ret = *max_element(dp[n].begin(), dp[n].end());
  cout << ret << endl;
  return 0;
}