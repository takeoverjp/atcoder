#include <bits/stdc++.h>
using namespace std;
static int N, M;
static vector<vector<int>> G;
static vector<int> dp;

static int recurse(int node) {
  if (dp[node] != -1) {
    return dp[node];
  }

  int ret = 0;
  for (int dst : G[node]) {
    ret = max(ret, recurse(dst) + 1);
  }
  return dp[node] = ret;
}

int main() {
  cin >> N >> M;
  G.assign(N, vector<int>());
  dp.assign(N, -1);
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;

    // 1-indexed -> 0-indexed
    --x;
    --y;

    G[x].push_back(y);
  }

  int ret = 0;
  for (int node = 0; node < N; node++) {
    ret = max(ret, recurse(node));
  }
  cout << ret << endl;
  return 0;
}