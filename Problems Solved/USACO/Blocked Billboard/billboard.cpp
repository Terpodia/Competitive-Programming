#include <algorithm>
#include <fstream>
using namespace std;

struct rectangle {
  int x1, y1, x2, y2;
};

int main() {
  ifstream fin;
  ofstream fout;
  fin.open("billboard.in");
  fout.open("billboard.out");

  rectangle r1, r2, r3;

  fin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
  fin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;
  fin >> r3.x1 >> r3.y1 >> r3.x2 >> r3.y2;

  int a1 = (r1.y2 - r1.y1) * (r1.x2 - r1.x1),
      a2 = (r2.y2 - r2.y1) * (r2.x2 - r2.x1);

  a1 -= max(0, max(min(r1.x2, r3.x2) - max(r1.x1, r3.x1), 0) *
                   max(min(r1.y2, r3.y2) - max(r1.y1, r3.y1), 0));
  a2 -= max(0, max(min(r2.x2, r3.x2) - max(r2.x1, r3.x1), 0) *
                   max(min(r2.y2, r3.y2) - max(r2.y1, r3.y1), 0));

  fout << a1 + a2 << "\n";

  return 0;
}
