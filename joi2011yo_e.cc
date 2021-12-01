#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
vector<vector<char>> grid;
vector<vector<int>> depth;
vector<pair<ll, ll>> cheese;
queue<pair<ll, ll>> todo;

static bool wfs(ll next_x, ll next_y, ll goal_x, ll goal_y, ll next_depth) {
  if (next_x == goal_x && next_y == goal_y) {
    return true;
  }
  if (grid[next_y][next_x] != 'X' && depth[next_y][next_x] == -1) {
    depth[next_y][next_x] = next_depth;
    todo.push({next_x, next_y});
  }
  return false;
}
int main() {
  ll H, W, N;
  cin >> H >> W >> N;
  cheese.assign(N + 1, {-1, -1});
  grid.assign(H + 2, vector<char>(W + 2, 'X'));
  rep(y, H) {
    rep(x, W) {
      cin >> grid[y + 1][x + 1];
      if (grid[y + 1][x + 1] == 'S') {
        cheese[0] = {x + 1, y + 1};
      }
      if (grid[y + 1][x + 1] >= '1' && grid[y + 1][x + 1] <= '9') {
        cheese[grid[y + 1][x + 1] - '0'] = {x + 1, y + 1};
      }
    }
  }

  ll ans = 0;
  rep(i, N) {
    auto start = cheese[i];
    auto start_x = start.first;
    auto start_y = start.second;
    auto goal = cheese[i + 1];
    auto goal_x = goal.first;
    auto goal_y = goal.second;
    // cout << "start = (" << start_x << ", " << start_y << ")" << endl;
    // cout << "goal = (" << goal_x << ", " << goal_y << ")" << endl;
    depth.assign(H + 2, vector<int>(W + 2, -1));
    depth[start_y][start_x] = 0;
    todo = {};
    todo.push({start_x, start_y});
    while (!todo.empty()) {
      auto curr = todo.front();
      // cout << "start = (" << curr.first << ", " << curr.second << ", "
      //      << depth[curr.second][curr.first] << ")" << endl;
      todo.pop();
      int next_depth = depth[curr.second][curr.first] + 1;

      if (wfs(curr.first, curr.second + 1, goal_x, goal_y, next_depth)) {
        ans += next_depth;
        goto NEXT_CHEESE;
      }
      if (wfs(curr.first, curr.second - 1, goal_x, goal_y, next_depth)) {
        ans += next_depth;
        goto NEXT_CHEESE;
      }
      if (wfs(curr.first + 1, curr.second, goal_x, goal_y, next_depth)) {
        ans += next_depth;
        goto NEXT_CHEESE;
      }
      if (wfs(curr.first - 1, curr.second, goal_x, goal_y, next_depth)) {
        ans += next_depth;
        goto NEXT_CHEESE;
      }
    }
  NEXT_CHEESE:;
    // cout << "ans = " << ans << endl;
  }

  cout << ans << endl;
  return 0;
}