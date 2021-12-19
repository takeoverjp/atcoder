#include <bits/stdc++.h>
// #include <atcoder/all>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
#define INF INT64_MAX
#if defined(TEST)
#include <lassert.h>
int main() {
  ASSERT_EQ(0, 0);
  return 0;
}
#else

int main() {
  string S, T;
  cin >> S >> T;
  ll K = (T[0] + 26 - S[0]) % 26;
  for (ll i = 1; i < (ll)S.size(); i++) {
    if ((S[i] - 'a' + K) % 26 + 'a' != T[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
#endif