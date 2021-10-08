#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n;
  cin >> n;
  vector<int64_t> a(n);
  for (int64_t i = 0; i < n; i++) {
    cin >> a[i];
  }
  set<int64_t> ret{a.begin(), a.end()};
  cout << ret.size() << endl;
  return 0;
}