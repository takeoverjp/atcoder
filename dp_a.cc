#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n;
  cin >> n;
  vector<int64_t> h(n);
  for (auto &x : h) cin >> x;
  const int64_t MAX = 100001;
  vector<int64_t> dp(MAX, INT64_MAX);
  dp[0] = 0;
  dp[1] = dp[0] + abs(h[0] - h[1]);
  for (int i = 2; i < n; i++) {
    dp[i] = std::min(dp[i], dp[i - 1] + abs(h[i - 1] - h[i]));
    dp[i] = std::min(dp[i], dp[i - 2] + abs(h[i - 2] - h[i]));
  }

  cout << dp[n - 1] << endl;
  return 0;
}