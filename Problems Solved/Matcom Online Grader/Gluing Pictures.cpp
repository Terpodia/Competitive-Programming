#include "bits/stdc++.h"
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
#define raya                                                                   \
  cerr << "\n----------------------------------------------------------------" \
          "-------------\n"
#define $ << " " <<

typedef long long ll;

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << '(' << p.fst $ p.snd << ')';
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

#define RB(x) (x < n ? r[x] : 0)
void csort(vector<int> &sa, vector<int> &r, int k) {
  int n = sa.size();
  vector<int> f(max(255, n), 0), t(n);
  fore(i, 0, n) f[RB(i + k)]++;
  int sum = 0;
  fore(i, 0, max(255, n)) f[i] = (sum += f[i]) - f[i];
  fore(i, 0, n) t[f[RB(sa[i] + k)]++] = sa[i];
  sa = t;
}
vector<int> constructSA(string &s) {  // O(n logn)
  int n = s.size(), rank;
  vector<int> sa(n), r(n), t(n);
  fore(i, 0, n) sa[i] = i, r[i] = s[i];
  for (int k = 1; k < n; k *= 2) {
    csort(sa, r, k);
    csort(sa, r, 0);
    t[sa[0]] = rank = 0;
    fore(i, 1, n) {
      if (r[sa[i]] != r[sa[i - 1]] || RB(sa[i] + k) != RB(sa[i - 1] + k))
        rank++;
      t[sa[i]] = rank;
    }
    r = t;
    if (r[sa[n - 1]] == n - 1) break;
  }
  return sa;
}

const ll P = 1777771, MOD[2] = {999727999, 1070777777};

struct Hash {
  vector<ll> h[2], pow[2];
  Hash() {}
  Hash(string &s) {
    fore(k, 0, 2) h[k] = vector<ll>(len(s) + 1, 0),
                  pow[k] = vector<ll>(len(s) + 1, 1);
    fore(k, 0, 2) fore(i, 1, len(s) + 1) {
      h[k][i] = (h[k][i - 1] * P + (ll)s[i - 1]) % MOD[k];
      pow[k][i] = (pow[k][i - 1] * P) % MOD[k];
    }
  }
  ll get(int l, int r) {
    ll ret[2];
    fore(k, 0, 2) ret[k] =
        ((h[k][r] - pow[k][r - l] * h[k][l]) % MOD[k] + MOD[k]) % MOD[k];
    return (ret[0] << 32LL) | ret[1];
  }
};

vector<int> sa;

Hash hs, ht;
int l, r, n;

string s;
string t;

bool cmp(int j) {
  int cmp_l = 0, cmp_r = min(n - j, r - l + 1);
  while (cmp_r > cmp_l) {
    int mid = cmp_l + (cmp_r - cmp_l + 1) / 2;
    if (hs.get(j, j + mid) == ht.get(l, l + mid))
      cmp_l = mid;
    else
      cmp_r = mid - 1;
  }
  if (cmp_l == min(n - j, r - l + 1)) return n - j >= r - l + 1;
  return s[cmp_l + j] > t[cmp_l + l];
}

bool can() {
  if (r - l + 1 > len(s)) return false;

  int sa_l = 0, sa_r = n - 1;
  while (sa_r > sa_l) {
    int mid = sa_l + (sa_r - sa_l) / 2;
    if (cmp(sa[mid]))
      sa_r = mid;
    else
      sa_l = mid + 1;
  }

  int m = min(n, sa[sa_r] + r - l + 1);
  return hs.get(sa[sa_r], m) == ht.get(l, r + 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  n = len(s);

  sa = constructSA(s);
  hs = Hash(s);

  int q;
  cin >> q;

  forn(tt, q) {
    cin >> t;
    ht = Hash(t);
    l = 0, r = 0;

    int ans = 0;
    bool flag = true;
    fore(j, 0, len(t)) {
      r = j;
      if (l == r) {
        ans++;
        if (!can()) {
          flag = false;
          break;
        }
      } else {
        if (!can()) {
          l = r;
          ans++;
          if (!can()) {
            // dbg(l);
            // dbg(r);
            flag = false;
            break;
          }
        }
      }
    }
    if (!flag)
      cout << "-1\n";
    else
      cout << ans << "\n";
  }
  return 0;
}
