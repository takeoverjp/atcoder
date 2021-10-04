#include <bits/stdc++.h>
using namespace std;

static vector<string> rotate_90(const vector<string>& mat) {
  vector<string> ret;
  int size = mat.size();
  ret.resize(size);
  for (int y = 0; y < size; y++) {
    ret[y].resize(size);
    for (int x = 0; x < size; x++) {
      ret[y][x] = mat[x][size - 1 - y];
    }
  }
  return ret;
}

static vector<string> shift(const vector<string>& mat, int m, int n) {
  vector<string> ret;
  int size = mat.size();
  ret.resize(size);
  for (int y = 0; y < size; y++) {
    ret[y].resize(size);
    for (int x = 0; x < size; x++) {
      if (y >= n && x >= m && (y - n < size - 1) && (x - m < size - 1)) {
        ret[y][x] = mat[y - n][x - m];
      } else {
        ret[y][x] = '.';
      }
    }
  }
  return ret;
}

static pair<int, int> find_lt(const vector<string>& mat) {
  int size = mat.size();
  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      if (mat[y][x] == '#') {
        return make_pair(x, y);
      }
    }
  }
  cout << "Yes" << endl;
  exit(0);
}
static bool is_same_mat(const vector<string>& mat1, const vector<string>& mat2) {
  auto [x1, y1] = find_lt(mat1);
  auto [x2, y2] = find_lt(mat2);
  return mat1 == shift(mat2, x1 - x2, y1 - y2);
}

#if 0
static void dump(const vector<string>& mat) {
  cout << "--------------" << endl;
  for (const auto& row : mat) {
    cout << row << endl;
  }
  cout << "--------------" << endl;
}
#endif

int main() {
  int64_t n;
  cin >> n;
  vector<string> s, t;
  s.resize(n);
  t.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }

#if 0
  dump(s);
  dump(shift(s, 1, 3));
  dump(rotate_90(shift(s, 1, 3)));
#endif

  for (int i = 0; i < 4; i++) {
    if (is_same_mat(s, t)) {
      cout << "Yes" << endl;
      return 0;
    }
    s = rotate_90(s);
  }

  cout << "No" << endl;
  return 0;
}