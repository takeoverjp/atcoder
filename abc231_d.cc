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

// true: with closed cycle
static bool dfs(ll index, vector<vector<ll> > &g, vector<bool> &visited,
                ll parent = -1) {
  visited[index] = true;
  for (auto &i : g[index]) {
    if (i == parent) continue;
    if (visited[i]) {
      return true;
    }
    if (dfs(i, g, visited, index)) {
      return true;
    }
  }
  return false;
}

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N), B(N);
  vector<vector<ll> > G(N);
  rep(i, M) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  rep(i, N) {
    if (G[i].size() > 2) {
      cout << "No" << endl;
      return 0;
    }
  }
  vector<bool> seen(N, false);
  rep(i, N) {
    if (seen[i]) continue;
    bool ret = dfs(i, G, seen);
    if (ret) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
#endif