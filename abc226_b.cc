#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t N;
  cin >> N;
  set<vector<int64_t>> a;
  for (int64_t i = 0; i < N; i++) {
    vector<int64_t> b;
    int64_t L;
    cin >> L;
    b.reserve(L);
    for (int64_t i = 0; i < L; i++) {
      int64_t x;
      cin >> x;
      b.push_back(x);
    }
    a.insert(move(b));
  }
  cout << a.size() << endl;
  return 0;
}