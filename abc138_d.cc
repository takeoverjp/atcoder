#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

static vector<vector<ll>> to;
static vector<ll> score;
static vector<bool> done;

static void dfs(ll idx) {
  if (done[idx]) return;
  done[idx] = true;
  for (auto child : to[idx]) {
    if (done[child]) continue;
    score[child] += score[idx];
    dfs(child);
  }
}
int main() {
  int64_t N, Q;
  cin >> N >> Q;
  to.resize(N);
  score.assign(N, 0);
  done.assign(N, false);
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
