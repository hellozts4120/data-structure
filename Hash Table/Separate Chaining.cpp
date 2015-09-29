#include<vector>
#include<list>
#include<string>
using namespace std;

template <typename HashedObj>
class HashTable{
	private:
		vector<list<HashedObj> >theLists;	//The array of lists
		int currentSize;
		void rehash();
		int myhash(const HashedObj &x) const{
			int hashVal = hash(x);
			hashVal %= theLists.size();
			if(hashVal < 0){
				hashVal += theLists.size();
			}
			return hashVal;
		}

	public:
		explicit HashTable(int size = 101);

		bool contains(const HashedObj &x) const{
			const list<HashedObj>&whichList = theLists[myhash(x)];
			return find(whichList.begin(),whichList.end(),x) != whichList.end();
		}

		void makeEmpty(){
			for(int i = 0;i < theLists.size();i++){
				theLists[i].clear();
			}
		}

		bool insert(const HashedObj &x){
			list<HashedObj>&whichList = theLists[myhash(x)];
			if(find(whichList.begin(),whichList.end(),x) != whichList.end()){
				return false;
			}
			whichList.push_back(x);
			if(++currentSize > theLists.size()){
				rehash();
			}
			return true;
		}

		bool remove(const HashedObj &x){
			list<HashedObj>&whichList = theLists[myhash(x)];
			list<HashedObj>::iterator itr = find(whichList.begin(),whichList.end(),x);
			if(itr == whichList.end()){
				return false;
			}
			whichList.erase(itr);
			--currentSize;
			return true;
		}

};

int hash(const string &key){
	int hashVal = 0;
	for(int i = 0;i < key.length();i++){
		hashVal = 37 * hashVal + key[i];
	}
	hashVal %= tableSize;
	if(hashVal < 0){
		hashVal += tableSize;
	}
	return hashVal;
}
int hash(int key);