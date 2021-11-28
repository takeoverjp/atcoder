#include <bits/stdc++.h>
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
  ll H, W, C, Q;
  cin >> H >> W >> C >> Q;
  vector<tuple<ll, ll, ll> > queries;
  rep(i, Q) {
    ll t, n, c;
    cin >> t >> n >> c;
    c--;
    queries.emplace_back(t, n, c);
  }
  vector<ll> ans(C, 0);
  unordered_set<ll> h_done;
  unordered_set<ll> v_done;

  for (auto q = queries.rbegin(); q != queries.rend(); ++q) {
    ll t, n, c;
    tie(t, n, c) = *q;
    if (t == 1) {
      if (h_done.count(n) == 0) {
        ans[c] += W - v_done.size();
        h_done.insert(n);
      }
    } else {
      if (v_done.count(n) == 0) {
        ans[c] += H - h_done.size();
        v_done.insert(n);
      }
    }
  }

  rep(i, C) {
    if (i >= 1) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
#endif