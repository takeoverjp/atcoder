#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, x;
  cin >> n;
  vector<int64_t> a(n);
  int64_t sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  cin >> x;

  int64_t remain = x % sum;
  int64_t ret = (x / sum) * n;

  int64_t work = 0;
  for (int i = 0; i < n; i++) {
    work += a[i];
    ret++;
    if (work > remain) {
      break;
    }
  }

  cout << ret << endl;
  return 0;
}
