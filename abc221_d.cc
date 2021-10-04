#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n;
  cin >> n;
  vector<std::pair<int64_t, int64_t>> a;
  a.reserve(n);
  for (int64_t i = 0; i < n; i++) {
    int64_t tmp[2];
    cin >> tmp[0] >> tmp[1];
    a.emplace_back(tmp[0], 1);
    a.emplace_back(tmp[0] + tmp[1], -1);
  }
  std::sort(a.begin(), a.end());
  int64_t count = 0;
  std::vector<int64_t> ret(n + 1);
  std::generate(ret.begin(), ret.end(), []() { return 0; });
  for (int i = 0; i < n - 1; i++) {
    count += a[i].second;
    ret[count] += a[i + 1].first - a[i].first;
  }
  for (int i = 1; i < n; i++) {
    cout << ret[i] << " ";
  }
  cout << ret[n] << endl;

  return 0;
}