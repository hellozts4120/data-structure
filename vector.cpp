#include<cstdio>
#include<iostream>
using namespace std;

template <typename Object>
class Vector{
private:
	int theSize;
	int theCapacity;
	Object *objects;
public:
	explicit Vector(int initSize = 0):theSize(initSize),theCapacity(initSize + SPARE_CAPACITY){
		objects = new Object[theCapacity];
	}

	Vector(const Vector & rhs):objects(NULL){
		operator=(rhs);
	}

	~Vector(){
		delete []objects;
	};

	const Vector & Operator=(const Vector & rhs){
		if(this == &rhs){return *this;}
		else{
			delete []objects;
			theSize = rhs.size();
			theCapacity = rhs.theCapacity;

			objects = new object[theCapaciy];
			for(int i = 0;i < theSize;k++){
				objects[i] = rhs.objects[i];
			}
		}
		return *this;
	}
	
	void resize(int newSize){
		if(newSize > theCapacity){
			reserve(newSize * 2 + 1);
		}
		theSize = newSize;
	}

	void reserve(int newCapacity){
		if(newCapacity < theSize){
			return;
		}
		Object *oldArray = objects;
		objects = new Object[newCapacity];
		for(int i = 0;i < theSize;i++){
			objects[i] = oldArray[i];
		}
		theCapacity = newCapacity;
		delete []oldArray;
	}

	Object & operator[](int index){
		return objects[index];}

	const Object & operator[](int index) const{
		return objects[index];}

	bool empty(){
		return size() == 0;
	}
	
	int size(){
		return theSize;
	}

	int capacity(){
		return theCapacity;
	}

	void push_back(const Object & x){
		if(theSize == theCapacity){
			reserve(2 * theCapacity + 1);
		}
		objects[theSize++] = x;
	}

	void pop_back(){
		theSize--;
	}

	const Object & back() const{
		return objects[theSize - 1];
	}

	typedef Object * iterator;
	typedef const Object * const_iterator;

	iterator begin(){
		return &objects[0];
	}
	const_iterator begin() const{
		return &objects[0];
	}

	iterator end(){
		return &objects[size()];
	}

	const_iterator  end(){
		return &objects[size()];
	}

	enum{
		SPACE_CAPACITY = 16;
	}

};