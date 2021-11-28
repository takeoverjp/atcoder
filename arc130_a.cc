#include <bits/stdc++.h>

// #include <atcoder/all>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

static ll solve(int N, string& S) {
  char last = S[0];
  ll ans = 0;
  ll count = 1;
  for (int i = 1; i < N; i++) {
    if (S[i] == last) {
      count++;
    } else {
      if (count > 1) {
        ans += count * (count - 1) / 2;
      }
      count = 1;
      last = S[i];
    }
  }
  if (count > 1) {
    ans += count * (count - 1) / 2;
  }
  return ans;
}
#if defined(TEST)
#include <lassert.h>
int main() {
  string S = "abbbcca";
  ASSERT_EQ(solve(S.size(), S), 4);
  return 0;
}
#else

int main() {
  ll N;
  string S;
  cin >> N >> S;
  cout << solve(N, S) << endl;
  return 0;
}
#endif