#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void _scan(int &x) { scanf("%d", &x); }
void _scan(long long &x) { scanf("%lld", &x); }
void _scan(double &x) { scanf("%lf", &x); }
void _scan(long double &x) { scanf("%Lf", &x); }
void _scan(char &x) { scanf(" %c", &x); }
void _scan(char *x) { scanf("%s", x); }
template <typename T>
void _scan(vector<T> &v) {
  for (int i = 0; i < (int)v.size(); i++) _scan(v[i]);
}
void scan() {}
template <typename T, typename... U>
void scan(T &head, U &... tail) {
  _scan(head);
  scan(tail...);
}
void set_IO() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(15);
}

void _dbg(istream_iterator<string> it) {}
template <typename T, typename... U>
void _dbg(istream_iterator<string> it, T &head, U &... tail) {
  cout << *it << "=" << head << " ";
  _dbg(++it, tail...);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define line cout << "\n-----------------------------\n";
#define dbg(args...)                         \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    _dbg(_it, args);                         \
  }

typedef __uint128_t u128;
typedef long long ll;

int MAX_SZ = 1e6;

int main() {
  int s[MAX_SZ];
  memset(s,0,sizeof(s));
  s[1] = 1;
  for(int i=2; i<MAX_SZ; i+=2) s[i] = 2;
  for(int i=3; i<MAX_SZ; i+=2){
    if(s[i] == 0){
      s[i] = i;
      for(ll j = (ll)i * (ll)i; j < (ll)MAX_SZ; j+=(ll)i){
        s[j] = i;
      }
    }
  }

  int tt;
  scan(tt);
  while(tt--){
    int a,b,c,d;
    scan(a,b,c,d);
    int x=-1, y=-1;

    map<int,int> f;
    int ax = a, bx = b;

    while(ax > 1){
      int p = s[ax];
      while(ax % p == 0) f[p]++, ax /= p;
    }
    while(bx > 1){
      int p = s[bx];
      while(bx % p == 0) f[p]++, bx /= p;
    }
    
    rep(i,a+1, c+1){
      map<int,int> fx;
      int ix = i;
      while(ix > 1){
        int p = s[ix];
        while(ix % p == 0) fx[p]++, ix /= p;
      }

      bool overflow = false;
      ll yx = 1;

      for(auto& [p, cnt] : f){
        if(overflow) break;

        auto it = fx.find(p);
        int cnt2 = (it == fx.end()) ? 0 : it->snd;

        if(cnt2 < cnt){
          rep(_,0,cnt-cnt2){
            if(overflow) break;
            yx *= (ll)p;
            if(yx > d) overflow = true;
          } 
        }
      }

      if(!overflow){
        if(yx <= b){
          ll z = b/yx;
          while(yx * z <= b) z++;
          yx *= z;
        }
        if(yx <= d) x = i, y = (int)yx;
      }
    }

    printf("%d %d\n", x, y);
  }
  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
