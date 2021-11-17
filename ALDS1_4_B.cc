#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n;
  cin >> n;
  vector<int64_t> S(n);
  for (int64_t i = 0; i < n; i++) {
    cin >> S[i];
  }
  int64_t q;
  cin >> q;
  vector<int64_t> T(q);
  for (int64_t i = 0; i < q; i++) {
    cin >> T[i];
  }
  int64_t ans = 0;
  for (const auto &t : T) {
    if (binary_search(S.begin(), S.end(), t)) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}