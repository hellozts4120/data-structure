#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
using namespace std;

vector<int>num;

int main(){
	int n,k,temp;
	int n1,n2;
	cin >> n >> k;
	k--;
	n1 = n2 = n;
	for(int i = 0; i <= n / 100000; i++){
		n2 = n1 > 100000 ? 100000 : n1;
		for(int j = 0; j < n2; j++){
			cin >> temp;
			num.push_back(temp);
		}
		sort(num.begin(),num.end());
		num.erase(num.begin() + k + 1,num.end());
		n1 -= n2;
		if(n1 <= 0){
			cout << num[k] << endl;
			break;
		}
	}
	return 0;
}