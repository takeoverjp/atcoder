#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t k;
  std::string a, b;
  cin >> k;
  cin >> a >> b;

  int64_t val_a = 0;
  for (const auto c : a) {
    val_a *= k;
    val_a += c - '0';
  }
  int64_t val_b = 0;
  for (const auto c : b) {
    val_b *= k;
    val_b += c - '0';
  }
  int64_t ret = val_a * val_b;
  cout << ret << endl;
  return 0;
}