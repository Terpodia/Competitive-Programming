#pragma GCC optimize("O3,unroll-loops")

#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
// #include<algorithm>
// #include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define len(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fore(i, a, b) for (auto i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define dfor(i, n) for (auto i = n; i-- > 0;)
#define dbg(x) cerr << "LINE" $ __LINE__ << ":" $ #x << "=" << x << endl;
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
#define $ << " " <<

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << '(' << p.first $ p.second << ')';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  forn(i, len(v)) {
    if (i) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  ll a[n];
  forn(i, n) cin >> a[i];
  set<pair<int, int>> cur;
  int l = 0, r = 0;
  fore(i, 1, n) {
    if (a[i] == a[l])
      r++;
    else {
      cur.insert({l, r});
      l = r = i;
    }
  }
  cur.insert({l, r});
  set<pair<int, int>> del;
  for (auto &[x, y] : cur) {
    del.insert({y - x + 1, x});
  }
  int res = 0;
  while (!del.empty()) {
    if (len(del) == 1) {
      res++;
      break;
    }
    if (len(del) == 2) {
      res += 2;
      break;
    }
    auto it = del.end();
    it--;
    auto it2 = del.lower_bound({it->fst, -1});
    int l = it2->snd, r = it2->snd + it2->fst - 1;

    auto it3 = cur.find({l, r});

    int l2 = -1, r2 = -1, l3 = -1, r3 = -1;

    if (it3 != cur.begin()) {
      it3--;
      l2 = it3->fst, r2 = it3->snd;
      it3++;
    }
    it3++;
    if (it3 != cur.end()) {
      l3 = it3->fst, r3 = it3->snd;
    }
    it3--;

    cur.erase(it3);
    del.erase(it2);

    if (l2 != -1 && l3 != -1) {
      if (a[l2] == a[l3]) {
        int l4 = l2, r4 = r2 + (r3 - l3 + 1);
        cur.erase({l2, r2});
        cur.erase({l3, r3});
        cur.insert({l4, r4});
        del.erase({r2 - l2 + 1, l2});
        del.erase({r3 - l3 + 1, l3});
        del.insert({r4 - l4 + 1, l4});
      }
    }
    res++;
  }
  cout << res << "\n";
  return 0;
}
