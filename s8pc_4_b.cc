#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t N, K;
  cin >> N >> K;
  vector<int64_t> a(N);
  for (int64_t i = 0; i < N; i++) {
    cin >> a[i];
  }
  int64_t ans = INT64_MAX;
  for (int64_t i = 0; i < pow(2, N - 1); i++) {
    int64_t count = 1;
    int64_t cost = 0;
    int64_t current = a[0];
    for (int64_t j = 0; j < N - 1; j++) {
      if (a[j + 1] > current) {
        count++;
        current = a[j + 1];
        continue;
      }
      bool up = (i >> j) & 1;
      if (up) {
        count++;
        current++;
        cost += current - a[j + 1];
      }
    }

    if (count < K) {
      continue;
    }
    ans = min(ans, cost);
  }
  cout << ans << endl;
  return 0;
}