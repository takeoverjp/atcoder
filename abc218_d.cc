#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n;
  cin >> n;

  vector<pair<int, int>> points;
  points.reserve(n);

  for (int i = 0; i < n; i++) {
    int64_t x, y;
    cin >> x >> y;
    points.push_back(make_pair(x, y));
  }

  std::sort(begin(points), end(points), [](auto &lhs, auto &rhs) {
    return (lhs.first == rhs.first) ? (lhs.second < rhs.second)
                                    : (lhs.first < rhs.first);
  });

  int64_t ret = 0;
  for (int i = 0; i < n - 3; i++) {
    auto lt = points[i];
    for (int j = i + 1; j < n - 2; j++) {
      auto lb = points[j];
      if (lt.first > lb.first) {
        continue;
      }
      if (lt.first < lb.first) {
        break;
      }
      for (int k = j + 1; k < n - 1; k++) {
        auto rt = points[k];
        if (lt.second != rt.second) {
          continue;
        }
        for (int l = k + 1; l < n; l++) {
          auto rb = points[l];
          if (rt.first > rb.first) {
            continue;
          }
          if (rt.first < rb.first) {
            break;
          }
          if (lb.second != rb.second) {
            continue;
          }
          ret++;
        }
      }
    }
  }

  cout << ret << endl;
  return 0;
}