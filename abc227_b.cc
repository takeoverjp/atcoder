#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t N;
  cin >> N;
  vector<int64_t> S(N);
  for (int64_t i = 0; i < N; i++) {
    cin >> S[i];
  }
  int64_t ans = 0;
  for (auto s : S) {
    for (int a = 1; a <= 250; a++) {
      for (int b = 1; a * b <= 250; b++) {
        if (s == 4 * a * b + 3 * a + 3 * b) {
          goto NEXT;
        }
      }
    }
    ans++;
  NEXT:;
  }
  cout << ans << endl;
  return 0;
}