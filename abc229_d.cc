#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

//#define TEST

#if defined(TEST)
#include "lassert.h"
#endif

static bool judge(string &S, ll K, ll len) {
  ll size = S.size();
  ll cnt = 0;
  rep(i, len) {
    if (S[i] == '.') {
      cnt++;
    }
  }
  if (cnt <= K) {
    return true;
  }
  for (ll offset = 1; offset + len <= size; ++offset) {
    if (S[offset - 1] == '.') {
      cnt--;
    }
    if (S[len - 1 + offset] == '.') {
      cnt++;
    }

    if (cnt <= K) {
      return true;
    }
  }

  return false;
}

static ll solve(string &S, ll K) {
  ll l = 0;
  ll r = S.length();
  while (l < r) {
    ll m = (l + r) / 2;
    if (judge(S, K, m)) {
      if (l == m) {
        break;
      }
      l = m;
    } else {
      r = m;
    }
  }
  if (judge(S, K, l + 1)) {
    l++;
  }
  return l;
}

int main() {
#if defined(TEST)
  {
    string s(".");
    ASSERT_EQ(solve(s, 1), 1);
    ASSERT_EQ(solve(s, 2), 1);
    ASSERT_EQ(solve(s, 3), 1);
  }
  {
    string s("X");
    ASSERT_EQ(solve(s, 0), 1);
    ASSERT_EQ(solve(s, 1), 1);
    ASSERT_EQ(solve(s, 2), 1);
    ASSERT_EQ(solve(s, 3), 1);
  }
  {
    string s("..");
    ASSERT_EQ(solve(s, 1), 1);
    ASSERT_EQ(solve(s, 2), 2);
    ASSERT_EQ(solve(s, 3), 2);
  }
  {
    string s("X.");
    ASSERT_EQ(solve(s, 0), 1);
    ASSERT_EQ(solve(s, 1), 2);
    ASSERT_EQ(solve(s, 2), 2);
    ASSERT_EQ(solve(s, 3), 2);
  }
  {
    string s("XX");
    ASSERT_EQ(solve(s, 0), 2);
    ASSERT_EQ(solve(s, 1), 2);
    ASSERT_EQ(solve(s, 2), 2);
    ASSERT_EQ(solve(s, 3), 2);
  }
  {
    string s("X.X");
    ASSERT_EQ(solve(s, 0), 1);
    ASSERT_EQ(solve(s, 1), 3);
    ASSERT_EQ(solve(s, 2), 3);
    ASSERT_EQ(solve(s, 3), 3);
    ASSERT_EQ(solve(s, 4), 3);
  }
  {
    string s("X.X.");
    ASSERT_EQ(solve(s, 0), 1);
    ASSERT_EQ(solve(s, 1), 3);
    ASSERT_EQ(solve(s, 2), 4);
    ASSERT_EQ(solve(s, 3), 4);
    ASSERT_EQ(solve(s, 4), 4);
    ASSERT_EQ(solve(s, 5), 4);
  }
  {
    string s(".X.X.");
    ASSERT_EQ(solve(s, 0), 1);
    ASSERT_EQ(solve(s, 1), 3);
    ASSERT_EQ(solve(s, 2), 4);
    ASSERT_EQ(solve(s, 3), 5);
    ASSERT_EQ(solve(s, 4), 5);
    ASSERT_EQ(solve(s, 5), 5);
  }
  {
    string s(".X.XX");
    ASSERT_EQ(solve(s, 0), 2);
    ASSERT_EQ(solve(s, 1), 4);
    ASSERT_EQ(solve(s, 2), 5);
    ASSERT_EQ(solve(s, 3), 5);
    ASSERT_EQ(solve(s, 4), 5);
    ASSERT_EQ(solve(s, 5), 5);
  }
  {
    string s(".....");
    ASSERT_EQ(solve(s, 0), 0);
    ASSERT_EQ(solve(s, 1), 1);
    ASSERT_EQ(solve(s, 2), 2);
    ASSERT_EQ(solve(s, 3), 3);
    ASSERT_EQ(solve(s, 4), 4);
    ASSERT_EQ(solve(s, 5), 5);
  }
  {
    string s("XXXXX");
    ASSERT_EQ(solve(s, 0), 5);
    ASSERT_EQ(solve(s, 1), 5);
    ASSERT_EQ(solve(s, 2), 5);
    ASSERT_EQ(solve(s, 3), 5);
    ASSERT_EQ(solve(s, 4), 5);
    ASSERT_EQ(solve(s, 5), 5);
  }
  {
    string s(
        "......................................................................"
        "......................................................................"
        "......................................................................"
        "...................................................................."
        "..");
    ASSERT_EQ(solve(s, 0), 0);
    ASSERT_EQ(solve(s, 1), 1);
    ASSERT_EQ(solve(s, 2), 2);
    ASSERT_EQ(solve(s, 280), 280);
    ASSERT_EQ(solve(s, 281), 280);
  }
  {
    string s(
        "..X.X................................................................."
        ".....XXXX.X..........................................................."
        "...........XXXX.X..XX...X............................................."
        "...................................................................."
        "..");
    ASSERT_EQ(solve(s, 0), 4);
    ASSERT_EQ(solve(s, 1), 6);
    ASSERT_EQ(solve(s, 2), 7);
    ASSERT_EQ(solve(s, 3), 10);
    ASSERT_EQ(solve(s, 4), 11);
    ASSERT_EQ(solve(s, 5), 12);
    ASSERT_EQ(solve(s, 6), 14);
    ASSERT_EQ(solve(s, 280), 280);
    ASSERT_EQ(solve(s, 281), 280);
  }
#else
  string S;
  ll K;
  cin >> S >> K;
  cout << solve(S, K) << endl;
#endif
  return 0;
}