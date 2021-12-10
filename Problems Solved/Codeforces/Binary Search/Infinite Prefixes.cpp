#include <iostream>
using namespace std;

typedef long long ll;

const ll INF = 1e9;

int n; ll x, cntb;
string s;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int f(ll acc) {
  ll l=0, r=INF; 

  while (r > l) {
    ll mid = l + (r-l)/2;
    if (acc + (cntb * mid) >= x) r = mid;
    else l = mid+1;
  }

  return (acc + (cntb * r) == x) ? 1 : 0;
}

int g(ll acc) {
  ll l=0, r=INF;
  
  while (r > l) {
    ll mid = l + (r-l)/2;
    if (acc + cntb * mid <= x) r = mid;
    else l = mid+1;
  }

  return (acc + cntb * r == x) ? 1 : 0;
}

int main() {
  fastIO();
  int t; cin >> t;
  while (t--)  {
    cin >> n >> x >> s;
    cntb=0;

    for (char c : s)
      cntb += (c == '0') ? 1 : -1;

    if (cntb == 0) {
      bool inf=false;
      int acc=0;
      for (char c : s) {
        acc += (c == '0') ? 1 : -1;
        inf |= (x == acc);
      }

      (inf) ? cout << "-1\n" : cout << "0\n";
    }

    else {
      int ans=0; ll acc=0;
      for (char c : s) {
        acc += (c == '0') ? 1 : -1;
        ans += (cntb > 0) ? f(acc) : g(acc);
      }

      if (x == 0) ans++;
      
      cout << ans << "\n";
    }
  }

  return 0;
}

