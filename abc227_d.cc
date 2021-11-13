#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    cin >> A[i];
  }

  int64_t ok = 0, ng = 1e18 / K;
  while (ng - ok > 1) {
    int64_t mid = (ok + ng) / 2, sum = 0;
    for (int64_t a : A) {
      sum += min(a, mid);
    }
    if (sum >= K * mid)
      ok = mid;
    else
      ng = mid;
  }
  cout << ok << endl;
}