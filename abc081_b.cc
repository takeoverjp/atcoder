#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n;
  cin >> n;
  vector<int64_t> a(n);
  for (int64_t i = 0; i < n; i++) {
    int64_t tmp, count = 0;
    cin >> tmp;
    while (tmp) {
      if (tmp % 2) {
        break;
      }
      tmp /= 2;
      count++;
    }
    a[i] = count;
  }
  int64_t ret = *std::min_element(a.begin(), a.end());

  cout << ret << endl;
  return 0;
}