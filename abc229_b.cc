#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main() {
  string A, B;
  cin >> A >> B;
  int limit = min(A.length(), B.length());
  rep(i, limit + 1) {
    if ((A[A.length() - i] - '0') + (B[B.length() - i] - '0') >= 10) {
      cout << "Hard" << endl;
      return 0;
    }
  }
  cout << "Easy" << endl;
  return 0;
}