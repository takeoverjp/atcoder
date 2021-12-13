#include <bits/stdc++.h>
// #include <atcoder/all>
#define INF INT64_MAX
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

int main() {
  while (true) {
    ll N, M;
    cin >> N >> M;
    if (N == 0 && M == 0) break;
    vector<ll> C(M), x(N);
    rep(i, M) cin >> C[i];
    rep(i, N) cin >> x[i];
    vector<vector<ll> > dp(20001, vector<ll>(256, INF));
    dp[0][128] = 0;
    rep(j, N) {
      rep(i, 256) {
        if (dp[j][i] == INF) continue;
        rep(k, M) {
          ll next = max(0ll, min(255ll, i + C[k]));
          dp[j + 1][next] =
              min(dp[j + 1][next], dp[j][i] + (next - x[j]) * (next - x[j]));
        }
      }
    }
    // rep(i, 256) {
    //   cout << setw(3) << i << ": ";
    //   rep(j, N) {
    //     if (dp[j][i] == INF) {
    //       cout << "INF ";
    //     } else {
    //       cout << setw(3) << dp[j][i] << " ";
    //     }
    //   }
    //   cout << endl;
    // }
    ll ans = INF;
    rep(i, 256) ans = min(ans, dp[N][i]);
    cout << ans << endl;
  }
  return 0;
}
#endif