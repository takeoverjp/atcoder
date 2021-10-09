#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, m;
  cin >> n >> m;
  char a[m][2 * n];
  for (int64_t i = 0; i < 2 * n; i++) {
    for (int64_t j = 0; j < m; j++) {
      cin >> a[j][i];
    }
  }
  vector<pair<int64_t, int64_t>> score(2 * n);
  for (int64_t i = 0; i < 2 * n; i++) {
    score[i] = std::make_pair(i, 0);
  }

  for (int j = 0; j < m; j++) {
    for (int k = 1; k <= n; k++) {
      auto& p1 = score[2 * k - 1 - 1];
      auto& p2 = score[2 * k - 1];
      char h1 = a[j][p1.first];
      char h2 = a[j][p2.first];
      if (h1 == h2) {
        continue;
      }
      if ((h1 == 'G' && h2 == 'C') || (h1 == 'C' && h2 == 'P') ||
          (h1 == 'P' && h2 == 'G')) {
        p1.second++;
        continue;
      }
      p2.second++;
    }
    std::sort(score.begin(), score.end(), [](auto& lhs, auto& rhs) {
      return (lhs.second == rhs.second) ? (lhs.first < rhs.first)
                                        : (lhs.second > rhs.second);
    });
  }
  for (const auto& s : score) {
    cout << s.first + 1 << endl;
  }
  return 0;
}