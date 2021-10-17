#include <bits/stdc++.h>
using namespace std;
int main() {
  std::string s;
  cin >> s;
  int len = s.length();
  vector<string> list(len, s);
  for (int i = 1; i < len; i++) {
    for (int j = 0; j < len; j++) {
      list[i][j] = list[i - 1][(j + 1) % len];
    }
  }
  sort(list.begin(), list.end());
  cout << list[0] << endl << list[len - 1] << endl;
  return 0;
}