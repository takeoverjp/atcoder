#include <bits/stdc++.h>
using namespace std;
int main() {
  uint64_t testcase_num;
  cin >> testcase_num;
  vector<tuple<uint64_t, uint64_t, uint64_t>> cases(testcase_num);
  for (uint64_t i = 0; i < testcase_num; i++) {
    uint64_t a, b, c;
    cin >> a >> b >> c;
    cases[i] = make_tuple(a, b, c);
  }

  uint64_t max_a = 0, max_b = 0, max_c = 0;
  for (uint64_t i = 0; i < testcase_num; i++) {
    auto [a, b, c] = cases[i];
    max_a = std::max(max_a, a);
    max_b = std::max(max_b, b);
    max_c = std::max(max_c, c);
  }
  cout << "@@@ max = " << max_a << "," << max_b << "," << max_c << endl;

  uint64_t dp[max_a + 1][max_b + 1][max_c + 1];
  memset(dp, 0, sizeof(dp));
  for (uint64_t i = 0; i <= max_a; i++) {
    for (uint64_t j = 0; j <= max_b; j++) {
      for (uint64_t k = 0; k <= max_c; k++) {
        if (i >= 5) {
          dp[i][j][k] = std::max(dp[i][j][k], dp[i - 5][j][k] + 1);
        }
        if (i >= 2 && j >= 2) {
          dp[i][j][k] = std::max(dp[i][j][k], dp[i - 2][j - 2][k] + 1);
        }
        if (j >= 2 && k >= 1) {
          dp[i][j][k] = std::max(dp[i][j][k], dp[i][j - 2][k - 1] + 1);
        }
        if (i >= 3 && k >= 1) {
          dp[i][j][k] = std::max(dp[i][j][k], dp[i - 3][j][k - 1] + 1);
        }
        if (i >= 1 && k >= 2) {
          dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j][k - 2] + 1);
        }
      }
    }
  }
  for (uint64_t i = 0; i < testcase_num; i++) {
    auto [a, b, c] = cases[i];
    cout << dp[a][b][c] << endl;
  }

  return 0;
}