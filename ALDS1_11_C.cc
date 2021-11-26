#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main() {
  ll n;
  cin >> n;
  vector<vector<int>> G(n);
  rep(i, n) {
    int u, k;
    cin >> u >> k;
    G[u - 1].resize(k);
    rep(j, k) {
      int v;
      cin >> v;
      G[u - 1][j] = v - 1;
    }
  }
  vector<int> d(n, -1);
  queue<int> todo;
  todo.push(0);
  d[0] = 0;
  while (!todo.empty()) {
    int next = todo.front();
    todo.pop();
    for (auto i : G[next]) {
      if (d[i] >= 0) continue;
      todo.push(i);
      d[i] = d[next] + 1;
    }
  }

  rep(i, n) { cout << (i + 1) << " " << d[i] << endl; }
  return 0;
}