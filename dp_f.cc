#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int slen = s.length();
  int tlen = t.length();
  vector<string> dp(tlen + 1);
  vector<string> work(tlen + 1);
  for (int i = 1; i <= slen; i++) {
    for (int j = 1; j <= tlen; j++) {
      if (s[i - 1] == t[j - 1]) {
        work[j] = dp[j - 1] + s[i - 1];
      } else {
        if (dp[j].length() > work[j - 1].length()) {
          work[j] = dp[j];
        } else {
          work[j] = work[j - 1];
        }
      }
    }
    std::swap(dp, work);
    // for (const auto c : dp) {
    //   cout << c << " ";
    // }
    // cout << endl;
  }
  cout << dp[tlen] << endl;
  return 0;
}