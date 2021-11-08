#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t N;
  string S;
  cin >> N >> S;
  int64_t ans = 0;
  for (int64_t i = 0; i <= 999; i++) {
    int index = 0;
    for (auto c : S) {
      c -= '0';
      if (index == 0 && c == i / 100) {
        index++;
      } else if (index == 1 && c == (i / 10) % 10) {
        index++;
      } else if (index == 2 && c == i % 10) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}