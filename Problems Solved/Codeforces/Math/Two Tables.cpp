#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

struct rect {
    int x1, y1, x2, y2;
};

const int INF = 1e9;

int W, H, w, h; rect c;

bool check(rect a, rect b) {
    return !(b.x1 < a.x2 && b.x2 > a.x1 && b.y1 < a.y2 && b.y2 > a.y1);
}

int calc(rect a, int i) {
    if(check(c, a)) return 0;
    
    int dx, dy;

    if(i == 0) {
        dx = abs(c.x1 - a.x2); dy = abs(c.y1 - a.y2);
        if(c.x2 + dx > W) dx = INF;
        if(c.y2 + dy > H) dy = INF;
    }

    else if(i == 1) {
        dx = abs(c.x1 - a.x2); dy = abs(c.y2 - a.y1);
        if(c.x2 + dx > W) dx = INF;
        if(c.y1 - dy < 0) dy = INF;
    }

    else if(i == 2) {
        dx = abs(c.x2 - a.x1); dy = abs(c.y1 - a.y2);
        if(c.x1 - dx < 0) dx = INF;
        if(c.y2 + dy > H) dy = INF;
    }
    
    else {
        dx = abs(c.x2 - a.x1); dy = abs(c.y2 - a.y1);
        if(c.x1 - dx < 0) dx = INF;
        if(c.y1 - dy < 0) dy = INF;
    }

    //if(i == 0) return min(abs(c.x1 - a.x2), abs(c.y1 - a.y2));
    //if(i == 1) return min(abs(c.x1 - a.x2), abs(c.y2 - a.y1)); 
    //if(i == 2) return min(abs(c.x2 - a.x1), abs(c.y1 - a.y2));
    //return min(abs(c.x2 - a.x1), abs(c.y2 - a.y1));
    
    return min(dx, dy);
}

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&W,&H); 
        scanf("%d%d%d%d",&c.x1,&c.y1,&c.x2,&c.y2);
        scanf("%d%d",&w,&h);

        if(abs(c.x2 - c.x1) + w > W && abs(c.y2 - c.y1) + h > H) { puts("-1"); continue; }

        int ans = INF;

        rect corners[4];
        corners[0] = { 0, 0, w, h };
        corners[1] = { 0, H-h, w, H };
        corners[2] = { W-w, 0, W, h };
        corners[3] = { W-w, H-h, W, H }; 

        for(int i=0; i<4; i++) {
            ans = min(ans, calc(corners[i], i));
        }

        printf("%d\n", ans);
    }

    return 0;
}

