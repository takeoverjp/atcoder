#include <bits/stdc++.h>
using namespace std;

static string solve(int64_t N) {
  vector<int64_t> c;
  while (N) {
    for (int64_t i = N + 1; i >= 1; i--) {
      if (2 * N >= i * (i - 1)) {
        c.push_back(i);
        // cout << "i = " << i << endl;
        N -= i * (i - 1) / 2;
        break;
      }
    }
  }
  string ans;
  for (int i = 1; i < c[0]; i++) {
    ans = "7" + ans;
  }
  int last_rem = 0;
  int size = c.size();
  for (int i = 1; i < size; i++) {
    for (int j = 0; j < c[i]; j++) {
      int unit = 1;
      for (size_t l = 0; l < ans.size(); l++) {
        unit *= 10;
        unit %= 7;
      }
      for (int k = 0; k < 7; k++) {
        if ((unit * k + last_rem) % 7 == i) {
          ans = to_string(k ? k : 7) + ans;
          last_rem = i;
          break;
        }
      }
    }
  }
  return ans;
}

#if defined(TEST)
static int64_t count(int64_t N) {
  int64_t ret = 0;
  for (int64_t r = 0; pow(10, r) <= N; r++) {
    for (int64_t l = r + 1; pow(10, l) <= N * 10; l++) {
      int64_t vl = N / (int64_t)pow(10, l - 1) * (int64_t)pow(10, l - 1);
      int64_t vr =
          (r == 0) ? 0
                   : (N / (int64_t)pow(10, r - 1) * (int64_t)pow(10, r - 1));
      if ((vr - vl) % 7 == 0) {
        // cout << "vl = " << vl << ", vr = " << vr << ", vr-vl = " << vr - vl
        //      << endl;
        ret++;
      }
    }
  }
  // cout << "count end" << endl;
  return ret;
}
#endif

int main() {
#if defined(TEST)
  for (int i = 1; i < 53; i++) {
    cout << i << " " << solve(i) << " " << count(stoll(solve(i))) << endl;
    assert(count(stoll(solve(i))) == i);
  }
#endif
  int64_t N;
  cin >> N;
  cout << solve(N) << endl;
  return 0;
}