#include <bits/stdc++.h>
using namespace std;
int main() {
  std::string s[3];
  cin >> s[0];
  cin >> s[1];
  cin >> s[2];
  std::string t;
  cin >> t;

  std::string ret;
  for (char c : t) {
    ret += s[c - '1'];
  }

  cout << ret << endl;
  return 0;
}