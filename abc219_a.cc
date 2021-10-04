#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t x;
  cin >> x;
  int64_t ret = 0;

  if (x < 40) {
    cout << 40 - x << endl;
  } else if (x < 70) {
    cout << 70 - x << endl;
  } else if (x < 90) {
    cout << 90 - x << endl;
  } else {
    cout << "expert" << endl;
  }

  return 0;
}