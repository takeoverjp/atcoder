#include <bits/stdc++.h>
// #include <atcoder/all>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
#define INF INT64_MAX
#if defined(TEST)
#include <lassert.h>
int main() {
  ASSERT_EQ(0, 0);
  return 0;
}
#else

static ll solv(const vector<ll>& w, vector<vector<ll> >& dp, ll l, ll r) {
  if (dp[l][r] != -1) return dp[l][r];
  if (abs(r + 1 - l) <= 1) return 0;

  ll ret = 0;
  if (abs(w[l] - w[r]) <= 1) {
    if (solv(w, dp, l + 1, r - 1) == (r - 1 - (l + 1) + 1)) {
      ret = r - l + 1;
    }
  }

  for (ll mid = l + 1; mid <= r; mid++) {
    ret = max(ret, solv(w, dp, l, mid - 1) + solv(w, dp, mid, r));
  }

  return dp[l][r] = ret;
}

int main() {
  while (true) {
    ll n;
    cin >> n;
    if (n == 0) break;
    vector<ll> w(n);
    rep(i, n) { cin >> w[i]; }
    vector<vector<ll> > dp(n, vector<ll>(n + 1, -1));
    rep(i, n) { dp[i][i] = 0; }
    cout << solv(w, dp, 0, n - 1) << endl;

    // rep(i, n) {
    //   rep(j, n) { cout << dp[i][j] << " "; }
    //   cout << endl;
    // }
  }
  return 0;
}
#endif