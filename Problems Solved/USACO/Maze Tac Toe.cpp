#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

#define FOR(i,x,n) for(int i=(x); i<(int)(n); i++)

struct cell{
  bool can;
  int i,j;
  char c;
};

const int dr[]={1,-1,0,0},dc[]={0,0,1,-1};
int N, power[10];
cell a[25][25];
bool vis[25][25][59055];

bool win(int msk){
  char game[3][3];
  FOR(i,0,9){ 
    if(msk%3==0) game[i/3][i%3]='-';
    else game[i/3][i%3]=(msk%3==1)?'O':'M';
    msk/=3;
  }
  FOR(i,0,3){
    string w;
    w.push_back(game[i][0]); w.push_back(game[i][1]); w.push_back(game[i][2]);
    if(w == "MOO" || w == "OOM") return true;
  }
  FOR(i,0,3){
    string w;
    w.push_back(game[0][i]); w.push_back(game[1][i]); w.push_back(game[2][i]);
    if(w == "MOO" || w == "OOM") return true;
  }
  string w;
  w.push_back(game[0][0]); w.push_back(game[1][1]); w.push_back(game[2][2]);
  if(w == "MOO" || w == "OOM") return true;
  w.clear();
  w.push_back(game[0][2]); w.push_back(game[1][1]); w.push_back(game[2][0]);
  if(w == "MOO" || w == "OOM") return true;
  return false;
}

bool valid(int& i, int& j){
  return (i>-1 && j>-1 && i<N && j<N && a[i][j].can);
}

void solve(int& sr, int& sc){
  queue<tuple<int,int,int>> q;
  q.push({sr,sc,0});
  vis[sr][sc][0]=true;
  unordered_set<int> wins;

  while (!q.empty()){
    auto&[ur,uc,msk]=q.front();
    q.pop();
    if(win(msk)){
      wins.insert(msk);
      continue;
    }
    FOR(i,0,4){
      int vr=ur+dr[i], vc=uc+dc[i];
      if(valid(vr,vc)){
        int j=a[vr][vc].i*3+a[vr][vc].j;
        int nmsk=msk;
        if(a[vr][vc].i!=-1 && (msk/power[j])%3==0){ 
          if(a[vr][vc].c=='O') nmsk+=power[j];
          else nmsk+=power[j]*2;
        }
        if(vis[vr][vc][nmsk]) continue;
        vis[vr][vc][nmsk]=true;
        q.push({vr,vc,nmsk});
      }
    }
  }
  cout << (int)wins.size() << "\n";
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  cin>>N;
  int sr=-1,sc=-1;
  FOR(i,0,N) FOR(j,0,N){
    char c[3]; cin>>c[0]>>c[1]>>c[2];
    if(c[0]=='.' && c[1]=='.' && c[2]=='.') a[i][j]={true,-1,-1,'-'};
    else if(c[0]=='#' && c[1]=='#' && c[2]=='#') a[i][j]={false,-1,-1,'-'};
    else if(c[0]=='B' && c[1]=='B' && c[2]=='B') a[i][j]={true,-1,-1,'-'}, sr=i, sc=j;
    else a[i][j]={true,c[1]-'0'-1,c[2]-'0'-1,c[0]};
  } 
  power[0]=1;
  FOR(i,1,10) power[i]=power[i-1]*3;
  solve(sr, sc);
  return 0;
}

