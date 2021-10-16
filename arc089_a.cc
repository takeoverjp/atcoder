#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n;
  cin >> n;
  vector<int64_t> t(n), x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> x[i] >> y[i];
  }

  bool ret = true;
  for (int i = 0; i < n; i++) {
    int64_t diff;
    if (i == 0) {
      diff = t[i] - abs(x[i]) - abs(y[i]);
    } else {
      diff = (t[i] - t[i - 1]) - abs(x[i] - x[i - 1]) - abs(y[i] - y[i - 1]);
    }
    if (diff < 0 || diff % 2) {
      ret = false;
      break;
    }
  }

  cout << (ret ? "Yes" : "No") << endl;
  return 0;
}