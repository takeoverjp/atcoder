#include <bits/stdc++.h>
using namespace std;

static vector<int64_t> T;
static vector<vector<int64_t>> A;

static int64_t cost(int64_t n) {
  // cout << "@@@ T[" << n << "] = " << T[n] << endl;
  int64_t ret = 0;
  if (T[n] == 0) {
    return 0;
  }
  for (auto child : A[n]) {
    ret += cost(child);
  }
  ret += T[n];
  T[n] = 0;
  return ret;
}
int main() {
  int64_t N;
  cin >> N;
  T.resize(N);
  A.resize(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t K;
    cin >> T[i] >> K;
    A[i].resize(K);
    for (int64_t j = 0; j < K; j++) {
      cin >> A[i][j];
      A[i][j]--;
    }
  }
  cout << cost(N - 1) << endl;
  return 0;
}