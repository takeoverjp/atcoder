#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, k;
  cin >> n >> k;
  vector<int64_t> h(n);
  for (auto &x : h) cin >> x;
  vector<int64_t> dp(n, INT64_MAX);
  dp[0] = 0;
  for (int64_t i = 1; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      if (i < j) {
        break;
      }
      dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
    }
  }
  cout << dp[n - 1] << endl;
  return 0;
}