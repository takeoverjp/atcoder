#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n;
  cin >> n;
  vector<int64_t> a(n);
  for (int64_t i = 0; i < n; i++) {
    cin >> a[i];
  }
  std::sort(a.begin(), a.end(), [](auto lhs, auto rhs) { return lhs > rhs; });
  int64_t ret = 0;
  for (int64_t i = 0; i < n; i++) {
    if (i % 2) {
      ret -= a[i];
    } else {
      ret += a[i];
    }
  }

  cout << ret << endl;
  return 0;
}