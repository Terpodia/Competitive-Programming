#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
/* ================================================= */
void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int aux;
void _scan(int &x) { aux=scanf("%d",&x); }
void _scan(long long &x) { aux=scanf("%lld",&x); }
void _scan(double &x) { aux=scanf("%lf",&x); }
void _scan(char &x) { aux=scanf(" %c",&x); }
void _scan( char *x) { aux=scanf("%s",x); }
template<typename T>
void _scan(vector<T> &v){
	for(int i=0; i<(int)v.size(); i++) _scan(v[i]);
}
void scan() {}
template<typename T, typename... U>
void scan( T& head, U&... tail ) { _scan(head); scan(tail...);}
/* ================================================= */

#define sz(x) (int)x.size()

int main() {
  fastIO();
  int t; cin >> t;

  while (t--) {
    string p, h; cin >> p >> h; 
    int cnt[26]; memset(cnt, 0, sizeof(cnt));
    int check[26]; memset(check, 0, sizeof(check));

    int n = (int)h.size(), k = (int)p.size();

    for (int i=0; i<k;i++) {
      check[p[i]-'a']++;
    }

    for (int i=0; i<k && i<n; i++) {
      cnt[h[i]-'a']++;
    }

    bool can = true;

    for (int j=0; j<26; j++) can &= (cnt[j] == check[j]);

    for (int i=k; i<n; i++) {
      bool flag=true; 

      cnt[h[i-k] - 'a']--;
      cnt[h[i] - 'a']++;
      for (int j=0; j<26; j++) flag &= (cnt[j] == check[j]);

      can |= flag;
    }

    (can) ? puts("YES") : puts("NO");
  }

  return 0;
}

// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
