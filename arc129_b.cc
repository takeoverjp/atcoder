#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t N;
  cin >> N;
  vector<int64_t> L(N), R(N);
  int64_t max_l = INT64_MIN;
  int64_t min_r = INT64_MAX;
  for (int64_t i = 0; i < N; i++) {
    cin >> L[i] >> R[i];
    max_l = max(max_l, L[i]);
    min_r = min(min_r, R[i]);
    if (min_r > max_l) {
      cout << "0" << endl;
      continue;
    }
    cout << (max_l - min_r + 1) / 2 << endl;
  }
  return 0;
}