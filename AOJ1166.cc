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

static ll solv(ll w, ll h, vector<vector<int> > &maze) {
  vector<vector<bool> > seen(h, vector<bool>(w, false));
  vector<vector<ll> > depth(h, vector<ll>(w, 0));
  queue<pair<ll, ll> > todo;
  todo.push({0, 0});
  while (!todo.empty()) {
    auto [x, y] = todo.front();
    todo.pop();
    if (seen[y][x]) continue;
    seen[y][x] = true;
    if (x == w - 1 && y == h - 1) return depth[y][x] + 1;
    // up
    if (!maze[2 * y][x]) {
      depth[y - 1][x] = depth[y][x] + 1;
      todo.push({x, y - 1});
    }
    // down
    if (!maze[2 * y + 2][x]) {
      depth[y + 1][x] = depth[y][x] + 1;
      todo.push({x, y + 1});
    }
    // left
    if (!maze[2 * y + 1][x]) {
      depth[y][x - 1] = depth[y][x] + 1;
      todo.push({x - 1, y});
    }
    // right
    if (!maze[2 * y + 1][x + 1]) {
      depth[y][x + 1] = depth[y][x] + 1;
      todo.push({x + 1, y});
    }
  }
  return 0;
}
int main() {
  while (true) {
    ll w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) break;
    vector<vector<int> > maze(2 * h + 1, vector<int>(w + 1, 1));
    rep(y, 2 * h - 1) {
      if (y % 2 == 0) {
        rep(x, w - 1) { cin >> maze[y + 1][x + 1]; }
      } else {
        rep(x, w) { cin >> maze[y + 1][x]; }
      }
    }
    cout << solv(w, h, maze) << endl;
  }
  return 0;
}
#endif