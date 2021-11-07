#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int64_t ans = 0;
  int64_t work = 0;
  for (auto c : S) {
    if (c == 'A' || c == 'C' || c == 'G' || c == 'T') {
      work++;
      ans = max(ans, work);
    } else {
      work = 0;
    }
  }
  cout << ans << endl;
  return 0;
}