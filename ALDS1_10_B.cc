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

static ll solv(vector<vector<ll> > &dp, vector<ll> &row, vector<ll> &col, ll l,
               ll r) {
  if (dp[l][r] != INF) return dp[l][r];
  if (l + 1 == r) {
    return row[l] * col[l] * col[r];
  }
  if (l == r) {
    return 0;
  }
  if (l + 1 > r) {
    return INF;
  }
  for (ll mid = l; mid < r; mid++) {
    ll left = solv(dp, row, col, l, mid);
    ll right = solv(dp, row, col, mid + 1, r);
    dp[l][r] = min(dp[l][r], left + right + row[l] * col[mid] * col[r]);
  }
  return dp[l][r];
}

int main() {
  ll n;
  cin >> n;
  vector<ll> row(n), col(n);
  rep(i, n) { cin >> row[i] >> col[i]; }
  vector<vector<ll> > dp(n, vector<ll>(n, INF));
  cout << solv(dp, row, col, 0, n - 1) << endl;
  return 0;
}
#endif