#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ifstream fin;
  ofstream fout;
  fin.open("lostcow.in");
  fout.open("lostcow.out");

  int x, y, pos, val = 1;
  fin >> x >> y;
  pos = x;
  int ans = 0;

  int dir = 1;

  while (true) {
    int l, r;
    if (dir == 1) {
      l = x;
      r = x + val;
    } else {
      l = x - val;
      r = x;
    }

    if (y >= l && y <= r) {
      ans += abs(pos - y);
      break;
    }

    ans += abs(pos - (x + (val * dir)));
    pos = x + (val * dir);

    val *= 2;
    dir *= -1;
  }

  fout << ans << "\n";

  fin.close();
  fout.close();
  return 0;
}
