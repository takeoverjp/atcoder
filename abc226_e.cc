#include <bits/stdc++.h>
using namespace std;

static vector<vector<int64_t>> G;
static vector<bool> seen;

static void dfs(int64_t index, int64_t &v, int64_t &e) {
  if (seen[index]) return;
  seen[index] = true;
  v++;
  e += G[index].size();
  for (const auto g : G[index]) {
    dfs(g, v, e);
  }
}

int main() {
  int64_t N, M;
  cin >> N >> M;
  G.resize(N);
  seen.resize(N, false);
  for (int64_t i = 0; i < M; i++) {
    int64_t U, V;
    cin >> U >> V;
    U--;
    V--;
    G[U].push_back(V);
    G[V].push_back(U);
  }
  for (const auto &g : G) {
    if (g.size() == 0) {
      cout << 0 << endl;
      return 0;
    }
  }

  int64_t ans = 1;
  for (int64_t i = 0; i < N; i++) {
    if (seen[i]) {
      continue;
    }
    int64_t v = 0, e = 0;
    dfs(i, v, e);
    e /= 2;
    int64_t r = 2 - v + e;
    // cout << "@@@ r = " << r << ", v = " << v << ", e = " << e << endl;
    if (r != 2) {
      cout << 0 << endl;
      return 0;
    }
    ans = ans * 2 % 998244353;
  }
  cout << ans << endl;
  return 0;
}