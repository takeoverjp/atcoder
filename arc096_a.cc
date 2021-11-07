#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int64_t ans = A * X + B * Y;
  if (A + B <= C * 2) {
    cout << ans << endl;
    return 0;
  }
  int64_t Z = min(X, Y) * 2;
  X -= Z / 2;
  Y -= Z / 2;
  if (X == 0 && Y == 0) {
    cout << Z * C << endl;
    return 0;
  }
  int64_t rest = INT64_MAX;
  for (int64_t i = 0; i <= X; i++) {
    for (int64_t j = 0; j <= Y; j++) {
      rest = min(rest, i * A + j * B + max(X - i, Y - j) * 2 * C);
    }
  }
  ans = Z * C + rest;
  cout << ans << endl;
  return 0;
}