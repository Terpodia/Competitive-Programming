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
    string s;
    cin >> s;

    int k = 0;
    for (int i = 1; i < sz(s); i++) {
      if (s[i] <= s[i - 1] && s[i] != s[0])
        k = i;
      else
        break;
    }

    string ans;
    for (int i = 0; i <= k; i++) ans.push_back(s[i]);

    string ansp = ans;
    reverse(ansp.begin(), ansp.end());
    cout << ans + ansp << "\n";
  }

  return 0;
}

// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
