#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t N, M;
  cin >> N >> M;
  vector<int64_t> x(M), y(M);
  for (int64_t i = 0; i < M; i++) {
    cin >> x[i] >> y[i];
  }
  vector<int> dp(N, 0);
  for (int64_t i = 1; i <= M; i++) {
    // cout << "i = " << i << ", x[i - 1] - 1 = " << x[i - 1] - 1 << endl;
    // cout << "i = " << i << ", y[i - 1] - 1 = " << y[i - 1] - 1 << endl;
    dp[y[i - 1] - 1] = max(dp[y[i - 1] - 1], dp[x[i - 1] - 1] + 1);
  }
  cout << *max_element(dp.begin(), dp.end()) << endl;
  return 0;
}