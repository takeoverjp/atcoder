#include <bits/stdc++.h>
using namespace std;
int main() {
  double P;
  cin >> P;
  double left = 0.0, right = P;
  while (abs(left - right) > 1e-9) {
    double mid = (left + right) / 2;
    if (1.0 + P * logf64(powf64(2.0, -2.0 / 3.0)) *
                  powf64(2.0, -2.0 / 3.0 * mid) <=
        0.0) {
      left = mid;
    } else {
      right = mid;
    }
  }
  cout << fixed << setprecision(10) << left + P * powf64(2.0, -2.0 / 3.0 * left)
       << endl;
  return 0;
}