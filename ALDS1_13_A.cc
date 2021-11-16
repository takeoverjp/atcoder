#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  vector<int> r(k), c(k);
  for (int i = 0; i < k; i++) {
    cin >> r[i] >> c[i];
  }
  for (int i = 0; i < 8; i++) {
    if (find(r.begin(), r.end(), i) == r.end()) {
      r.push_back(i);
    }
    if (find(c.begin(), c.end(), i) == c.end()) {
      c.push_back(i);
    }
  }
  do {
    for (int i = 0; i < 7; i++) {
      for (int j = i + 1; j < 8; j++) {
        if (abs(r[i] - r[j]) == abs(c[i] - c[j])) {
          goto NEXT;
        }
      }
    }
    break;
  NEXT:;
  } while (next_permutation(r.begin() + k, r.end()));

  vector<pair<int, int>> ans;
  for (int i = 0; i < 8; i++) {
    ans.push_back(make_pair(r[i], c[i]));
  }
  sort(ans.begin(), ans.end(), [](const auto& lhs, const auto& rhs) {
    return lhs.second < rhs.second;
  });
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < ans[i].first; j++) {
      cout << ".";
    }
    cout << "Q";
    for (int j = ans[i].first; j < 8; j++) {
      cout << ".";
    }
    cout << endl;
  }

  return 0;
}