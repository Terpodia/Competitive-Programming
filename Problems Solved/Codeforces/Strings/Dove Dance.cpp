#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()

#define fore(i, a, b) for (int i = a, ThxDem = b; i < ThxDem; ++i)

typedef long long ll;

struct Hash {
  int P = 1777771, MOD[2], PI[2];
  vector<int> h[2], pi[2];
  Hash(string& s) {
    MOD[0] = 999727999;
    MOD[1] = 1070777777;
    PI[0] = 325255434;
    PI[1] = 10018302;
    fore(k, 0, 2) h[k].resize(s.size() + 1), pi[k].resize(s.size() + 1);
    fore(k, 0, 2) {
      h[k][0] = 0;
      pi[k][0] = 1;
      ll p = 1;
      fore(i, 1, s.size() + 1) {
        h[k][i] = (h[k][i - 1] + p * s[i - 1]) % MOD[k];
        pi[k][i] = (1LL * pi[k][i - 1] * PI[k]) % MOD[k];
        p = (p * P) % MOD[k];
      }
    }
  }
  ll get(int s, int e) {
    ll h0 = (h[0][e] - h[0][s] + MOD[0]) % MOD[0];
    h0 = (1LL * h0 * pi[0][s]) % MOD[0];
    ll h1 = (h[1][e] - h[1][s] + MOD[1]) % MOD[1];
    h1 = (1LL * h1 * pi[1][s]) % MOD[1];
    return (h0 << 32) | h1;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int Q;
  cin >> Q;
  set<pair<ll, int>> s1, s2;
  bool r = false;

  while (Q--) {
    int t;
    cin >> t;
    if (t == 1) {
      string s;
      cin >> s;
      Hash hs(s);
      for (int i = 0; i < sz(s); i++) {
        if (!r)
          s1.insert({hs.get(0, i + 1), i + 1});
        else
          s2.insert({hs.get(0, i + 1), i + 1});
      }
      reverse(s.begin(), s.end());
      hs = Hash(s);
      for (int i = 0; i < sz(s); i++) {
        if (!r)
          s2.insert({hs.get(0, i + 1), i + 1});
        else
          s1.insert({hs.get(0, i + 1), i + 1});
      }
    } else if (t == 2) {
      string s;
      cin >> s;
      Hash hs(s);
      if (!r) {
        if (s1.find({hs.get(0, sz(s)), sz(s)}) != s1.end())
          cout << "1\n";
        else
          cout << "0\n";
      } else {
        if (s2.find({hs.get(0, sz(s)), sz(s)}) != s2.end())
          cout << "1\n";
        else
          cout << "0\n";
      }
    } else
      r = !r;
  }
  return 0;
}
