#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t N;
  cin >> N;
  int64_t ans = 0;

  for (int64_t A = 1; A * A * A <= N; A++) {
    for (int64_t B = A; A * B * B <= N; B++) {
      ans += N / (A * B) - B + 1;
    }
  }
  cout << ans << endl;
  return 0;
}