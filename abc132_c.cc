#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t N;
  cin >> N;
  vector<int64_t> d(N);
  for (int64_t i = 0; i < N; i++) {
    cin >> d[i];
  }
  sort(d.begin(), d.end());
  int64_t ret = d[N / 2] - d[N / 2 - 1];
  cout << ret << endl;
  return 0;
}