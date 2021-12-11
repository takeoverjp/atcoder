#include <bits/stdc++.h>
// #include <atcoder/all>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
#if defined(TEST)
#include <lassert.h>
int main() {
  ASSERT_EQ(0, 0);
  return 0;
}
#else

int main() {
  ll N, Q;
  cin >> N >> Q;
  vector<ll> A(N);
  rep(i, N) { cin >> A[i]; }
  sort(A.begin(), A.end());
  rep(i, Q) {
    ll x;
    cin >> x;
    cout << (A.end() - lower_bound(A.begin(), A.end(), x)) << endl;
  }
  return 0;
}
#endif