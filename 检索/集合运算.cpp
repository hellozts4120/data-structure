#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int m,n;
	int temp;
	cin >> n;
	vector<int>a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cin >> m;
	int cur = 0;
	 for(int i = 0; i < m; i++){
		 cin >> temp;
		 while(cur < n && temp > a[cur]){
			 cout << a[cur++] << " ";
		 }
		 if(a[cur] == temp){
			 cur++;
		 }
		 else{
			 cout << temp << " ";
		 }
	 }
	 for(; cur < n; cur++){
		 cout << a[cur] << " ";
	 }
	 cout << endl;
	 return 0;
}