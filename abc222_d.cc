#include <bits/stdc++.h>
using namespace std;
int main() {
  const int64_t MOD = 998244353;
  const int64_t MAX = 3000;
  int64_t n;
  cin >> n;
  vector<int64_t> a(n), b(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  int64_t dp[MAX + 1][n + 1];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int64_t i = 0; i < n + 1; i++) {
    for (int64_t v = 0; v < MAX; v++) {
      dp[v + 1][i] += dp[v][i];
      dp[v + 1][i] %= MOD;
    }
    if (i != n) {
      for (int v = a[i]; v <= b[i]; v++) {
        dp[v][i + 1] += dp[v][i];
      }
    }
  }

  // cout << "-------------" << endl;
  // for (int64_t v = 0; v <= b[n - 1] + 1; v++) {
  //   for (int64_t i = 0; i <= n; i++) {
  //     cout << setw(10) << dp[v][i] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << "-------------" << endl;

  cout << dp[MAX][n] << endl;
  return 0;
}