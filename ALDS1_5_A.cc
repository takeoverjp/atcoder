#include <bits/stdc++.h>
using namespace std;

static bool can_consist(vector<int> &a, int start, int m) {
  if (a.size() == start - 1) {
    return m == 0;
  }
  if (can_consist(a, start + 1, m - a[start])) {
    return true;
  }
  if (can_consist(a, start + 1, m)) {
    return true;
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int m;
    cin >> m;
    cout << (can_consist(a, 0, m) ? "yes" : "no") << endl;
  }
  return 0;
}