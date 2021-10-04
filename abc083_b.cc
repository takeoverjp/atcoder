#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, a, b;
  int64_t ret = 0;
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    int work = i;
    while (work) {
      sum += work % 10;
      work /= 10;
    }
    if (a <= sum && sum <= b) {
      ret += i;
    }
  }
  cout << ret << endl;
  return 0;
}