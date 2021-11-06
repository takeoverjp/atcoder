#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t N, K;
  cin >> N >> K;
  vector<int64_t> l(N);
  for (auto &x : l) cin >> x;
  sort(l.begin(), l.end(), std::greater<int64_t>());
  int64_t ret = 0;
  for (int i = 0; i < K; i++) {
    ret += l[i];
  }
  cout << ret << endl;
  return 0;
}