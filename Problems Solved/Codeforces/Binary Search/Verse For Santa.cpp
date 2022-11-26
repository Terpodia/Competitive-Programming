#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
/* ================================================= */
void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int aux;
void _scan(int &x) { aux = scanf("%d", &x); }
void _scan(long long &x) { aux = scanf("%lld", &x); }
void _scan(double &x) { aux = scanf("%lf", &x); }
void _scan(char &x) { aux = scanf(" %c", &x); }
void _scan(char *x) { aux = scanf("%s", x); }
template <typename T>
void _scan(vector<T> &v) {
  for (int i = 0; i < (int)v.size(); i++) _scan(v[i]);
}
void scan() {}
template <typename T, typename... U>
void scan(T &head, U &...tail) {
  _scan(head);
  scan(tail...);
}
/* ================================================= */

#define sz(x) (int)x.size()

int bs(int i, vector<long long> &pref, int s) {
  int l = i, r = sz(pref) - 2;

  while (r > l) {
    int mid = l + (r - l + 1) / 2;
    if (pref[i] + pref[mid + 1] - pref[i + 1] <= (long long)s)
      l = mid;
    else
      r = mid - 1;
  }

  return l;
}

int main() {
  int tc;
  scan(tc);

  while (tc--) {
    int n, s;
    scan(n, s);
    vector<int> a(n);
    scan(a);

    bool can = false;
    int ans = -1;

    int cnt = 0, pos = -1, acc = 0;

    for (int i = 0; i < n; i++) {
      if (cnt + a[i] > s) {
        pos = i;
        break;
      }
      cnt += a[i];
      acc++;
    }

    if (pos != -1) {
      ans = n - 1;
      vector<long long> pref(n + 1, 0);
      for (int i = 1; i <= n; i++) pref[i] += pref[i - 1] + a[i - 1];

      for (int i = 0; i <= pos; i++) {
        int val = bs(i, pref, s) - i + i;
        if (val >= acc) can = true, ans = i, acc = val;
      }
    }

    (!can) ? puts("0") : printf("%d\n", ans + 1);
  }

  return 0;
}

// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
