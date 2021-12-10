#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int INF = 1e9;

int aux;

int main() {
  int t; aux=scanf("%d",&t);
  while (t--) {
    int n; aux=scanf("%d",&n);
    vector<int> a(n);
    for (int i=0; i<n; i++) 
      aux=scanf("%d",&a[i]);

    int ans=INF;

    map<int,vector<int>> mp;
    for(int i=0; i<n; i++) mp[a[i]].push_back(i);

    map<int,int> mp2;
    for (int i=0; i<n; i++) mp2[a[i]] = 1;

    for (int i=0; i<n-1; i++) {
      if(mp2[a[i]] >= (int)mp[a[i]].size()) continue; 
      else {
        ans = min(ans, mp[a[i]][mp2[a[i]]] - i + 1);
        mp2[a[i]]++;
      }
    }

    printf("%d\n", (ans == INF)? -1 : ans);
  }

  return 0;
}

