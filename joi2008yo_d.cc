#include <bits/stdc++.h>
using namespace std;
int main() {
  int m;
  cin >> m;
  vector<pair<int, int>> seiza(m);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    seiza[i] = make_pair(x, y);
  }
  int n;
  cin >> n;
  vector<pair<int, int>> stars(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    stars[i] = make_pair(x, y);
  }
  sort(seiza.begin(), seiza.end());
  sort(stars.begin(), stars.end());
  for (int i = 0; i < n; i++) {
    auto diff_x = stars[i].first - seiza[0].first;
    auto diff_y = stars[i].second - seiza[0].second;
    for (int j = 1; j < m; j++) {
      if (!binary_search(
              stars.begin(), stars.end(),
              make_pair(seiza[j].first + diff_x, seiza[j].second + diff_y))) {
        goto NEXT;
      }
    }
    cout << diff_x << " " << diff_y << endl;
    return 0;
  NEXT:;
  }
  return 0;
}