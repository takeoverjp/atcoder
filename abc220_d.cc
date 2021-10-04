#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n;
  cin >> n;
  vector<int64_t> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int dp[n][10];
  memset(dp, 0, sizeof(dp));
  dp[0][a[0]] = 1;
  for (int64_t i = 0; i < n - 1; i++) {
    for (int64_t j = 0; j < 10; j++) {
      dp[i + 1][(j + a[i + 1]) % 10] =
          (dp[i + 1][(j + a[i + 1]) % 10] + dp[i][j]) % 998244353;
      dp[i + 1][(j * a[i + 1]) % 10] =
          (dp[i + 1][(j * a[i + 1]) % 10] + dp[i][j]) % 998244353;
    }
  }

  for (int i = 0; i < 10; i++) {
    cout << dp[n - 1][i] << endl;
  }
  return 0;
}