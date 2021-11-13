#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t N, K, A;
  cin >> N >> K >> A;
  int64_t ans = (K + A - 1) % N;
  cout << (ans ? ans : N) << endl;
  return 0;
}