#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> a(N);
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    a[i] = {x, y};
  }
  sort(a.begin(), a.end());

  double ans = 0.0;
  int64_t count = 0;
  do {
    count++;
    for (int i = 1; i < N; i++) {
      double distance = sqrtf64(powf64(a[i].first - a[i - 1].first, 2) +
                                powf64(a[i].second - a[i - 1].second, 2));
      ans += distance;
    }
  } while (std::next_permutation(a.begin(), a.end()));
  cout << std::fixed << std::setprecision(10) << ans / (double)count << endl;
  return 0;
}
