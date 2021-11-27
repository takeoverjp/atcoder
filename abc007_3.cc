#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main() {
  ll R, C, sy, sx, gy, gx;
  cin >> R >> C >> sy >> sx >> gy >> gx;
  sy--;
  sx--;
  gy--;
  gx--;
  vector<vector<char>> c(R, vector<char>(C));
  rep(i, R) rep(j, C) cin >> c[i][j];
  vector<vector<int>> depth(R, vector<int>(C, -1));
  queue<pair<int, int>> todo;
  todo.push({sx, sy});
  depth[sy][sx] = 0;
  while (!todo.empty()) {
    auto curr = todo.front();
    int next_depth = depth[curr.second][curr.first] + 1;
    todo.pop();

#define HANDLE(next_x, next_y)                                     \
  do {                                                             \
    if (next_x == gx && next_y == gy) {                            \
      cout << next_depth << endl;                                  \
      exit(0);                                                     \
    }                                                              \
    if (c[next_y][next_x] == '.' && depth[next_y][next_x] == -1) { \
      todo.push({next_x, next_y});                                 \
      depth[next_y][next_x] = next_depth;                          \
    }                                                              \
  } while (0)

    HANDLE((curr.first), (curr.second - 1));
    HANDLE((curr.first), (curr.second + 1));
    HANDLE((curr.first - 1), (curr.second));
    HANDLE((curr.first + 1), (curr.second));
  }
  cout << depth[gy][gx] << endl;
  return 0;
}