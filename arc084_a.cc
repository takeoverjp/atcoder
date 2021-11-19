#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t N;
  cin >> N;
  vector<int64_t> A(N), B(N), C(N);
  for (int64_t i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int64_t i = 0; i < N; i++) {
    cin >> B[i];
  }
  for (int64_t i = 0; i < N; i++) {
    cin >> C[i];
  }
  sort(A.begin(), A.end());
  sort(C.begin(), C.end());
  int64_t ans = 0;
  for (const auto b : B) {
    if (b <= *A.begin() || b >= *(C.end() - 1)) continue;
    auto a = lower_bound(A.begin(), A.end(), b);
    if (a == B.end()) {
      continue;
    }
    auto c = upper_bound(C.begin(), C.end(), b);
    auto a_idx = distance(A.begin(), a);
    auto c_idx = distance(C.begin(), c);
    // cout << "a = " << *a << ", c = " << *c << endl;
    ans += a_idx * (N - c_idx);
  }
  cout << ans << endl;
  return 0;
}