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

static ll N;
static ll A[2000];
static ll dp[2000][2000];
static ll solv(ll l, ll r, bool is_ioi) {
  if (dp[l][r] != -1) return dp[l][r];
  if (l == r) {
    if (is_ioi) {
      dp[l][r] = 0;
    } else {
      dp[l][r] = A[l];
    }
    return dp[l][r];
  }
  if (is_ioi) {
    if (A[l] > A[r]) {
      dp[l][r] = solv((l + 1) % N, r, false);
    } else {
      dp[l][r] = solv(l, (r - 1 + N) % N, false);
    }
  } else {
    dp[l][r] = max(A[l] + solv((l + 1) % N, r, true),
                   solv(l, (r - 1 + N) % N, true) + A[r]);
  }
  return dp[l][r];
}

int main() {
  cin >> N;
  rep(i, N) { cin >> A[i]; }
  ll ans = 0;
  rep(i, N) {
    rep(j, N) { dp[i][j] = -1; }
  }
  rep(i, N) { ans = max(ans, A[i] + solv((i + 1) % N, (i - 1 + N) % N, true)); }
  // rep(i, N) {
  //   rep(j, N) { cout << dp[i][j] << " "; }
  //   cout << endl;
  // }
  cout << ans << endl;
  return 0;
}
#endif