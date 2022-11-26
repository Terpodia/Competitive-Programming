#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 500, INF = 5000;
int N;
ll a[MAXN][MAXN];

void fastIO() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
}

ll f(vector<ll> &x) {
  ll res = 0;
  int index = 0;
  vector<vector<ll>> p(MAXN + 7);

  for (int i = 0; i < (int)x.size(); i++) {
    if (x[i] < 0) {
      if (i > 0 && x[i - 1] >= 0) index++;
    } else {
      p[index].push_back(x[i]);
    }
  }

  for (int j = 0; j < (int)p.size(); j++) {
    if (p[j].empty()) break;
    int r = 0;
    for (int i = 0; i < (int)p[j].size(); i++) {
      if (p[j][i] > 0) {
        ll right = (i - 1) - r, left = (p[j].size() - 1) - (i + 1);
        right++;
        left++;
        res += right + left + (right * left) + 1;
        r = i + 1;
      }
    }
  }
  return res;
}

ll calc(int row) {
  ll res = 0;
  vector<ll> x(N, 0);

  for (int i = row; i < N; i++) {
    for (int j = 0; j < N; j++) {
      x[j] += a[i][j];
    }
    res += f(x);
  }
  return res;
}

void solve() {
  ll ans = 0;

  for (int i = 0; i < N; i++) {
    ans += calc(i);
  }
  cout << ans << "\n";
}

int main() {
  fastIO();

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ll b;
      cin >> b;
      if (b == 100)
        a[i][j] = 1;
      else
        a[i][j] = (b > 100) ? 0 : -INF;
    }
  }

  solve();

  return 0;
}
