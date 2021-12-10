#include <iostream>
#include <iomanip>
using namespace std;
using ld = long double;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
    fastIO();

    ld sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    cout << fixed << setprecision(12); 

    /*
     * y = mx + b
     * 0 = mx + b
     * x = -b / m
     *
     * b = y - mx
     * m = (y1-y2) / (x1-x2)
    */

    gy *= -1;

    ld m = (sy - gy) / (sx - gx);
    ld b = sy - m * sx;

    cout << -b / m << "\n";

    return 0;
}

