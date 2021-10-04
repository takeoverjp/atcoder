#include <bits/stdc++.h>
using namespace std;
int main()
{
  int64_t a;
  cin >> a;
  int ret = 0;
  while (a) {
    if (a % 10) {
      ret++;
    }
    a /= 10;
  }
  cout << ret << endl;
  return 0;
}