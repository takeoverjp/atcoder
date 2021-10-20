#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int slen = s.length();
  int tlen = t.length();
  vector<vector<int>> dp(tlen + 1, vector<int>(slen + 1));
  for (int i = 1; i <= slen; i++) {
    for (int j = 1; j <= tlen; j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[j][i] = dp[j - 1][i - 1] + 1;
      } else {
        dp[j][i] = max(dp[j - 1][i], dp[j][i - 1]);
      }
    }
    // for (const auto &row : dp) {
    //   for (const auto val : row) {
    //     cout << val << " ";
    //   }
    //   cout << endl;
    // }
  }
  int len = dp[tlen][slen];
  string ret;
  ret.resize(len);
  int i = slen, j = tlen;
  while (len > 0) {
    if (j >= 1 && dp[j][i] == dp[j - 1][i]) {
      j--;
      continue;
    }
    if (i >= 1 && dp[j][i] == dp[j][i - 1]) {
      i--;
      continue;
    }
    j--;
    i--;
    len--;
    ret[len] = s[i];
  }
  cout << ret << endl;
  return 0;
}