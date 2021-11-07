#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t N;
  cin >> N;
  vector<pair<int64_t, int64_t>> a(N);
  for (int64_t i = 0; i < N; i++) {
    cin >> a[i].first >> a[i].second;
  }
  set<pair<int64_t, int64_t>> diffs;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < N; j++) {
      if (i == j) {
        continue;
      }
      int64_t diff_x = a[i].first - a[j].first;
      int64_t diff_y = a[i].second - a[j].second;
      int64_t w = gcd(diff_x, diff_y);
      auto diff = make_pair<int64_t, int64_t>(diff_x / w, diff_y / w);
      diffs.insert(diff);
    }
  }
  cout << diffs.size() << endl;
  return 0;
}