#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, y;
  cin >> n >> y;
  if (y % 1000) {
    cout << "-1 -1 -1" << endl;
    return 0;
  }
  y /= 1000;
  if (y > 10 * n) {
    cout << "-1 -1 -1" << endl;
    return 0;
  }

  for (int i = n; i >= 0; i--) {
    if (10 * i > y) {
      continue;
    }
    for (int j = 0; j <= n - i; j++) {
      int k = n - i - j;
      if (10 * i + 5 * j + k == y) {
        cout << i << " " << j << " " << k << endl;
        return 0;
      }
    }
  }

  cout << "-1 -1 -1" << endl;
  return 0;
}