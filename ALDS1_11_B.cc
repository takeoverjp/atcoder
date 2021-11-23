#include <bits/stdc++.h>
using namespace std;

static int64_t timestamp = 0;
static void dfs(vector<vector<int64_t>>& graph, vector<int64_t>& d,
                vector<int64_t>& f, int64_t id) {
  if (d[id] > 0) return;
  d[id] = ++timestamp;
  for (const auto node : graph[id]) {
    dfs(graph, d, f, node);
  }
  f[id] = ++timestamp;
}
int main() {
  int64_t N;
  cin >> N;
  vector<vector<int64_t>> G(N);
  vector<int64_t> d(N, 0), f(N, 0);
  for (int64_t i = 0; i < N; i++) {
    int64_t id, k;
    cin >> id >> k;
    G[i].reserve(k);
    for (int64_t j = 0; j < k; j++) {
      int64_t a;
      cin >> a;
      G[i].push_back(a - 1);
    }
  }
  for (int64_t i = 0; i < N; i++) {
    dfs(G, d, f, i);
  }
  for (int64_t i = 0; i < N; i++) {
    cout << i + 1 << " " << d[i] << " " << f[i] << endl;
  }
  return 0;
}