#include <iostream>
#include <bitset>
using namespace std;

#define FOR(i,x,n) for(int i=(x); i<(int)(n); i++)

int aux;
char a[8][8];
bitset<30> row, dl, dr;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int solve(int c) {
  if(c == 8) return 1;
  int ret=0; 

  FOR(r,0,8) if(a[r][c] != '*') {
    if(!row[r] && !dl[r-c+7] && !dr[r+c]) {
      row[r] = dl[r-c+7] = dr[r+c] = true;
      ret += solve(c+1);
      row[r] = dl[r-c+7] = dr[r+c] = false;
    }
  }
  
  return ret; 
}

int main() {
  fastIO();
  FOR(i,0,8) FOR(j,0,8) cin >> a[i][j];

  cout << solve(0) << "\n";

  return 0;
}

