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
struct Edge {
  ll dist;
  ll time;
};
static ll N, M;
static Edge G[16][16];
static pair<ll, ll> dp[1 << 16][16];

static pair<ll, ll> rec(ll mask, ll pos) {
  if (mask == 0) {
    if (pos == 0) {
      return make_pair(0, 1);
    } else {
      return make_pair(INF, 0);
    }
  }
  if ((mask & (1 << pos)) == 0) {
    return make_pair(INF, 0);
  }
  auto &ret = dp[mask][pos];
  if (ret.first != 0) {
    return ret;
  }
  ret = make_pair(INF, 0);
  rep(i, N) {
    auto p = rec(mask & (~(1 << pos)), i);
    if (p.first == INF) {
      continue;
    }
    if (G[i][pos].dist == INF) {
      continue;
    }
    p.first += G[i][pos].dist;
    if (p.first <= G[i][pos].time) {
      if (ret.first > p.first) {
        ret = p;
      } else if (ret.first == p.first) {
        ret.second += p.second;
      }
    }
    // cout << "pos: " << pos << " i: " << i << "ret: " << ret.first << ", "
    //      << ret.second << " p: " << p.first << ", " << p.second << endl;
  }
  return ret;
}

int main() {
  cin >> N >> M;
  vector<vector<pair<ll, ll> > > edges(N);
  vector<ll> a(N), b(N);
  rep(i, 16) {
    rep(j, 16) {
      G[i][j].dist = INF;
      G[i][j].time = 0;
    }
  }
  rep(i, M) {
    ll s, t, d, time;
    cin >> s >> t >> d >> time;
    s--;
    t--;
    G[s][t] = {d, time};
    G[t][s] = {d, time};
  }
  auto ans = rec((1 << N) - 1, 0);
  if (ans.first != INF) {
    cout << ans.first << " " << ans.second << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  // rep(i, (1 << N) - 1) {
  //   rep(j, N) {
  //     cout << "(" << dp[i][j].first << ", " << dp[i][j].second << ") ";
  //   }
  //   cout << endl;
  // }
  return 0;
}
#endif