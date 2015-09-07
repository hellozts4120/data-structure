#include<iostream>
#include<string.h>
using namespace std;

char word[51][16];
char dict[10001][16];

int dict_size,word_num;

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
	if(*b == '\0'){
		return true;
	}
	else return false;
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
	if(*b == '\0'){
		return true;
	}
	else return false;
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
	if(*b == '\0'){
		return true;
	}
	else return false;
}

int main()
{
	input();
	/*	to be continue	*/

}