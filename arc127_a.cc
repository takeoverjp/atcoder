#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n;
  cin >> n;

  int64_t ret = 0;

  for (int64_t i = n; i >= 1; i--) {
    int64_t next = 1;
    int64_t next_order = 0;
    while (i >= next * 10) {
      next *= 10;
      next_order++;
    }

    int64_t floor = next;
    int64_t f = 0;
    char digit = 0;
    while (floor) {
      digit = (i / floor) % 10;
      if (digit != 1) {
        break;
      }
      f++;
      floor /= 10;
    }

    if (f == 0) {
      ret += (100 * next - 10 - 9 * (next_order + 1)) / 81;
      break;
    }

    if (digit != 1) {
      ret += f * (i % floor + 1);
      i -= i % floor;
      continue;
    }

    ret += f;
  }

  cout << ret << endl;
  return 0;
}