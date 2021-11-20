#include <bits/stdc++.h>
using namespace std;

static bool satisfied(int64_t x, const vector<int64_t>& H,
                      const vector<int64_t>& S) {
  int64_t size = H.size();
  vector<int64_t> X(size);
  for (int64_t i = 0; i < size; i++) {
    if (x < H[i]) {
      return false;
    }
    X[i] = (x - H[i]) / S[i];
  }
  sort(X.begin(), X.end());
  for (int64_t i = 0; i < size; i++) {
    if (X[i] < i || X[i] > x) return false;
  }
  return true;
}
int main() {
  int64_t N;
  cin >> N;
  vector<int64_t> H(N), S(N);
  for (int64_t i = 0; i < N; i++) {
    cin >> H[i] >> S[i];
  }
  int64_t left = 1;
  int64_t right = N * 1e10;
  int64_t mid;

  while (left < right - 1) {
    // cout << "left = " << left << ", right = " << right << endl;
    mid = (left + right) / 2;
    if (satisfied(mid, H, S)) {
      right = mid;
    } else {
      left = mid;
    }
  }
  cout << right << endl;
  return 0;
}