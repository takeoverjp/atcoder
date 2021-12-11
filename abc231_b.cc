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
  ll N;
  cin >> N;
  map<string, ll> m;
  rep(i, N) {
    string s;
    cin >> s;
    m[s]++;
  }
  ll ans = 0;
  string name;
  for (auto &pair : m) {
    if (pair.second > ans) {
      ans = pair.second;
      name = pair.first;
    }
  }
  cout << name << endl;
  return 0;
}
#endif