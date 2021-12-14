#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int aux;

const int MAXA = 2e5+7;

int cnt[MAXA];

bool cmp(int a, int b) {
  if(cnt[a] != cnt[b]) return cnt[a] < cnt[b];
  return a < b;
}

int main() {
  int TC; aux=scanf("%d",&TC);
  while (TC--) {
    int n, k; aux=scanf("%d%d",&n,&k);
    int a[n];
    for (int i=0; i<n; i++)
      aux=scanf("%d",a+i);

    sort(a, a+n);

    int ans=0;
    for (int i=0; i<n-2*k; i++) ans += a[i];

    vector<int> vec;
    
    for (int i=n-2*k; i<n; i++) {
      cnt[a[i]]++;
      vec.push_back(a[i]);
    } 

    sort(vec.begin(), vec.end());

    vec.resize(distance(vec.begin(), unique(vec.begin(), vec.end())));

    sort(vec.begin(), vec.end(), cmp);

    for (int i = (int)vec.size() - 1; i > -1; i--) {
      int j=i-1;
      while (cnt[vec[i]] > 0) {
        if (j == -1) ans += cnt[vec[i]] / 2, cnt[vec[i]] = 0; 
        else {
          cnt[vec[i]] -= min(cnt[vec[i]], cnt[vec[j]]);
          cnt[vec[j]] -= min(cnt[vec[i]], cnt[vec[j]]);
          if (cnt[vec[j]] == 0) j--;
        }
      } 
    }

    printf("%d\n", ans);

    memset(cnt, 0, sizeof(cnt)); 
  } 

  return 0;
}

