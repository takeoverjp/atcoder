#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int64_t i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a[i] = make_pair(x, y);
  }
  sort(a.begin(), a.end(), [](const auto &p1, const auto &p2) {
    return p1.first == p2.first ? p1.second < p2.second : p1.first < p2.first;
  });
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int dx = a[i].first - a[j].first;
      int dy = a[i].second - a[j].second;
      auto p1 = make_pair(a[i].first + dy, a[i].second - dx);
      auto p2 = make_pair(a[j].first + dy, a[j].second - dx);
      if (binary_search(a.begin(), a.end(), p1) &&
          binary_search(a.begin(), a.end(), p2)) {
        ans = max(ans, dx * dx + dy * dy);
        continue;
      }
      auto p3 = make_pair(a[i].first + dy, a[i].second - dx);
      auto p4 = make_pair(a[j].first + dy, a[j].second - dx);
      if (binary_search(a.begin(), a.end(), p3) &&
          binary_search(a.begin(), a.end(), p4)) {
        ans = max(ans, dx * dx + dy * dy);
        continue;
      }
    }
  }
  cout << ans << endl;
  return 0;
}