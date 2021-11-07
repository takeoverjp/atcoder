#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t N, M;
  cin >> N >> M;
  vector<vector<int64_t>> A(N, vector<int64_t>(M, 0));
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }
  int64_t ans = 0;
  for (int64_t t1 = 0; t1 < M - 1; t1++) {
    for (int64_t t2 = t1 + 1; t2 < M; t2++) {
      int64_t sum = 0;
      for (int64_t i = 0; i < N; i++) {
        sum += max(A[i][t1], A[i][t2]);
      }
      ans = max(ans, sum);
    }
  }
  cout << ans << endl;
  return 0;
}