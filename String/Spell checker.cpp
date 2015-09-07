#include<iostream>
#include<string.h>
using namespace std;

char word[51][16];
char dict[10001][16];

int dict_size = 0,word_num = 0;

void input(){
	while(cin >> dict[dict_size]){
		if(dict[dict_size][0] != '#'){
			dict_size++;
		}
		else break;
	}
	while(cin >> word[word_num]){
		if(word[word_num][0] != '#'){
			word_num++;
		}
		else break;
	}
	dict_size--;
	word_num--;
}

bool del(char *a,char *b){
	int wrong = 0;
	while(*a){
		if(*a != *b){
			wrong++;
			a++;
			if(wrong > 1){
				return false;
			}
		}
		else{
			a++;
			b++;
		}
	}
	return true;
}

bool change(char *a,char*b){
	int wrong = 0;
	while(*a){
		if(*a != *b){
			wrong++;
			a++;
			b++;
			if(wrong > 1){
				return false;
			}
		}
		else{
			a++;
			b++;
		}
	}
	return true;
}

bool add(char *a,char *b){
	int wrong = 0;
	while(*a){
		if(*a != *b){
			wrong++;
			b++;
			if(wrong > 1){
				return false;
			}
		}
		else{
			a++;
			b++;
		}
	}
	return true;
}

int main()
{
	input();	//input
	int *word_len = new int[dict_size + 1];
	for(int i = 0;i <= dict_size;i++){
		word_len[i] = strlen(dict[i]);
	}
	for(int i = 0;i <= word_num;i++){
		int *may_index = new int[dict_size + 1];
		int temp_len = strlen(word[i]);
		bool flag = false;
		int index = 0;
		/*	process start	*/ 
		for(int j = 0;j <= dict_size;j++){
			if(word_len[j] == temp_len){
				if(strcmp(word[i],dict[j]) == 0){//str equal
					flag = true;
					break;
				}
				else if(change(word[i],dict[j]) == true){//str change 
					may_index[index] = j;
					index++;
				}
			}
			else if(word_len[j] - temp_len == 1){//str add
				if(add(word[i],dict[j]) == true){
					may_index[index] = j;
					index++;
				}
			}
			else if(temp_len - word_len[j] == 1){//str delete
				if(del(word[i],dict[j]) == true){
					may_index[index] = j;
					index++;
				}
			}
		}
		/*	process end	*/

		/*	now output	*/
		if(flag == true){
			cout << word[i] << " is correct" << endl;
		}
		else
		{
			cout << word[i] << ": ";
			for(int k = 0;k < index;k++){
				cout << dict[may_index[k]] << " ";
			}
			cout << endl;
		}
		delete may_index;
	}
	delete word_len;
	return 0;



}