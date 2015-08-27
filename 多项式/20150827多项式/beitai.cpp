    #include <iostream>  
      
    using namespace std;  
      
    class Node{  
    public:  
        Node *next_;  
        int coeff_;  
        int power_;  
    };  
      
    class List{  
    public:  
        List(void)  { head_=new Node;  head_->next_=NULL;  }  
        ~List(void) { delete head_; }  
        void Insert(int coeff ,int power){   
            Node *pnode = head_;  
            while( pnode->next_ != NULL && pnode->next_->power_ > power ){  
                pnode = pnode->next_;  
            }  
            if ( pnode->next_!=NULL && pnode->next_->power_ == power ){  
                pnode->next_->coeff_ += coeff;  
            }else{  
                Node *nnode = new Node;  
                nnode->coeff_ = coeff;  
                nnode->power_ = power;  
                nnode->next_ = pnode->next_;  
                pnode->next_ = nnode;  
            }  
        }  
        void Output(void) {  
            Node *pnode = head_->next_;  
            while( pnode != NULL ){  
                if ( pnode->coeff_ != 0 )  
                    cout << "[ " << pnode->coeff_ << " " << pnode->power_ << " ] " ;  
                pnode = pnode->next_;  
            }  
            cout << endl;  
        }  
    private:  
        Node *head_;  
    };  
      
    List *_list;  
      
    int main(void){  
        int i,j;  
        int num, coeff, power;  
        string s;  
        cin >> num;  
        _list = new List [num];  
        for ( i=0; i<num; i++ ){  
            cin >> coeff >> power;  
            while( power >= 0 ){  
                _list[i].Insert(coeff,power);  
                cin >> coeff >> power;  
            }  
            getline(std::cin, s);  
      
            cin >> coeff >> power;  
            while( power >= 0 ){  
                _list[i].Insert(coeff,power);  
                cin >> coeff >> power;  
            }  
            getline(std::cin, s);  
        }  
        for ( i=0; i<num; i++ )  
            _list[i].Output();  
        delete[] _list;  
    }  