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
  vector<ll> A;
  while (true) {
    ll a;
    cin >> a;
    if (a == 0) break;
    A.push_back(a);
  }
  ll max_value = *max_element(A.begin(), A.end());
  ll max_n = 1;
  while (max_n * (max_n + 1) * (max_n + 2) / 6 <= max_value) {
    max_n++;
  }
  vector<vector<ll> > dp(max_value + 1, vector<ll>(2, 0));
  rep(j, max_value + 1) { dp[j][0] = j; }
  for (ll i = 1; i < max_n; i++) {
    rep(j, max_value + 1) {
      dp[j][1] = dp[j][0];
      ll val = (i + 1) * (i + 2) * (i + 3) / 6;
      if (j >= val) {
        dp[j][1] = min(dp[j][1], dp[j - val][1] + 1);
      }
    }
    rep(j, max_value + 1) { swap(dp[j][0], dp[j][1]); }
  }
  // rep(j, max_value + 1) {
  //   rep(i, max_n) { cout << dp[j][i] << " "; }
  //   cout << endl;
  // }
  vector<ll> odd_tetrahedron;
  rep(i, max_n) {
    ll tetra = (i + 1) * (i + 2) * (i + 3) / 6;
    if (tetra % 2 == 0) {
      continue;
    }
    odd_tetrahedron.push_back(tetra);
  }
  vector<vector<ll> > dp_odd(max_value + 1, vector<ll>(2, 0));
  rep(j, max_value + 1) { dp_odd[j][0] = j; }
  for (ll i = 1; i < odd_tetrahedron.size(); ++i) {
    rep(j, max_value + 1) {
      dp_odd[j][1] = dp_odd[j][0];
      if (j >= odd_tetrahedron[i]) {
        dp_odd[j][1] = min(dp_odd[j][1], dp_odd[j - odd_tetrahedron[i]][1] + 1);
      }
    }
    rep(j, max_value + 1) { swap(dp_odd[j][0], dp_odd[j][1]); }
  }
  // rep(j, max_value + 1) {
  //   rep(i, 2) { cout << dp_odd[j][i] << " "; }
  //   cout << endl;
  // }
  rep(i, A.size()) { cout << dp[A[i]][0] << " " << dp_odd[A[i]][0] << endl; }
  return 0;
}
#endif