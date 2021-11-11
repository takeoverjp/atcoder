#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M), p(M);
  for (int i = 0; i < M; i++) {
    int k;
    cin >> k;
    int s = 0;
    for (int j = 0; j < k; j++) {
      int tmp;
      cin >> tmp;
      s |= 1 << (tmp - 1);
    }
    a[i] = s;
  }
  for (int i = 0; i < M; i++) {
    cin >> p[i];
  }
  int64_t ans = 0;
  for (int i = 0; i < pow(2, N); i++) {
    for (int j = 0; j < M; j++) {
      if (__builtin_popcount(i & a[j]) % 2 != p[j]) {
        goto NEXT;
      }
    }
    ans++;
  NEXT:;
  }
  cout << ans << endl;
  return 0;
}