#include<iostream>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;

set<int>text[100];

int main(){
	freopen("in (1).txt","r",stdin);
	freopen("outt.txt","w",stdout);
	int n,m;
	cin >> n;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		for(int j = 0; j < num; j++){
			int value;
			cin >> value;
			text[i].insert(value);
		}
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		set<int>ans,del;
		int flag = 1;
		for(int j = 0; j < n; j++){
			int cases;
			cin >> cases;
			if(cases == 1 && flag){
				flag = 0;
				set<int>::iterator itr1 = text[j].begin();
				while(itr1 != text[j].end()){
					ans.insert(*itr1);
					itr1++;
				}
			}
			else if(cases == 1 && !flag){
				set<int>::iterator itr1 = ans.begin();
				while(itr1 != ans.end()){
					if(text[j].find(*itr1) == text[j].end()){
						ans.erase(itr1++);
					}
					else{
						itr1++;
					}
				}
			}
			else if(cases == -1){
				set<int>::iterator itr1 = text[j].begin();
				while(itr1 != text[j].end()){
					del.insert(*itr1);
					itr1++;
				}
			}
		}
		set<int>::iterator itr1 = del.begin();
		while(itr1 != del.end()){
			if(ans.find(*itr1) != ans.end()){
				ans.erase(*itr1);
				itr1++;
			}
			else{
				itr1++;
			}
		}
		if(ans.empty()){
			cout << "NOT FOUND" << endl;
		}
		else{
			set<int>::iterator itr1 = ans.begin();
			while(itr1 != ans.end()){
				cout << *itr1 << " ";
				itr1++;
			}
			cout << endl;
		}
	}
	return 0;
}