#include <bits/stdc++.h>
// #include <atcoder/all>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
#if defined(TEST)
#include <lassert.h>
int main() {
  ASSERT_EQ(0, 0);
  return 0;
}
#else

static ll lcs(const string &s1, const string &s2) {
  ll n1 = s1.size();
  ll n2 = s2.size();
  vector<vector<ll> > dp(n1 + 1, vector<ll>(n2 + 1, 0));
  for (ll i = 1; i <= n1; ++i) {
    for (ll j = 1; j <= n2; ++j) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
      }
    }
  }
  return dp[n1][n2];
}
int main() {
  ll q;
  cin >> q;
  rep(i, q) {
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2) << endl;
  }
  return 0;
}
#endif