#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main() {
  ll N, W;
  cin >> N >> W;
  vector<pair<ll, ll>> cheese(N);
  rep(i, N) {
    ll a, b;
    cin >> a >> b;
    cheese[i] = {a, b};
  }
  sort(cheese.begin(), cheese.end(),
       [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
         return a.first > b.first;
       });
  ll ans = 0;
  rep(i, N) {
    // cout << "i = " << i << ", cheese = " << cheese[i].first << ", "
    //      << cheese[i].second << endl;
    if (cheese[i].second > W) {
      ans += W * cheese[i].first;
      break;
    }
    ans += cheese[i].first * cheese[i].second;
    W -= cheese[i].second;
  }
  cout << ans << endl;
  return 0;
}