#include <bits/stdc++.h>
// #include <atcoder/all>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const int odx[] = {1, 1, 1, 0, -1, 0};
const int ody[] = {-1, 0, 1, 1, 0, -1};
const int edx[] = {0, 1, 0, -1, -1, -1};
const int edy[] = {-1, 0, 1, 1, 0, -1};
static void dfs(vector<vector<int>>& board, vector<vector<bool>>& is_outside,
                ll x, ll y) {
  if (y < 0 || y >= board.size() || x < 0 || x >= board[0].size()) {
    return;
  }
  if (board[y][x]) {
    return;
  }
  if (is_outside[y][x]) {
    return;
  }
  is_outside[y][x] = true;
  for (int i = 0; i < 6; i++) {
    int nx = x + ((y % 2) ? odx[i] : edx[i]);
    int ny = y + ((y % 2) ? ody[i] : edy[i]);
    dfs(board, is_outside, nx, ny);
  }
}

#if defined(TEST)
#include <lassert.h>
int main() {
  ASSERT_EQ(0, 0);
  return 0;
}
#else

int main() {
  ll W, H;
  cin >> W >> H;
  vector<vector<int>> board(H + 2, vector<int>(W + 2, 0));
  rep(y, H) {
    rep(x, W) { cin >> board[y + 1][x + 1]; }
  }
  vector<vector<bool>> is_outside(H + 2, vector<bool>(W + 2, false));
  dfs(board, is_outside, 0, 0);
  // rep(y, H + 2) {
  //   rep(x, W + 2) { cout << (is_outside[y][x] ? '*' : '.') << ' '; }
  //   cout << endl;
  // }

  ll ans = 0;
  rep(x, W + 2) {
    rep(y, H + 2) {
      for (int i = 0; i < 6; i++) {
        int nx = x + ((y % 2) ? odx[i] : edx[i]);
        int ny = y + ((y % 2) ? ody[i] : edy[i]);
        if (!is_outside[y][x] && is_outside[ny][nx]) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
#endif