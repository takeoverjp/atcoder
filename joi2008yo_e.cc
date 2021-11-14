#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t R, C;
  cin >> R >> C;
  vector<vector<int64_t>> a(R, vector<int64_t>(C));
  for (int64_t i = 0; i < R; i++) {
    for (int64_t j = 0; j < C; j++) {
      cin >> a[i][j];
    }
  }

  int64_t ans = 0;
  for (int64_t i = 0; i < pow(2, R - 1); i++) {
    int64_t score = 0;
    for (int64_t j = 0; j < C; j++) {
      int64_t count = 0;
      for (int64_t k = 0; k < R; k++) {
        bool flip = (i >> k) & 1;
        if ((flip && (a[k][j] == 1)) || (!flip && (a[k][j] == 0))) {
          count++;
        }
      }
      count = max(count, R - count);
      score += count;
    }
    ans = max(ans, score);
  }
  cout << ans << endl;
  return 0;
}