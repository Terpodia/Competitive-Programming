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

set<string> s;

void solve(deque<int>& b1, deque<int>& b2, int cnt = 0) {
  string t;
  fore(i, 0, SZ(b1)) t += to_string(b1[i]) + " ";
  t += "$";
  fore(i, 0, SZ(b2)) t += to_string(b2[i]) + " ";
  if (s.find(t) != s.end()) {
    cout << "-1\n";
    return;
  }
  s.insert(t);
  if (SZ(b2) == 0 || SZ(b1) == 0) {
    cout << cnt << " ";
    if (SZ(b2) == 0)
      cout << "1\n";
    else
      cout << "2\n";
    return;
  }
  if (b1[0] > b2[0]) {
    b1.push_back(b2[0]);
    b1.push_back(b1[0]);
    b1.pop_front();
    b2.pop_front();
  } else {
    b2.push_back(b1[0]);
    b2.push_back(b2[0]);
    b2.pop_front();
    b1.pop_front();
  }
  solve(b1, b2, cnt + 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k1, k2;
  cin >> n;
  cin >> k1;
  deque<int> b1(k1);
  fore(i, 0, k1) cin >> b1[i];
  cin >> k2;
  deque<int> b2(k2);
  fore(i, 0, k2) cin >> b2[i];
  solve(b1, b2);
  return 0;
}
