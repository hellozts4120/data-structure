#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>num;

bool cmp(int a,int b){
    return a > b;
}

int main(){
	int n,t,temp;
	cin >> n >> t;
	for(int i = 0; i < n; i++){
		cin >> temp;
		num.push_back(temp);
	}
	if(t > 0){
		sort(num.begin(),num.end());
		vector<int>::iterator end_unique = unique(num.begin(), num.end()); 
		num.erase(end_unique,num.end());
	}
	else if(t < 0){
		sort(num.begin(),num.end(),cmp);
		vector<int>::iterator end_unique = unique(num.begin(), num.end()); 
		num.erase(end_unique,num.end());
	}
	else{
		sort(num.begin(),num.end());
	}
	int ans = 0;
	for(vector<int>::iterator i = num.begin(); i != num.end(); i++){
		for(vector<int>::iterator j = i+1; j != num.end(); j++){
			if(*j - *i == t){
				ans++;
			}
			else{
				if(t > 0 && *j - *i > t){
					break;
				}
				if(t < 0 && *j - *i < t){
					break;
				}
				if(t == 0){
					break;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}

