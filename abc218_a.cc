#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n;
  string s;
  cin >> n;
  cin >> s;
  int64_t ret = 0;

  if (s[n - 1] == 'o') {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}