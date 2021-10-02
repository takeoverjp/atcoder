#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t a, b;
  cin >> a >> b;
  int64_t ret = pow(32, a - b);

  cout << ret << endl;
  return 0;
}