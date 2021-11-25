#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

static ll max_depth = 0;

static void dfs(vector<vector<int>>& a, size_t i, size_t j, ll depth = 0) {
  a[i][j] = 0;
  depth++;
  if ((i < a.size() - 1) && a[i + 1][j]) {
    dfs(a, i + 1, j, depth);
  }
  if ((i > 0) && a[i - 1][j]) {
    dfs(a, i - 1, j, depth);
  }
  if ((j > 0) && a[i][j - 1]) {
    dfs(a, i, j - 1, depth);
  }
  if ((j < a[0].size() - 1) && a[i][j + 1]) {
    dfs(a, i, j + 1, depth);
  }
  max_depth = max(max_depth, depth);
  depth--;
  a[i][j] = 1;
}
int main() {
  ll m, n;
  cin >> m >> n;
  vector<vector<int>> a(n, vector<int>(m));
  rep(i, n) {
    rep(j, m) { cin >> a[i][j]; }
  }
  rep(i, n) {
    rep(j, m) {
      if (a[i][j]) dfs(a, i, j);
    }
  }
  cout << max_depth << endl;
  return 0;
}