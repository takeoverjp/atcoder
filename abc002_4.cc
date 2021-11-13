#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<unordered_set<int>> a(N);
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    a[x].insert(y);
    a[y].insert(x);
  }
  for (int i = 0; i < N; i++) {
    a[i].insert(i);
    // cout << "a[" << i << "] = " << a[i];
  }

  int ans = 1;
  for (int i = 0; i < pow(2, N); i++) {
    int bit_num = __builtin_popcount(i);
    if (bit_num <= ans) {
      continue;
    }
    unordered_set<int> bits;
    for (int j = 0; j < N; j++) {
      if (((i >> j) & 1) == 0) {
        continue;
      }
      bits.insert(j);
    }
    // cout << "bits = " << bits;
    for (auto& src : bits) {
      for (auto& dst : bits) {
        if (a[src].count(dst) == 0) {
          goto next;
        }
      }
    }
    ans = max(ans, bit_num);

  next:;
  }
  cout << ans << endl;
  return 0;
}