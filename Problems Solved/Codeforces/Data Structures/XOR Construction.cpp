#include <bits/stdc++.h>
using namespace std;

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
  int child[2];
  Vertex() { child[0] = child[1] = -1; }
};
vector<Vertex> trie(1);
void add(int x) {
  int cur = 0;
  for (int i = 30; i >= 0; i--) {
    int idx = (bool)(x & (1 << i));
    if (trie[cur].child[idx] == -1) {
      trie[cur].child[idx] = SZ(trie);
      trie.emplace_back();
    }
    cur = trie[cur].child[idx];
  }
}
int search(int x) {
  int cur = 0, ret = 0;
  for (int i = 30; i >= 0; i--) {
    int idx = (bool)(x & (1 << i));
    idx = 1 - idx;
    if (trie[cur].child[idx] == -1)
      idx = 1 - idx;
    else
      ret |= (1 << i);
    cur = trie[cur].child[idx];
  }
  return ret;
}

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int acc[n - 1];
  fore(i, 0, n - 1) {
    int a;
    cin >> a;
    acc[i] = a;
    if (i > 0) acc[i] ^= acc[i - 1];
    add(acc[i]);
  }

  int b0 = 0;
  fore(i, 0, n) {
    if (search(i) < n) b0 = i;
  }
  cout << b0 << " ";
  fore(i, 0, n - 1) cout << (acc[i] ^ b0) << " ";
  cout << "\n";
  return 0;
}
