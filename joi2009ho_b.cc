#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t d, n, m;
  cin >> d >> n >> m;
  vector<int64_t> s(n + 1), k(m);
  s[0] = 0;
  for (int64_t i = 1; i < n; i++) {
    cin >> s[i];
  }
  s[n] = d;
  sort(s.begin(), s.end());
  int64_t ans = 0;
  for (int64_t i = 0; i < m; i++) {
    cin >> k[i];
    int64_t left = 0, right = n;
    while (left < right) {
      int64_t mid = (left + right) / 2;
      if (s[mid] <= k[i]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    int64_t dist = min(abs(k[i] - s[left]), abs(s[left - 1] - k[i]));
    // cout << left << " " << right << " " << dist << endl;
    ans += dist;
  }
  cout << ans << endl;
  return 0;
}
