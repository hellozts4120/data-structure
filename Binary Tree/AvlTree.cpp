/*		Fake Code		*/
#include<iostream>
#include<algorithm>
using namespace std;		//大部分BSF的code可直接使用，唯独增减元素需要进行改变，同时加入高度的属性
							//其中insert,delete函数是改动最大的，也是AvlTree的核心！
template <typename Comparable>
class AvlTree
{
	public:
		AvlTree(){}
		AvlTree(const AvlTree & rhs){
			this = rhs;
		}

		~AvlTree(){
			makeEmpty();
		}
		//赋值及析构;
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

		//均为常量成员函数，防止改变变量;
		void makeEmpty{
			makeEmpty(root);
		}

		void insert(const Comparable & x){
			insert(x,root);
		}

		void remove(const Comparable & x){
			remove(x,root);
		}

		const AvlTree & operator=(const AvlTree & rhs){
			if(this != &rhs){
				makeEmpty();
				root = clone(rhs.root);
			}
			return *this;
		}


	private:
		struct AvlNode	//二叉寻找树结点;
		{
			Comparable element;
			AvlNode *left;	//左结点；
			AvlNode *right	//右结点;
			int height;		//结点高度

			AvlNode(const Comparable & elem,AvlNode *l,AvlNode *r,int h = 0):element(elem),left(l),right(r),height(h){};	//Root结点的高度默认为0
		};

		AvlNode *root;	//定位根结点;

		int height(AvlNode *t) const{		//计算高度的函数
			if(t == NULL){
				return -1;
			}
			return (t -> height);
		}

		void rotateWithLeftChild(AvlNode * & k2){	//左子树单旋转
			AvlNode *k1 = k2 -> left;
			k2 -> left = k1 -> right;
			k1 -> right = k2;
			k2 -> height = max(height(k2 -> left),height(k2 -> right)) + 1;
			k1 -> height = max(height(k1 -> left),k2 -> height) + 1;
			k2 = k1;	//将k1设定为新的ROOT
		}

		void rotateWithRightChild(AvlNode * & k2){	//右子树单旋转
			AvlNode *k1 = k2 -> right;
			k2 -> right = k1 -> left;
			k1 -> left = k2;
			k2 -> height = max(height(k2 -> right),height(k2 -> left)) + 1;
			k1 -> height = max(height(k1 -> right),k2 -> height) + 1;
			k2 = k1;	//将k1设定为新的ROOT
		}

		void doubleWithLeftChild(AvlNode * & k3){  //左子树双旋转
			rotateWithRightChild(k3 -> left);
			rotateWithLeftChild(k3);
		}

		void doubleWithRightChild(AvlNode * & k3){  //右子树双旋转
			rotateWithLeftChild(k3 -> Right);
			rotateWithRightChild(k3);
		}

		void insert(const Comparable & x,AvlNode * & t){
			if(t == NULL){
				t = new AvlNode(x,NULL,NULL);
			}
			else if(x < t -> element){
				insert(x,t -> left);
				if(height(t -> left) - height(t -> right) == 2){
					if(x < t -> left -> element){	//左子树的左子树
						rotateWithLeftChild(t);
					}
					else{		//左子树的右子树
						doubleWithLeftChild(t);
					}
				}
			}
			else if(x > t -> element){
				insert(x,t -> right);
				if(height(t -> right) - height(t -> left) == 2){
					if(x > t -> right -> element){	//右子树的右子树
						rotateWithRightChild(t);
					}
					else{		//右子树的左子树;
						doubleWithRightChild(t);
					}
				}
			}
			else {};
			t -> height = max(height(t -> left),height(t -> right));
		}

		/*		to be continue...	*/
		void remove(const Comparable & x,AvlNode * & t){		//此处还没有改，麻烦，to be continue
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
				t -> element = findMin(t -> right) -> element;	//同时有左右子时，从右子中选取最小的元素赋值给结点;
				remove(t -> element,t -> right);
			}
			else{
				AvlNode *tempNode = t;
				t = (t -> left != NULL) ? t -> left : t -> right;
				delete tempNode;
			}
		}
		/*		to be continue		*/

		AvlNode * findMax(AvlNode * t) const{		//采用递归写法
			if(t == NULL){
				return NULL;
			}
			if(t -> right == NULL){
				return t;
			}
			else return findMax(t -> right);
		}

		AvlNode * findMin(AvlNode * t) const{		//采用非递归写法
			if(t == NULL){
				return NULL;
			}
			while(t -> left != NULL){
				t = t -> left;
			}
			return t;
		}

		bool contains(const Comparable & x,AvlNode * t){
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

		void makeEmpty(AvlNode * & t){
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

		void makeTree(AvlNode * t) const;	//omit

		AvlNode * clone(AvlNode * t) const{
			if(t == NULL){
				return NULL;
			}
			return new AvlNode(t -> element,clone(t -> left),clone(t -> right));
		}

};//struct of AvlTree
