#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

struct Point{
	int x,y,z;
};
Point AllPoint[10];

struct Way{
	Point PA,PB;
	double len;
};
Way AllWay[50];

int main(){
	int n;
	bool flag;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> AllPoint[i].x >> AllPoint[i].y >> AllPoint[i].z;
	}
	Way temp;
	int t = 0;
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			AllWay[t].PA = AllPoint[i];
			AllWay[t].PB = AllPoint[j];
			AllWay[t].len = sqrt( (AllWay[t].PA.x - AllWay[t].PB.x)*(AllWay[t].PA.x - AllWay[t].PB.x) +
						(AllWay[t].PA.y - AllWay[t].PB.y)*(AllWay[t].PA.y - AllWay[t].PB.y) +
						(AllWay[t].PA.z - AllWay[t].PB.z)*(AllWay[t].PA.z - AllWay[t].PB.z) );
			t++;
		}
	}
	//using poping sort...
	for(int i = 0; i < t; i++){
		flag = 1;
		for(int j = t - 1; j > i; j--){
			if(AllWay[j].len > AllWay[j - 1].len){
				flag = 0;
				temp = AllWay[j];
				AllWay[j] = AllWay[j - 1];
				AllWay[j - 1] = temp;
			}
		}
		if(flag){
			break;
		}
	}
	for(int i = 0; i < t; i++){
		cout<<'('<<AllWay[i].PA.x<<','<<AllWay[i].PA.y<<','<<AllWay[i].PA.z<<')';
        cout<<'-';
        cout<<'('<<AllWay[i].PB.x<<','<<AllWay[i].PB.y<<','<<AllWay[i].PB.z<<')';
        cout<<'=';
		cout<<fixed<<setprecision(2)<<AllWay[i].len << endl;
	}
	return 0;
}