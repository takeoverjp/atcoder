#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

static vector<vector<ll>> to;
static vector<ll> score;

static void dfs(ll idx, ll parent = -1) {
  for (auto next : to[idx]) {
    if (next == parent) continue;
    score[next] += score[idx];
    dfs(next, idx);
  }
}
int main() {
  int64_t N, Q;
  cin >> N >> Q;
  to.resize(N);
  score.assign(N, 0);
  rep(i, N - 1) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  rep(i, Q) {
    ll p, x;
    cin >> p >> x;
    p--;
    score[p] += x;
  }
  dfs(0);
  rep(i, N) {
    if (i > 0) cout << " ";
    cout << score[i];
  }
  cout << endl;
  return 0;
}
