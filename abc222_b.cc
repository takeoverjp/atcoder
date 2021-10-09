#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, p;
  cin >> n >> p;
  int64_t ret = 0;
  for (int64_t i = 0; i < n; i++) {
    int64_t a;
    cin >> a;
    if (a < p) {
      ret++;
    }
  }
  cout << ret << endl;
  return 0;
}