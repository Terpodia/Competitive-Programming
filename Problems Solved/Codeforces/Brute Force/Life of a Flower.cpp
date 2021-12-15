#include <cstdio>
int aux;

int main() {
  int TC; aux=scanf("%d",&TC);
  while (TC--) {
    int n; aux=scanf("%d",&n);
    int a[n];
    for (int i=0; i<n; i++)
      aux=scanf("%d",a+i);
    
    int ans = 1, cnt1 = 0, cnt2 = 0;

    for (int i=0; i<n; i++) {
      if (cnt2 >= 2) { ans = -1; break; }

      if (a[i] != 1) cnt2++, cnt1 = 0;
      else {
        if (cnt1 > 0) ans += 5;
        else ans++;
        
        cnt1++;
        cnt2 = 0;
      }

      if (cnt2 >= 2) { ans = -1; break; }
    }

    printf("%d\n", ans);
  }

  return 0;
}

