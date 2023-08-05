#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

const int INF = 1e9;

typedef long long ll;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++)
      if (a[i] < i + 1) p.push_back(make_pair(a[i], i + 1));
    sort(all(p));
    ll ans = 0;
    for (int i = 0; i < sz(p); i++) {
      int j = (int)distance(p.begin(),
                            upper_bound(all(p), make_pair(p[i].snd, INF)));
      // printf("%d %d %d\n",p[i].fst,p[i].snd,j);
      ans += (ll)(sz(p) - j);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
