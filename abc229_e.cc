#include <bits/stdc++.h>

#include <atcoder/all>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

#if defined(TEST)
#include <lassert.h>
int main() {
  ASSERT_EQ(0, 0);
  return 0;
}
#else
int main() {
  ll N, M;
  cin >> N >> M;
  vector<vector<ll> > G(N);

  rep(i, M) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
  }

  vector<ll> ans = {0};
  ll sets = 0;
  dsu d(N);

  for (ll i = N - 1; i >= 1; i--) {
    sets++;
    for (auto v : G[i]) {
      if (!d.same(i, v)) {
        d.merge(i, v);
        sets--;
      }
    }
    ans.push_back(sets);
  }
  reverse(ans.begin(), ans.end());
  for (auto a : ans) {
    cout << a << endl;
  }

  return 0;
}
#endif
