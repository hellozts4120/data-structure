/*		Fake Code		*/
#include<iostream>
#include<algorithm>
using namespace std;		//�󲿷�BSF��code��ֱ��ʹ�ã�Ψ������Ԫ����Ҫ���иı䣬ͬʱ����߶ȵ�����
							//����insert,delete�����ǸĶ����ģ�Ҳ��AvlTree�ĺ��ģ�
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

		const AvlTree & operator=(const AvlTree & rhs){
			if(this != &rhs){
				makeEmpty();
				root = clone(rhs.root);
			}
			return *this;
		}


	private:
		struct AvlNode	//����Ѱ�������;
		{
			Comparable element;
			AvlNode *left;	//���㣻
			AvlNode *right	//�ҽ��;
			int height;		//���߶�

			AvlNode(const Comparable & elem,AvlNode *l,AvlNode *r,int h = 0):element(elem),left(l),right(r),height(h){};	//Root���ĸ߶�Ĭ��Ϊ0
		};

		AvlNode *root;	//��λ�����;

		int height(AvlNode *t) const{		//����߶ȵĺ���
			if(t == NULL){
				return -1;
			}
			return (t -> height);
		}

		void rotateWithLeftChild(AvlNode * & k2){	//����������ת
			AvlNode *k1 = k2 -> left;
			k2 -> left = k1 -> right;
			k1 -> right = k2;
			k2 -> height = max(height(k2 -> left),height(k2 -> right)) + 1;
			k1 -> height = max(height(k1 -> left),k2 -> height) + 1;
			k2 = k1;	//��k1�趨Ϊ�µ�ROOT
		}

		void rotateWithRightChild(AvlNode * & k2){	//����������ת
			AvlNode *k1 = k2 -> right;
			k2 -> right = k1 -> left;
			k1 -> left = k2;
			k2 -> height = max(height(k2 -> right),height(k2 -> left)) + 1;
			k1 -> height = max(height(k1 -> right),k2 -> height) + 1;
			k2 = k1;	//��k1�趨Ϊ�µ�ROOT
		}

		void doubleWithLeftChild(AvlNode * & k3){  //������˫��ת
			rotateWithRightChild(k3 -> left);
			rotateWithLeftChild(k3);
		}

		void doubleWithRightChild(AvlNode * & k3){  //������˫��ת
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
					if(x < t -> left -> element){	//��������������
						rotateWithLeftChild(t);
					}
					else{		//��������������
						doubleWithLeftChild(t);
					}
				}
			}
			else if(x > t -> element){
				insert(x,t -> right);
				if(height(t -> right) - height(t -> left) == 2){
					if(x > t -> right -> element){	//��������������
						rotateWithRightChild(t);
					}
					else{		//��������������;
						doubleWithRightChild(t);
					}
				}
			}
			else {};
			t -> height = max(height(t -> left),height(t -> right));
		}

		/*		to be continue...	*/
		void remove(const Comparable & x,AvlNode * & t){		//�˴���û�иģ��鷳��to be continue
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
				AvlNode *tempNode = t;
				t = (t -> left != NULL) ? t -> left : t -> right;
				delete tempNode;
			}
		}
		/*		to be continue		*/

		AvlNode * findMax(AvlNode * t) const{		//���õݹ�д��
			if(t == NULL){
				return NULL;
			}
			if(t -> right == NULL){
				return t;
			}
			else return findMax(t -> right);
		}

		AvlNode * findMin(AvlNode * t) const{		//���÷ǵݹ�д��
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
