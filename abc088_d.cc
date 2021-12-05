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

int main() {
  ll H, W;
  cin >> H >> W;
  vector<vector<char> > s(H, vector<char>(W));
  vector<vector<ll> > depth(H, vector<ll>(W, -1));
  rep(y, H) {
    rep(x, W) { cin >> s[y][x]; }
  }
  ll white = 0;
  rep(y, H) {
    rep(x, W) {
      if (s[y][x] == '.') white++;
    }
  }
  std::queue<pair<ll, ll> > todo;
  todo.push(make_pair(0, 0));
  depth[0][0] = 1;
  while (!todo.empty()) {
    auto p = todo.front();
    todo.pop();
    if (p.first == H - 1 && p.second == W - 1) {
      cout << (white - depth[H - 1][W - 1]) << endl;
      return 0;
    }
    ll curr_x = p.first, curr_y = p.second;
#define HANDLE(next_x, next_y)                                     \
  do {                                                             \
    if (next_x >= 0 && next_x < H && next_y >= 0 && next_y < W &&  \
        s[next_x][next_y] == '.' && depth[next_x][next_y] == -1) { \
      todo.push(make_pair(next_x, next_y));                        \
      depth[next_x][next_y] = depth[curr_x][curr_y] + 1;           \
    }                                                              \
  } while (0)
    HANDLE((p.first - 1), (p.second));
    HANDLE((p.first + 1), (p.second));
    HANDLE((p.first), (p.second - 1));
    HANDLE((p.first), (p.second + 1));
  }
  cout << -1 << endl;
  return 0;
}
#endif