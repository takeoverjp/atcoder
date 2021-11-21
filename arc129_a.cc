#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t N, L, R;
  cin >> N >> L >> R;
  int n_bit = 0;
  int64_t tmp = N;
  while (tmp) {
    tmp /= 2;
    n_bit++;
  }

  int64_t ans = 0;
  for (int64_t i = 0; i < n_bit; i++) {
    int64_t bit = (1LL << i) & N;
    if (!bit) {
      continue;
    }
    if (bit * 2 - 1 < L) {
      // bit ~ (bit * 2 - 1) ~ L ~ R
      continue;
    }
    if (R < bit) {
      // L ~ R ~ bit ~ (bit * 2 - 1)
      continue;
    }
    if (L <= bit) {
      if (bit * 2 - 1 <= R) {
        // L ~ bit ~ (bit * 2 - 1) ~ R
        ans += bit;
      } else {
        // L~ bit ~ R ~ (bit * 2 - 1)
        ans += R - bit + 1;
      }
    } else {
      if (bit * 2 - 1 <= R) {
        // bit ~ L ~ (bit * 2 - 1) ~ R
        ans += bit * 2 - 1 - L + 1;
      } else {
        // bit ~ L ~ R ~ (bit * 2 - 1)
        ans += R - L + 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}