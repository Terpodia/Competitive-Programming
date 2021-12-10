#include <iostream>
#include <cstring>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    int n; char c; cin >> n >> c;
    string s; cin >> s;
    bool can=true;
    for (char x : s) can &= (x == c);

    if (can) cout << "0\n";
    else {
      bool a[n+1]; memset(a, false, sizeof(a));
      a[0]=true;
      for (int i=0; i<n; i++) {
        if (s[i] != c) a[i+1] = true; 
      }

      int ans=2, p1=n, p2=n-1;

      for (int i=1; i<=n; i++) {
        can=true;
        for (int j=i; j<=n; j+=i)
          if (a[j]) can=false;

        if (can) ans = 1, p1 = i;
      }
      
      if (ans == 1) cout << ans << "\n" << p1 << "\n";

      else cout << ans << "\n" << p1 << " " << p2 << "\n";
    }
  }

  return 0;
}

