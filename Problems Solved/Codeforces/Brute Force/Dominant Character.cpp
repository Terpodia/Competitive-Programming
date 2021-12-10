#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

bool can(int k, string& s, int n) {
  int cnta, cntb, cntc;
  cnta = cntb = cntc = 0;

  for (int i=0; i<k; i++) {
    if (s[i] == 'a') cnta++;
    else if (s[i] == 'b') cntb++;
    else cntc++;
  }

  int l=0;

  if (cnta > cntb && cnta > cntc) return true;

  for (int i=k; i<n; i++) {
    if (s[l] == 'a') cnta--; 
    else if (s[l] == 'b') cntb--;
    else cntc--;

    if (s[i] == 'a') cnta++;
    else if (s[i] == 'b') cntb++;
    else cntc++;

    if (cnta > cntb && cnta > cntc) return true;

    l++;
  }

  return false;
}

int main() {
  fastIO();
  int t; cin >> t;

  while (t--) {
    int n; string s; 
    cin >> n;
    cin >> s;

    int ans=-1;

    for (int i=2; i<=7 && i <= n; i++) {
      if (can(i, s, n)) { ans = i; break; }
    }
    
    cout << ans << "\n";
  }

  return 0;
}

