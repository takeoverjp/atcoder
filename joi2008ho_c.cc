#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t N, M;
  cin >> N >> M;
  vector<int64_t> P(N + 1);
  P[0] = 0;
  for (int64_t i = 1; i <= N; i++) {
    cin >> P[i];
  }
  sort(P.begin(), P.end());
  set<int64_t> S;
  for (int64_t i = 0; i <= N; i++) {
    for (int64_t j = i; j <= N; j++) {
      S.insert(P[i] + P[j]);
    }
  }
  vector<int64_t> V(S.begin(), S.end());
  sort(V.begin(), V.end());
  int64_t ans = 0;
  for (const auto two : V) {
    // cout << two << endl;
    auto it = upper_bound(V.begin(), V.end(), M - two);
    if (it == V.begin()) {
      continue;
    }
    it--;
    ans = max(ans, *it + two);
    if (ans == M) {
      cout << ans << endl;
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}