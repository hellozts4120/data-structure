#include<iostream>
#include<sstream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

string neg = "negative";
string str[31] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve",
				"thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty",
				"thirty","forty","fifty","sixty","seventy","eighty","ninety","hundred","thousand","million"};
int isNeg = 1;
int sum = 0;

int Location(string strIn){
	for(int i = 0;i < 31;i++){
		if((str[i] == strIn) && (i >= 0 && i <= 20)){
			return i;
		}
		else if((str[i] == strIn) && (i > 20 && i <= 27)){
			return (i - 18) * 10;
		}
		else if((str[i] == strIn) && (i == 28)){
			return 100;
		}
		else if((str[i] == strIn) && (i == 29)){
			return 1000;
		}
		else if((str[i] == strIn) && (i == 30)){
			return 1000000;
		}
	}
}

int main()
{
	string s;
	while(getline(cin,s)&&(s != "")){
		istringstream stream(s);	//绑定一行字符串，然后以空格为分隔符把该行分隔开来,调用头文件<sstream>
		string strIn[100];
		int len = 0;
		while(stream >> strIn[len]){//将字符串stream输入与字符串数组strIn，并记录其中元素个数
			len++;
		}
		int cnt = 0,tmp = 0;	//防止出现“fifteen million”
		for(int i = 0;i <= len;i++){
			if(i == len){
				cnt += tmp;
				break;
			}
			if(strIn[i] == neg){
				printf("-");
				continue;
			}
			int tag = Location(strIn[i]);
			if (tag == 100){
				tmp *= tag;
			}
			else if(tag > 100){
				tmp *= tag;
				cnt += tmp;
				tmp = 0;
			}
			else tmp += tag;
		}
		cout << cnt <<endl;
	}
	return 0;
}
