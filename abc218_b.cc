#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[26];
  cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] >> a[7] >> a[8] >>
      a[9] >> a[10] >> a[11] >> a[12] >> a[13] >> a[14] >> a[15] >> a[16] >>
      a[17] >> a[18] >> a[19] >> a[20] >> a[21] >> a[22] >> a[23] >> a[24] >>
      a[25];

  std::string ret;
  ret.reserve(26);
  for (int i = 0; i < 26; i++) {
    ret += 'a' + a[i] - 1;
  }

  cout << ret << endl;
  return 0;
}