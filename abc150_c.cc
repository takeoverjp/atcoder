#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin >> N;
  vector<int64_t> P(N), Q(N), R(N);
  for (int64_t i = 0; i < N; i++) {
    cin >> P[i];
  }
  for (int64_t i = 0; i < N; i++) {
    cin >> Q[i];
  }
  for (int64_t i = 0; i < N; i++) {
    R[i] = i + 1;
  }
  int count = 0;
  int rank_P = 0;
  int rank_Q = 0;
  // cout << "P: " << P;
  // cout << "Q: " << Q;
  // cout << "R: " << R;
  do {
    if (P == R) {
      rank_P = count;
    }
    if (Q == R) {
      rank_Q = count;
    }
    count++;
  } while (next_permutation(R.begin(), R.end()));
  cout << abs(rank_P - rank_Q) << endl;
  return 0;
}