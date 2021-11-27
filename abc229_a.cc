#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main() {
  string S1, S2;
  cin >> S1 >> S2;
  if (S1 == "##" || S2 == "##") {
    cout << "Yes" << endl;
    return 0;
  }
  if (S1[0] == '#' && S2[0] == '#') {
    cout << "Yes" << endl;
    return 0;
  }
  if (S1[1] == '#' && S2[1] == '#') {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}