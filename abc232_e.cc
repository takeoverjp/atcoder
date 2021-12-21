#include <bits/stdc++.h>
// #include <atcoder/all>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
#define INF INT64_MAX
const ll MOD = 998244353;

static ll solv(ll H, ll W, ll K, ll x1, ll y1, ll x2, ll y2) {
  H %= MOD;
  W %= MOD;
  ll dp[2][2] = {{0, 0}, {0, 0}};
  dp[x1 != x2][y1 != y2] = 1;
  ll row[2] = {1, H - 1};
  ll col[2] = {1, W - 1};
  while (K--) {
    ll next[2][2] = {{0, 0}, {0, 0}};
    rep(i, 2) {
      rep(j, 2) {
        rep(a, 2) {
          next[i][a] += dp[i][j] * (col[a] - (j == a)) % MOD;
          next[a][j] += dp[i][j] * (row[a] - (i == a)) % MOD;
          next[i][a] %= MOD;
          next[a][j] %= MOD;
        }
      }
    }
    memcpy(dp, next, sizeof(next));
  }
  return dp[0][0];
}

#if defined(TEST)
#include <lassert.h>
int main() {
  ASSERT_EQ(solv(2, 2, 1, 1, 2, 1, 2), 0);
  ASSERT_EQ(solv(2, 2, 1, 1, 2, 2, 2), 1);
  ASSERT_EQ(solv(2, 2, 1, 1, 2, 1, 1), 1);
  ASSERT_EQ(solv(2, 2, 1, 1, 2, 2, 1), 0);
  ASSERT_EQ(solv(2, 2, 2, 1, 2, 2, 1), 2);  // sample1
  ASSERT_EQ(solv(3, 3, 2, 1, 2, 2, 1), 2);
  ASSERT_EQ(solv(1000000000, 1000000000, 1000000, 1000000000, 1000000000,
                 1000000000, 1000000000),
            24922282);                      // sample2
  ASSERT_EQ(solv(3, 3, 3, 1, 3, 3, 3), 9);  // sample3
  return 0;
}
#else

int main() {
  ll H, W, K;
  cin >> H >> W >> K;
  ll x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << solv(H, W, K, x1, y1, x2, y2) << endl;
  return 0;
}
#endif