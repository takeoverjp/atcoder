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
  string S;
  cin >> S;
  cout << ((S[0] - '0') * (S[2] - '0')) << endl;
  return 0;
}
#endif