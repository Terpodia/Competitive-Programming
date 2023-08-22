// Si puedes imaginarlo puedes programarlo
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
#define erof(i, x, n) for (auto i = (x); i > (n); i--)
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " "
#define line \
  cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]

const char aux[4] = {'A', 'G', 'C', 'T'};
const int INF = 1e9;

int n, m;
vector<vector<char>> a;

vector<vector<char>> row(int x, int y, int& res) {
  bool check[4];
  fore(i, 0, 4) check[i] = false;
  check[x] = check[y] = true;
  int k = -1, z = -1;
  fore(i, 0, 4) if (!check[i]) { (k == -1) ? k = i : z = i; }

  vector<vector<char>> ret(n, vector<char>(m));

  fore(i, 0, n) {
    int cnt1 = 0, cnt2 = 0;
    fore(j, 0, m) {
      if (i % 2 == 0) {
        if (j % 2 == 0)
          cnt1 += (aux[x] != a[i][j]) ? 1 : 0;
        else
          cnt1 += (aux[y] != a[i][j]) ? 1 : 0;
      } else {
        if (j % 2 == 0)
          cnt1 += (aux[k] != a[i][j]) ? 1 : 0;
        else
          cnt1 += (aux[z] != a[i][j]) ? 1 : 0;
      }
    }
    fore(j, 0, m) {
      if (i % 2 == 0) {
        if (j % 2 == 0)
          cnt2 += (aux[y] != a[i][j]) ? 1 : 0;
        else
          cnt2 += (aux[x] != a[i][j]) ? 1 : 0;
      } else {
        if (j % 2 == 0)
          cnt2 += (aux[z] != a[i][j]) ? 1 : 0;
        else
          cnt2 += (aux[k] != a[i][j]) ? 1 : 0;
      }
    }
    if (cnt1 < cnt2) {
      fore(j, 0, m) {
        if (i % 2 == 0) {
          if (j % 2 == 0)
            ret[i][j] = aux[x];
          else
            ret[i][j] = aux[y];
        } else {
          if (j % 2 == 0)
            ret[i][j] = aux[k];
          else
            ret[i][j] = aux[z];
        }
      }
    } else {
      fore(j, 0, m) {
        if (i % 2 == 0) {
          if (j % 2 == 0)
            ret[i][j] = aux[y];
          else
            ret[i][j] = aux[x];
        } else {
          if (j % 2 == 0)
            ret[i][j] = aux[z];
          else
            ret[i][j] = aux[k];
        }
      }
    }
    res += min(cnt1, cnt2);
  }
  return ret;
}

vector<vector<char>> col(int x, int y, int& res) {
  bool check[4];
  fore(i, 0, 4) check[i] = false;
  check[x] = check[y] = true;
  int k = -1, z = -1;
  fore(i, 0, 4) if (!check[i]) { (k == -1) ? k = i : z = i; }

  vector<vector<char>> ret(n, vector<char>(m));

  fore(j, 0, m) {
    int cnt1 = 0, cnt2 = 0;
    fore(i, 0, n) {
      if (j % 2 == 0) {
        if (i % 2 == 0)
          cnt1 += (aux[x] != a[i][j]) ? 1 : 0;
        else
          cnt1 += (aux[y] != a[i][j]) ? 1 : 0;
      } else {
        if (i % 2 == 0)
          cnt1 += (aux[k] != a[i][j]) ? 1 : 0;
        else
          cnt1 += (aux[z] != a[i][j]) ? 1 : 0;
      }
    }
    fore(i, 0, n) {
      if (j % 2 == 0) {
        if (i % 2 == 0)
          cnt2 += (aux[y] != a[i][j]) ? 1 : 0;
        else
          cnt2 += (aux[x] != a[i][j]) ? 1 : 0;
      } else {
        if (i % 2 == 0)
          cnt2 += (aux[z] != a[i][j]) ? 1 : 0;
        else
          cnt2 += (aux[k] != a[i][j]) ? 1 : 0;
      }
    }
    if (cnt1 < cnt2) {
      fore(i, 0, n) {
        if (j % 2 == 0) {
          if (i % 2 == 0)
            ret[i][j] = aux[x];
          else
            ret[i][j] = aux[y];
        } else {
          if (i % 2 == 0)
            ret[i][j] = aux[k];
          else
            ret[i][j] = aux[z];
        }
      }
    } else {
      fore(i, 0, n) {
        if (j % 2 == 0) {
          if (i % 2 == 0)
            ret[i][j] = aux[y];
          else
            ret[i][j] = aux[x];
        } else {
          if (i % 2 == 0)
            ret[i][j] = aux[z];
          else
            ret[i][j] = aux[k];
        }
      }
    }
    res += min(cnt1, cnt2);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  a = vector<vector<char>>(n, vector<char>(m));
  fore(i, 0, n) fore(j, 0, m) cin >> a[i][j];

  int curr = INF;
  vector<vector<char>> ans;

  fore(i, 0, 4) fore(j, i + 1, 4) {
    int res = 0;
    vector<vector<char>> b = row(i, j, res);
    if (res < curr) {
      curr = res;
      ans = b;
    }
  }
  fore(i, 0, 4) fore(j, i + 1, 4) {
    int res = 0;
    vector<vector<char>> b = col(i, j, res);
    if (res < curr) {
      curr = res;
      ans = b;
    }
  }
  fore(i, 0, n) {
    fore(j, 0, m) cout << ans[i][j];
    cout << "\n";
  }
  return 0;
}
