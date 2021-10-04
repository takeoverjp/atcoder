#include <bits/stdc++.h>
using namespace std;
int main() {
  std::string n;
  cin >> n;
  std::sort(n.begin(), n.end(),
            [](const auto lhs, const auto rhs) { return lhs > rhs; });
  int64_t size = n.length();
  int64_t ret = 0;
  int64_t bits = 1 << size;
  for (int64_t i = 0; i < bits; i++) {
    int64_t lhs = 0;
    int64_t rhs = 0;
    for (int j = 0; j < size; j++) {
      if (i & (1 << j)) {
        lhs = lhs * 10 + (n[j] - '0');
      } else {
        rhs = rhs * 10 + (n[j] - '0');
      }
    }
    ret = std::max(ret, lhs * rhs);
  }
  cout << ret << endl;
  return 0;
}