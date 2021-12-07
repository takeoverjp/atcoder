#include <bits/stdc++.h>
// #include <atcoder/all>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

static ll solv(const vector<ll>& A) {
  ll size = A.size();
  vector<vector<ull> > dp(size + 1, vector<ull>(21, 0));
  dp[0][0] = 1;
  rep(j, size) {
    for (ll i = 0; i <= 20; i++) {
      if (i - A[j] >= 0) {
        dp[j + 1][i] += dp[j][i - A[j]];
      }
      if (j > 0 && i + A[j] <= 20) {
        dp[j + 1][i] += dp[j][i + A[j]];
      }
    }
  }
  // rep(j, size + 1) {
  //   rep(i, 21) { cerr << dp[j][i] << " "; }
  //   cerr << endl;
  // }
  return dp[size][0];
}

#if defined(TEST)
#include <lassert.h>
int main() {
  {
    vector<ll> A = {8, 3, 2, 4, 8, 7, 2, 4, 0, 8, 8};
    ASSERT_EQ(solv(A), 10);
  }
  {
    vector<ll> A = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1};
    ASSERT_EQ(solv(A), 7069052760);
  }
  {
    vector<ll> A = {0, 7, 2, 8, 4, 8, 3, 9, 4, 9, 7, 9, 0, 8, 4, 7, 9, 0, 1, 5,
                    3, 4, 3, 6, 9, 1, 9, 3, 0, 4, 7, 1, 3, 8, 6, 1, 8, 2, 4, 4,
                    3, 1, 3, 2, 7, 9, 6, 7, 6, 0, 0, 7, 0, 8, 8, 2, 8, 6, 4, 2,
                    7, 1, 6, 7, 0, 1, 6, 9, 6, 7, 9, 9, 3, 9, 4, 6, 3, 4, 1, 5,
                    5, 1, 3, 2, 6, 7, 1, 9, 4, 3, 8, 0, 4, 8, 7, 4, 7, 8, 1, 6};
    ASSERT_EQ(solv(A), 671013170798012928);
  }
  return 0;
}
#else

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  cout << solv(A) << endl;
  return 0;
}
#endif