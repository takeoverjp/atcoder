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

static ll rec(vector<vector<ll> > &dist, vector<vector<ll> > &dp, ll S, ll v) {
  if (dp[S][v] != -1) {
    return dp[S][v];
  }
  if (S == (1 << dist.size()) - 1 && v == 0) {
    return dp[S][v] = 0;
  }
  ll ans = INF;
  rep(j, (ll)dist.size()) {
    if (dist[v][j] == INF) continue;
    if (S & 1 << j) continue;
    ll ret = rec(dist, dp, S | 1 << j, j);
    if (ret == INF) continue;
    ans = min(ans, ret + dist[v][j]);
  }
  return dp[S][v] = ans;
}

int main() {
  ll V, E;
  cin >> V >> E;
  vector<vector<ll> > dist(V, vector<ll>(V, INF));
  rep(i, E) {
    ll s, t, d;
    cin >> s >> t >> d;
    dist[s][t] = d;
  }
  vector<vector<ll> > dp((1 << V), vector<ll>(V, -1));
  ll ans = rec(dist, dp, 0, 0);
  // rep(i, (1 << V)) {
  //   rep(j, V) { cout << dp[i][j] << " "; }
  //   cout << endl;
  // }
  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
#endif