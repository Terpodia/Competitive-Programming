#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<long long int> vi;
 
bool P(ll max_value, ll k, vi &books) {
 
  ll sum = 0;
  k--;
 
  for (int i = 0; i < books.size(); ++i) {
 
    if(sum + books[i] <= max_value && books.size() - (i + 1) >= k) sum += books[i];
    
    else{
 
      sum = books[i];
      k--;
    }
  }
 
  return (k == 0);
}
 
ll bs(vi &books, ll k, ll maximo) {
 
  ll a = *max_element(books.begin(), books.end()) - 1, 
  b = maximo, mid;
 
  while (b - a > 1) {
 
    mid = (a + b) / 2;
    
    if(P(mid, k, books)) b = mid;
    else a = mid;
  }
 
  return b;
}
 
void print(vi &books, ll &max_val, ll k){
 
  vector<vi> ans(k);
  ll sum = 0;
  k--;
 
  for(int i = books.size() - 1, j = 1; i >= 0; i--, j++){
 
    if(sum + books[i] <= max_val && books.size() - j >= k){
 
      ans[k].insert(ans[k].begin(), books[i]);
      sum += books[i];
    }
 
    else{
 
      sum = books[i];
      k--;
      ans[k].insert(ans[k].begin(), books[i]);
    }
  }
 
  for(int i = 0; i < ans.size(); ++i){
 
    for(int j = 0; j < ans[i].size(); ++j){
 
      cout << ans[i][j] << " ";
    }
 
    if(i < ans.size() - 1) cout << "/ ";
  }
 
  cout << "\n";
}
 
int main() {
 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  ll N, m, k, suma = 1, max_val;
 
  cin >> N;
 
  for (int i = 0; i < N; ++i) {
 
    max_val = 0;
    cin >> m >> k;
    vi books(m);
 
    for (int j = 0; j < m; ++j){
      
      cin >> books[j];
      suma += books[j];
    } 
 
    max_val = bs(books, k, suma);
    print(books, max_val, k);
    suma = 1;
  }
 
  return 0;
} 

