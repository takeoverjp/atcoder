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
  ll N, M;
  cin >> N >> M;
  vector<pair<ll, ll> > a(M), b(M);
  rep(i, M) {
    ll A, B;
    cin >> A >> B;
    a[i] = {A, B};
  }
  rep(i, M) {
    ll A, B;
    cin >> A >> B;
    b[i] = {A, B};
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<ll> P(N);
  rep(i, N) { P[i] = i + 1; }

  do {
    // cout << "P = ";
    // rep(i, N) { cout << P[i] << " "; }
    // cout << endl;
    for (auto& p : a) {
      pair<ll, ll> target;
      target.first = P[p.first - 1];
      target.second = P[p.second - 1];
      if (target.first > target.second) {
        swap(target.first, target.second);
      }
      // if (vector<ll>{3, 2, 1, 4} == P) {
      //   cout << "  target = " << target.first << " " << target.second <<
      //   endl;
      // }
      if (!binary_search(b.begin(), b.end(), target)) {
        goto NEXT;
      }
    }
    cout << "Yes" << endl;
    return 0;
  NEXT:;
  } while (std::next_permutation(P.begin(), P.end()));
  cout << "No" << endl;
  return 0;
}
#endif