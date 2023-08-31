#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<int> x; x.find_by_order(y); x.order_of_key(y)

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define fore(i, x, n) for (auto i = (x); i < (n); i++)
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " "
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]
typedef long long ll;
typedef long double ld;

struct Vertex {
  int child[26];
  ll cnt = 0;
  Vertex() { fore(i, 0, 26) child[i] = -1; }
};
struct Trie {
  vector<Vertex> trie;
  Trie() { trie = vector<Vertex>(1); }
  void add(string& s) {
    int cur = 0;
    fore(i, 0, SZ(s)) {
      if (trie[cur].child[s[i] - 'a'] == -1) {
        trie[cur].child[s[i] - 'a'] = SZ(trie);
        trie.emplace_back();
      }
      cur = trie[cur].child[s[i] - 'a'];
    }
    trie[cur].cnt++;
  }
  ll search(string s, int& cur) {
    fore(i, 0, SZ(s)) {
      if (trie[cur].child[s[i] - 'a'] == -1) return 0;
      cur = trie[cur].child[s[i] - 'a'];
    }
    return trie[cur].cnt;
  }
};

const int MAXN = 5007;
const ll MOD = 1e9 + 7;

string s;
Trie dic;
ll dp[MAXN];

ll solve(int i) {
  if (i == SZ(s)) return 1;
  ll& ret = dp[i];
  if (ret != -1) return ret;
  int cur = 0;
  ret = 0;
  fore(j, i, SZ(s)) {
    if (dic.trie[cur].child[s[j] - 'a'] == -1) break;
    ret += (dic.search(string(1, s[j]), cur) * solve(j + 1)) % MOD;
    ret %= MOD;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> s >> k;
  fore(i, 0, k) {
    string p;
    cin >> p;
    dic.add(p);
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(0) << "\n";
  return 0;
}
