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

struct Trie {
  struct Vertex {
    int child[26];
    bool leaf = false;
    Vertex() { fore(i, 0, 26) child[i] = -1; }
  };
  vector<Vertex> trie;
  Trie() { trie = vector<Vertex>(1); }
  void add(string& s) {
    int cur = 0;
    fore(i, 0, SZ(s)) {
      if (trie[cur].child[s[i] - 'a'] == -1) {
        trie[cur].child[s[i] - 'a'] = SZ(trie);
        trie.emplace_back();
      }
      trie[cur].leaf = false;
      cur = trie[cur].child[s[i] - 'a'];
    }
    trie[cur].leaf = true;
    fore(i, 0, 26) trie[cur].leaf &= trie[cur].child[i] == -1;
  }
};

const int MAXN = 1e5 + 10;

Trie t;
int win[MAXN][2], lose[MAXN][2];

pair<int, int> solve(int v, int turn = 0) {
  int& w = win[v][turn];
  int& l = lose[v][turn];
  if (w != -1) return mp(w, l);
  if (t.trie[v].leaf) {
    if (turn == 0)
      return mp(0, 1);
    else
      return mp(1, 0);
  }
  if (turn == 0)
    w = 0, l = 0;
  else
    w = 1, l = 1;

  for (int u : t.trie[v].child)
    if (u != -1) {
      pair<int, int> res = solve(u, 1 - turn);
      if (turn == 0)
        w = max(w, res.fst), l = max(l, res.snd);
      else
        w = min(w, res.fst), l = min(l, res.snd);
    }
  return mp(w, l);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  fore(i, 0, n) {
    string s;
    cin >> s;
    t.add(s);
  }
  memset(win, -1, sizeof(win));
  memset(lose, -1, sizeof(lose));
  solve(0);
  if (win[0][0] == 1 && lose[0][0] == 1)
    cout << "First\n";
  else if (lose[0][0] == 1)
    cout << "Second\n";
  else if (win[0][0] == 0)
    cout << "Second\n";
  else {
    if (k % 2 == 0)
      cout << "Second\n";
    else
      cout << "First\n";
  }
  return 0;
}
