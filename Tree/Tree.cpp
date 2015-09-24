template<class T>
class TreeNode{
	public:
		TreeNode(const T& value);
		virtual ~TreeNode();
		bool isLeaf();
		T value;
		TreeNode<T> *LeftMostChild();			// 返回第一个左孩子 
		TreeNode<T> *RightSibling();			// 返回右兄弟 
		void setValue(const T& value);			// 设置当前结点的值 
		void setChild(TreeNode<T> *pointer);  // 设置左孩子   
		void setSibling(TreeNode<T> *pointer);    // 设置右兄弟   
		void InsertFirst(TreeNode<T> *node);    // 以第一个左孩子身份插入结点   
		void InsertNext(TreeNode<T> *node);		// 以右兄弟的身份插入结点 
};

template<class T> 
class Tree{
	public:
		Tree();      // 构造函数
		virtual ~Tree();     // 析构函数     
		TreeNode<T>* getRoot();       // 返回树中的根结点   
		void CreateRoot(const T& rootValue);    // 创建值为rootValue的根结点 
		bool isEmpty();          // 判断是否为空树     
		TreeNode<T>* Parent(TreeNode<T> *current);           // 返回父结点   
		TreeNode<T>* PrevSibling(TreeNode<T> *current);   //返回前一个兄弟   
		void DeleteSubTree(TreeNode<T> *subroot);   // 删除以subroot子树    
		void RootFirstTraverse(TreeNode<T> *root);   // 先根深度优先遍历树  
		void RootLastTraverse(TreeNode<T> *root);   // 后根深度优先遍历树   
		void WidthTraverse(TreeNode<T> *root);        // 广度优先遍历树 }; 
};

template<class T> 
void Tree<T>::RootFirstTraverse(TreeNode<T> *root){		//先根深度优先遍历森林
	while(root != NULL){
		cout << root->value;
		RootFirstTraverse(root->LeftMostChild());		//后根深度优先遍历森林
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
void Tree<T>::WidthTraverse(TreeNode<T> *root){		//广度优先遍历森林
	using std::queue;		//使用STL中的队列；
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
TreeNode<T>* Tree<T>::Parent(TreeNode<T> *current){		//寻找父节点
	using std::queue;		//使用STL中的队列；
	queue<TreeNode<T>*> aQueue;
	TreeNode<T> *pointer = root; 
	TreeNode<T> *father = upperlevelpointer  = NULL;    // 记录父结点 
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
		DestroyNodes(root->LeftMostChild());//递归删除第一子树
		DestroyNodes(root->RightSibling());   //递归删除其他子树
		delete root; //删除根结点 
	}
};

template<class T> 
void Tree<T>::DeleteSubTree(TreeNode<T> *subroot){
	if(subroot == NULL){
		return;
	}
	TreeNode<T> *pointer = Parent(subroot);
	if(pointer == NULL){		//subroot是个树根
		pointer = root;
		while(pointer->RightSibling() != subroot){
			pointer = pointer->RightSibling();
		}
		 pointer->setSibling(subroot->RightSibling()); // 前后挂接，脱链    
	}   
	else if (pointer->LeftMostChild() == subroot) // subroot为最左子 
		pointer->setChild(subroot->RightSibling()); // 挂新的最左  
	else {// subroot有左兄弟的情况   
		pointer = pointer->LeftMostChild();   // 下降到最左兄弟   
		while (pointer->RightSibling() != subroot){// 顺右链找左邻兄弟  
			pointer = pointer->RightSibling();     
		}
		pointer->setSibling(subroot->RightSibling()); // 前后挂接，脱链 
	}   
	 subroot->setSibling(NULL);// 非常重要，丢了会出错  
	 DestroyNodes(subroot);  // 删除以subroot代表的子森林的所有结点 
};