#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n;
  cin >> n;
  vector<int64_t> a(n), b(n);
  for (int64_t i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  vector<double> t(n);
  double total = 0.0f;
  for (int64_t i = 0; i < n; i++) {
    t[i] = (double)a[i] / (double)b[i];
    total += t[i];
  }

  double sum = 0.0f;
  int64_t med_idx = 0;
  double med_sec = 0.0f;
  double med_len = 0.0f;
  for (int64_t i = 0; i < n; i++) {
    sum += t[i];
    if (sum >= total / 2.0f) {
      med_idx = i;
      med_sec = total / 2.0f - (sum - t[i]);
      med_len = med_sec * b[med_idx];
      break;
    }
  }
  // cout << "total =" << total << ", med_idx = " << med_idx
  //      << ", med_sec = " << med_sec << ", med_len = " << med_len << endl;

  double ret = 0.0f;
  for (int64_t i = 0; i < med_idx; i++) {
    ret += a[i];
  }
  ret += med_len;
  cout << std::fixed << std::setprecision(15) << ret << endl;
  return 0;
}