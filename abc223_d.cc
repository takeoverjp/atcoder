#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, m;
  cin >> n >> m;

  // Covert A[i]/B[i] into graph
  vector<int64_t> indeg(n, 0);
  vector<vector<int64_t>> out(n);
  for (int64_t i = 0; i < m; i++) {
    int64_t a, b;
    cin >> a >> b;
    a--;  // 1-origin -> 0-origin
    b--;  // 1-origin -> 0-origin
    indeg[b]++;
    out[a].push_back(b);
  }

  // Collect zero degree nodes
  std::priority_queue<int64_t, vector<int64_t>, greater<int64_t>> zero_degrees;
  for (int64_t i = 0; i < n; i++) {
    if (indeg[i] == 0) {
      zero_degrees.push(i);
    }
  }

  // Insert zero degree nodes in increasing order
  vector<int64_t> ret;
  ret.reserve(n);
  while (!zero_degrees.empty()) {
    int64_t next = zero_degrees.top();
    zero_degrees.pop();
    ret.push_back(next + 1);  // 0-origin -> 1-origin for answer
    for (const auto dest : out[next]) {
      indeg[dest]--;
      if (indeg[dest] == 0) {
        zero_degrees.push(dest);
      }
    }
  }

  // If some edges are left, no solution
  if (static_cast<int64_t>(ret.size()) != n) {
    cout << "-1" << endl;
    return 0;
  }

  for (int i = 0; i < n; i++) {
    if (i < n - 1) {
      cout << ret[i] << " ";
    } else {
      cout << ret[i] << endl;
    }
  }
  return 0;
}