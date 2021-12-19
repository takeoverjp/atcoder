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

static ll ans = -1;

static void dfs(vector<vector<char> > &grid, ll x, ll y, ll depth) {
  if (grid[y][x] == '#') {
    return;
  }
  ans = max(ans, depth);
  grid[y][x] = '#';
  dfs(grid, x + 1, y, depth + 1);
  dfs(grid, x, y + 1, depth + 1);
}

int main() {
  ll H, W;
  cin >> H >> W;
  vector<vector<char> > grid(H + 1, vector<char>(W + 1, '#'));
  rep(y, H) rep(x, W) { cin >> grid[y][x]; }
  dfs(grid, 0, 0, 1);
  cout << ans << endl;
  return 0;
}
#endif