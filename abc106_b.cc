#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t N;
  cin >> N;
  int64_t ans = 0;
  if (N < 105) {
    cout << ans << endl;
    return 0;
  }
  ans++;
  if (N == 105) {
    cout << ans << endl;
    return 0;
  }
  for (int i = 107; i <= N; i++) {
    if (i % 2 == 0) {
      continue;
    }
    int num = 1;
    for (int j = 3; j <= N; j += 2) {
      if (i % j == 0) {
        num++;
      }
    }
    if (num == 8) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}