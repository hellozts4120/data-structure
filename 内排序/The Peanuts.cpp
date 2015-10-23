#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

struct Point{
	int x,y;
	int peanut;
}AllPoint[2550];

int cmp(const void *a , const void *b){
	return ((Point *)b)->peanut - ((Point *)a)->peanut;
}

int main(){
	int m,n,k,cases,temp,ans;
	cin >> cases;
	while(cases--){
		cin >> m >> n >> k;
		int cur = 0;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cin >> temp;
				if(temp){
					AllPoint[cur].x = i;
					AllPoint[cur].y = j;
					AllPoint[cur].peanut = temp;
					cur++;
				}
			}
		}
		qsort(AllPoint,cur,sizeof(AllPoint[0]),cmp);
		ans = 0;
		int xx = 0, yy = AllPoint[0].y;
		for(int i = 0; i < cur; i++){
			k -= abs(AllPoint[i].x - xx) + abs(AllPoint[i].y - yy) + 1;
			if(k <= 1 + abs(AllPoint[i].x)){
				break;
			}
			ans += AllPoint[i].peanut;
			xx = AllPoint[i].x;
			yy = AllPoint[i].y;
		}
		cout << ans << endl;
	}
	return 0;
}