#include <bits/stdc++.h>
using namespace std;
int main() {
  std::string s;
  cin >> s;

  long size = s.length();
  const char* str = s.c_str();
  const char* ptr = str;
  bool ret = false;
  while (ptr - str < size) {
    if ((ptr - str + 7 <= size) && strncmp(ptr, "dreamer", 7) == 0) {
      if (ptr - str + 7 == size) {
        ptr += 7;
        ret = true;
        break;
      }
      if (ptr[7] != 'a') {
        ptr += 7;
        continue;
      }
    }
    if ((ptr - str + 6 <= size) && strncmp(ptr, "eraser", 6) == 0) {
      if (ptr - str + 6 == size) {
        ptr += 6;
        ret = true;
        break;
      }
      if (ptr[6] != 'a') {
        ptr += 6;
        continue;
      }
    }
    if ((ptr - str + 5 <= size) &&
        (strncmp(ptr, "dream", 5) == 0 || strncmp(ptr, "erase", 5) == 0)) {
      if (ptr - str + 5 == size) {
        ptr += 5;
        ret = true;
        break;
      }
      ptr += 5;
      continue;
    }
    break;
  }
  cout << (ret ? "YES" : "NO") << endl;
  return 0;
}