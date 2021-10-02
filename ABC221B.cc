#include <bits/stdc++.h>
using namespace std;
int main() {
  std::string s, t;
  cin >> s;
  cin >> t;
  if (s == t) {
    cout << "Yes" << endl;
    return 0;
  }
  int64_t size = s.length();
  for (int i = 0; i < size - 1; i++) {
    if (s[i] == t[i]) {
      continue;
    }
    auto tmp = s[i];
    s[i] = s[i + 1];
    s[i + 1] = tmp;
    break;
  }
  if (s == t) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}