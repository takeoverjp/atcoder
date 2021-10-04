#include <bits/stdc++.h>
using namespace std;
int main() {
  string x;
  cin >> x;
  int64_t n;
  cin >> n;
  vector<string> names(n);
  for (int i = 0; i < n; i++) {
    cin >> names[i];
  }
  std::unordered_map<char, uint8_t> map;
  for (int i = 0; i < x.size(); i++) {
    map[x[i]] = i;
  }

  std::sort(names.begin(), names.end(),
            [&map](const auto& lhs, const auto& rhs) {
              int llen = lhs.length();
              int rlen = rhs.length();
              int len = std::min(llen, rlen);
              for (int i = 0; i < len; i++) {
                if (lhs[i] == rhs[i]) {
                  continue;
                }
                return map[lhs[i]] < map[rhs[i]];
              }
              return llen < rlen;
            });

  for (const auto& name : names) {
    cout << name << endl;
  }

  return 0;
}