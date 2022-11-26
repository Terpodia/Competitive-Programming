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

int main() {
  fastIO();
  int tc;
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++) cin >> p[i];
    string s;
    cin >> s;

    vector<pair<int, int>> a, b;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1')
        a.push_back({p[i], i});
      else
        b.push_back({p[i], i});
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int curr = 1;

    for (int i = 0; i < sz(b); i++) {
      p[b[i].second] = curr++;
    }

    for (int i = 0; i < sz(a); i++) {
      p[a[i].second] = curr++;
    }

    for (int i = 0; i < n; i++) cout << p[i] << " ";
    cout << "\n";
  }

  return 0;
}

// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
