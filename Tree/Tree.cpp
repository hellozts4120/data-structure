template<class T>
class TreeNode{
	public:
		TreeNode(const T& value);
		virtual ~TreeNode();
		bool isLeaf();
		T value;
		TreeNode<T> *LeftMostChild();			// ���ص�һ������ 
		TreeNode<T> *RightSibling();			// �������ֵ� 
		void setValue(const T& value);			// ���õ�ǰ����ֵ 
		void setChild(TreeNode<T> *pointer);  // ��������   
		void setSibling(TreeNode<T> *pointer);    // �������ֵ�   
		void InsertFirst(TreeNode<T> *node);    // �Ե�һ��������ݲ�����   
		void InsertNext(TreeNode<T> *node);		// �����ֵܵ���ݲ����� 
};

template<class T> 
class Tree{
	public:
		Tree();      // ���캯��
		virtual ~Tree();     // ��������     
		TreeNode<T>* getRoot();       // �������еĸ����   
		void CreateRoot(const T& rootValue);    // ����ֵΪrootValue�ĸ���� 
		bool isEmpty();          // �ж��Ƿ�Ϊ����     
		TreeNode<T>* Parent(TreeNode<T> *current);           // ���ظ����   
		TreeNode<T>* PrevSibling(TreeNode<T> *current);   //����ǰһ���ֵ�   
		void DeleteSubTree(TreeNode<T> *subroot);   // ɾ����subroot����    
		void RootFirstTraverse(TreeNode<T> *root);   // �ȸ�������ȱ�����  
		void RootLastTraverse(TreeNode<T> *root);   // ���������ȱ�����   
		void WidthTraverse(TreeNode<T> *root);        // ������ȱ����� }; 
};

template<class T> 
void Tree<T>::RootFirstTraverse(TreeNode<T> *root){		//�ȸ�������ȱ���ɭ��
	while(root != NULL){
		cout << root->value;
		RootFirstTraverse(root->LeftMostChild());		//���������ȱ���ɭ��
		root = root->RightSibling();
	}
};
template<class T> 
void Tree<T>::RootLastTraverse(TreeNode<T> *root){
	while(root != NULL){
		RootLastTraverse(root->LeftMostChild());
		cout << root->value;
		root = root->RightSibling();
	}
};
template<class T> 
void Tree<T>::WidthTraverse(TreeNode<T> *root){		//������ȱ���ɭ��
	using std::queue;		//ʹ��STL�еĶ��У�
	queue<TreeNode<T>*> aQueue;
	TreeNode<T> *point = root;
	while(point != NULL){
		aQueue.push(point);
		point = point->RightSibling();
	}
	while(!aQueue.empty()){
		point = aQueue.front();
		aQueue.pop();
		cout << point->value;
		point = point->LeftMostChild();
		while(point != NULL){
			aQueue.push(point);
			point = point->RightSibling();
		}
	}
};
template<class T> 
TreeNode<T>* Tree<T>::Parent(TreeNode<T> *current){		//Ѱ�Ҹ��ڵ�
	using std::queue;		//ʹ��STL�еĶ��У�
	queue<TreeNode<T>*> aQueue;
	TreeNode<T> *pointer = root; 
	TreeNode<T> *father = upperlevelpointer  = NULL;    // ��¼����� 
	if(current!=NULL && point!=current){
		while(point != NULL){
			if(current == pointer) break;
			aQueue.push(pointer);
		}
		pointer = pointer->RightSibling();
	}
	while(!aQueue.empty()){
		pointer = aQueue.front();
		aQueue.pop();
		upperlevelpointer = pointer;
		pointer = pointer->LeftMostChild();
		while(pointer){
			if(current == pointer){
				father = upperlevelpoint;
			}
			else{
				aQueue.push(pointer);
				pointer = pointer->RightSibling();
			}
		}
	}
	aQueue.clear();
	return father;
};

template <class T>
void Tree<T>::DestroyNodes(TreeNode<T>* root){
	if (root){
		DestroyNodes(root->LeftMostChild());//�ݹ�ɾ����һ����
		DestroyNodes(root->RightSibling());   //�ݹ�ɾ����������
		delete root; //ɾ������� 
	}
};

template<class T> 
void Tree<T>::DeleteSubTree(TreeNode<T> *subroot){
	if(subroot == NULL){
		return;
	}
	TreeNode<T> *pointer = Parent(subroot);
	if(pointer == NULL){		//subroot�Ǹ�����
		pointer = root;
		while(pointer->RightSibling() != subroot){
			pointer = pointer->RightSibling();
		}
		 pointer->setSibling(subroot->RightSibling()); // ǰ��ҽӣ�����    
	}   
	else if (pointer->LeftMostChild() == subroot) // subrootΪ������ 
		pointer->setChild(subroot->RightSibling()); // ���µ�����  
	else {// subroot�����ֵܵ����   
		pointer = pointer->LeftMostChild();   // �½��������ֵ�   
		while (pointer->RightSibling() != subroot){// ˳�����������ֵ�  
			pointer = pointer->RightSibling();     
		}
		pointer->setSibling(subroot->RightSibling()); // ǰ��ҽӣ����� 
	}   
	 subroot->setSibling(NULL);// �ǳ���Ҫ�����˻����  
	 DestroyNodes(subroot);  // ɾ����subroot�������ɭ�ֵ����н�� 
};