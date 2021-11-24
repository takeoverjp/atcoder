#include <bits/stdc++.h>
using namespace std;

static void dfs(vector<vector<int>> &c, int64_t i, int64_t j) {
  if (i < 0 || j < 0 || i >= c.size() || j >= c[0].size() || c[i][j] == 0 ||
      c[i][j] == '#')
    return;
  c[i][j] = '#';
  dfs(c, i - 1, j);
  dfs(c, i + 1, j);
  dfs(c, i, j - 1);
  dfs(c, i, j + 1);
  dfs(c, i - 1, j - 1);
  dfs(c, i - 1, j + 1);
  dfs(c, i + 1, j - 1);
  dfs(c, i + 1, j + 1);
}

static int64_t solve(vector<vector<int>> &c) {
  int64_t cnt = 0;
  for (int64_t i = 0; i < c.size(); i++) {
    for (int64_t j = 0; j < c[i].size(); j++) {
      if (c[i][j] == 1) {
        cnt++;
        dfs(c, i, j);
      }
    }
  }
  return cnt;
}

//#define TEST
#ifdef TEST
static void test() {
  vector<vector<int>> c;
  c = {{0}};
  assert(solve(c) == 0);
  c = {{0, 1}, {1, 0}};
  assert(solve(c) == 1);
  c = {{1, 1, 1}, {1, 1, 1}};
  assert(solve(c) == 1);
  c = {{1, 0, 1, 0, 0}, {1, 0, 0, 0, 0}, {1, 0, 1, 0, 1}, {1, 0, 0, 1, 0}};
  assert(solve(c) == 3);
  c = {{1, 1, 1, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}};
  assert(solve(c) == 1);
  c = {{1, 0, 1, 0, 1},
       {0, 0, 0, 0, 0},
       {1, 0, 1, 0, 1},
       {0, 0, 0, 0, 0},
       {1, 0, 1, 0, 1}};
  assert(solve(c) == 9);
  exit(0);
}
#endif  // TEST

int main() {
#ifdef TEST
  test();
#endif  // TEST

  while (true) {
    int64_t w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) {
      return 0;
    }
    vector<vector<int>> c(h, vector<int>(w));
    for (int64_t i = 0; i < h; i++) {
      for (int64_t j = 0; j < w; j++) {
        cin >> c[i][j];
      }
    }
    cout << solve(c) << endl;
  }
  return 0;
}