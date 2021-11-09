#include <bits/stdc++.h>
using namespace std;

static inline int64_t cost(const vector<int64_t>& a, const vector<int64_t>& b,
                           int64_t in, int64_t out) {
  int64_t ret = 0;
  for (uint64_t i = 0; i < a.size(); i++) {
    ret += abs(in - a[i]) + abs(a[i] - b[i]) + abs(out - b[i]);
  }
  return ret;
}

int main() {
  int64_t N;
  cin >> N;
  vector<int64_t> a(N), b(N);
  for (int64_t i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int64_t ans = INT64_MAX;
  if (N % 2) {
    ans = min(ans, cost(a, b, a[N / 2], b[N / 2]));
  } else {
    ans = min(ans, cost(a, b, a[N / 2], b[N / 2]));
    ans = min(ans, cost(a, b, a[N / 2 - 1], b[N / 2 - 1]));
  }
  cout << ans << endl;
  return 0;
}