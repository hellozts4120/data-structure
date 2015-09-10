/*		Fake Code		*/
#include<iostream>
using namespace std;

template <typename Comparable>
class BinarySearchTree
{
	public:
		BinarySearchTree(){}
		BinarySearchTree(const BinarySearchTree & rhs){
			this = rhs;
		}

		~BinarySearchTree(){
			makeEmpty();
		}
		//��ֵ������;
		const Comparable & findMin() const{
			findMin(x,root);
		}

		const Comparable & findMax() const{
			findMax(root);
		}

		bool contains(const Comparable & x) const{
			contains(root);
		}

		bool isEmpty const{
			if(root == NULL){
				return true;
			}
			return false;
		}

		void printTree const;	//omit, should add parameter;

		//��Ϊ������Ա��������ֹ�ı����;
		void makeEmpty{
			makeEmpty(root);
		}

		void insert(const Comparable & x){
			insert(x,root);
		}

		void remove(const Comparable & x){
			remove(x,root);
		}

		const BinarySearchTree & operator=(const BinarySearchTree & rhs){
			if(this != &rhs){
				makeEmpty();
				root = clone(rhs.root);
			}
			return *this;
		}


	private:
		struct BinaryNode	//����Ѱ�������;
		{
			Comparable element;
			BinaryNode *left;	//���㣻
			BinaryNode *right	//�ҽ��;

			BinaryNode(const Comparable & elem,BinaryNode *l,BinaryNode *r):element(elem),left(l),right(r){};
		};

		BinaryNode *root;	//��λ�����;

		void insert(const Comparable & x,BinaryNode * & t){
			if(t == NULL){
				t = new BinaryNode(x,NULL,NULL);
			}
			else if(x < t -> element){
				t = t -> left;
				insert(x,t);
			}
			else if(x > t -> element){
				t = t -> right;
				insert(x,t);
			}
			else {};
		}

		void remove(const Comparable & x,BinaryNode * & t){		//important!
			if(t == NULL){
				return;	//don't do anything;
			}
			if(x < t -> element){
				remove(x,t -> left);
			}
			else if(x > t -> element){
				remove(x,t -> right);
			}
			else if((t -> left != NULL) && (t -> right != NULL)){
				t -> element = findMin(t -> right) -> element;	//ͬʱ��������ʱ����������ѡȡ��С��Ԫ�ظ�ֵ�����;
				remove(t -> element,t -> right);
			}
			else{
				BinaryNode *tempNode = t;
				t = (t -> left != NULL) ? t -> left : t -> right;
				delete tempNode;
			}
		}

		BinaryNode * findMax(BinaryNode * t) const{		//���õݹ�д��
			if(t == NULL){
				return NULL;
			}
			if(t -> right == NULL){
				return t;
			}
			else return findMax(t -> right);
		}

		BinaryNode * findMin(BinaryNode * t) const{		//���÷ǵݹ�д��
			if(t == NULL){
				return NULL;
			}
			while(t -> left != NULL){
				t = t -> left;
			}
			return t;
		}

		bool contains(const Comparable & x,BinaryNode * t){
			if(t == NULL){
				return false;
			}
			else
				if(x < t -> element){
					return contains(x,t -> left);
				}
				else if(x > t -> element){
					return contains(x,t -> right);
				}
				else
					return true;
		}

		void makeEmpty(BinaryNode * & t){
			if(t == NULL){
				return;
			}
			else{
				makeEmpty(t -> left);
				makeEmpty(t -> right);
				delete t;
			}
			t = NULL	//avoid wild pointer;
		}

		void makeTree(BinaryNode * t) const;	//omit

		BinaryNode * clone(BinaryNode * t) const{
			if(t == NULL){
				return NULL;
			}
			return new BinaryNode(t -> element,clone(t -> left),clone(t -> right));
		}

};//struct of BST
