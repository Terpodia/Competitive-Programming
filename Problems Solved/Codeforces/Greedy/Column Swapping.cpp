#include <bits/stdc++.h>
using namespace std;

int main(){
	int tt;
	scanf("%d",&tt);
	while(tt--){
		int n,m;
		scanf("%d%d",&n,&m);
		int a[n][m], b[n][m];
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++){
				scanf("%d",&a[i][j]);
				b[i][j] = a[i][j];
			}
		for(int i=0; i<n; i++) sort(b[i], b[i]+m);
		
		int val = -1, x=-1, y=-1, row=-1;
				
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++) if(a[i][j] != b[i][j]){
				val = a[i][j], row = i, x = j;
			}
		
		if(row == -1){
			puts("1 1");
			continue;
		}
		for(int j=0; j<m; j++){
			if(val == b[row][j] && val != a[row][j]){
				y = j; 
				break;
			}
		}
		
		for(int i=0; i<n; i++) swap(a[i][x], a[i][y]);
		
		bool can = true;
		for(int i=0; i<n; i++)
			for(int j=0; j<m-1; j++)
				can &= (a[i][j] <= a[i][j+1]);
		
		if(can) printf("%d %d\n", x+1, y+1);
		else puts("-1");
	}
	return 0;
}
