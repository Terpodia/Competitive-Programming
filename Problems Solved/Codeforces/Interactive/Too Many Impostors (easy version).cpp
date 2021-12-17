#include <iostream>
#include <cstring>
using namespace std;

int n;

void query(int a, int b, int c) {
  a++, b++, c++;
  cout << "? " << a << " " << b << " " << c << endl;
  cout.flush();
}

void solve() {
  query(0, 1, 2);
  int prev; cin >> prev; prev = 1 - prev;
  int p[3]; p[0] = p[1] = p[2] = -1;
  int a=0, b=0;

  if (prev == 0) p[0] = 0, p[1] = 1, p[2] = 2;

  for (int i=1; i+2 < n; i++) {
    int ret;
    query(i, i+1, i+2);
    cin >> ret;

    ret = 1 - ret;

    if (ret == 0) p[0] = i, p[1] = i+1, p[2] = i+2;
    if (prev == 1 && ret == 0) a = i-1;
    else if (prev == 0 && ret == 1) a = i+2;;

    prev = ret;
  }

  int impostors[n]; 
  memset(impostors, -1, sizeof(impostors));

  impostors[a] = 1;

  int v1, v2;
  query(a, p[0], p[1]);
  cin >> v1; v1 = 1 - v1;
  query(a, p[1], p[2]);
  cin >> v2; v2 = 1 - v2;

  if (v1 == 0 && v2 == 0) impostors[p[0]] = 0, impostors[p[1]] = 0, impostors[p[2]] = 0, b = p[0];
  else if (v1 == 1 && v2 == 0) impostors[p[0]] = 1, impostors[p[1]] = 0, impostors[p[2]] = 0, b = p[1];
  else if (v1 == 0 && v2 == 1) impostors[p[0]] = 0, impostors[p[1]] = 0,  impostors[p[2]] = 1, b = p[0];
  else if (v1 == 1 && v2 == 1) impostors[p[0]] = 0, impostors[p[1]] = 1, impostors[p[2]] = 0, b = p[0];

  for (int i=0; i<n; i++) {
    if (impostors[i] == -1) {
      query(a, b, i);
      int ret; cin >> ret; ret = 1 - ret;
      if (ret == 0) impostors[i] = 0;
      else impostors[i] = 1;
    }
  }

  int k=0;
  for (int i=0; i<n; i++) if (impostors[i] == 1) k++;
  cout << "! " << k << " ";
  for (int i=0; i<n; i++) if (impostors[i] == 1) cout << i+1 << " ";
  cout << endl;
  cout.flush();
}

int main() {
  int TC; cin >> TC;

  while (TC--) {
    cin >> n; 
    solve();
  }

  return 0;
}

