#include <bits/stdc++.h>
using namespace std;
int main() {
  while (true) {
    int64_t n, x;
    cin >> n >> x;
    if (!n && !x) break;

    int64_t ans = 0;
    for (int64_t i = 1; i <= n; i++) {
      for (int64_t j = i + 1; j <= n; j++) {
        int64_t rest = x - (i + j);
        if (rest >= j + 1 && rest <= n) {
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}