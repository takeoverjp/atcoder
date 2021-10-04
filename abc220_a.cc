#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t a, b, c;
  cin >> a >> b >> c;
  int64_t ret = (a % c) ? (a - (a % c) + c) : a;
  if (ret > b) {
    cout << -1 << endl;
  } else {
    cout << ret << endl;
  }
  return 0;
}