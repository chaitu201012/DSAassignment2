#include<bits/stdc++.h>
using namespace std;

template<typename C,typename T>
class AVLTree{
public:
int noOfElements=0;
static const int balance_allowed=1;
class node{
    public:
        C key;
        T value;
        int height;
        node * left;
        node * right;
        node(C k,T v){ 
            key=k;
            value=v;
            left=NULL;
            right=NULL;
            height=0;
        }
    };
    node *root =nullptr;
         /*
        T operator = (C k,T v){
            //this[k]=
            if(!find(k)) insert(k,v);
            else {
                node *temp=getNode(root,key);
                return temp->value; 
            }
        }*/
        T operator[](C key){
            if(find(key)){ 
                node *temp=getNode(root,key);
                return temp->value;
            } 
            else{
                cout<<"Key Not Present\n";
                exit(0);
            }
        
        }
        void insert(C x,T y){
            root=inserSupplement(x,y,root);
        }
        void erase(C x){
            root=deletion(x,root);
        }
        bool find(C x){
            return searchSupplement(root,x);
        }
        int size(){
            return noOfElements;
        }
        void clear(){
            node *head=root;
            while(head!=NULL){
                head=deletion(head->key,head);
            }
           // clearSupplement(root);
           
            root=nullptr;
            noOfElements=0;
        }
        void inordertraversal(){
            inorderHelper(root);
        }
    private:
        int Height(node * head){
            return head==NULL ?-1 : head->height;
        }
        
        node * rotateWithRightChild(node * head){
            node * newhead = head->left;
            head->left = newhead->right;
            newhead->right = head;
            head->height = 1+max(Height(head->left), Height(head->right));
            newhead->height = 1+max(Height(newhead->left), Height(newhead->right));
            return newhead;
        }

        node * rotateWithLeftChild(node * head){
            node * newhead = head->right;
            head->right = newhead->left;
            newhead->left = head;
            head->height = 1+max(Height(head->left), Height(head->right));
            newhead->height = 1+max(Height(newhead->left), Height(newhead->right));
            return newhead;
        }
        node * doubleWithRightChild(node * head){
            head->left = rotateWithLeftChild(head->left);
            return rotateWithRightChild(head);
        }
        node * doubleWithLeftChild(node * head){
            head->right = rotateWithRightChild(head->right);
            return rotateWithLeftChild(head);
        }
        node * balance(C x,node * head){
            if((Height(head->left) - Height(head->right))>balance_allowed){
                if(x < head->left->key){
                    return rotateWithRightChild(head);
                }
                else{
                    return doubleWithRightChild(head);
                }
            }
            else if((Height(head->right) - Height(head->left))>balance_allowed){
                if(x > head->right->key){
                    return rotateWithLeftChild(head);
                }
                else{
                    return doubleWithLeftChild(head);
                }
            }
            head->height = 1 + max(Height(head->left), Height(head->right));
            return head;
        }
        void inorderHelper(node * head){
            if(head==NULL) return ;
            inorderHelper(head->left);
            cout<<head->key<<" ";
            inorderHelper(head->right);
        }
        

        node * inserSupplement( C x,T y,node * head){
            //cout<<"entresetrt\n";
            if(head==NULL){
                noOfElements+=1;
                node * temp = new node(x,y);
                return temp;
            }
            if(x < head->key) head->left = inserSupplement(x,y,head->left);
            else if(x > head->key) head->right = inserSupplement(x,y,head->right);
            return balance(x,head);
            
            //return head;
            
        }
        node * findMin(node * head){
            if( head == NULL )
            return NULL;
            if( head->left == NULL ) return head;
            return findMin( head->left );

        }
        node * deletion(C x, node * head){
            if(head==NULL) return NULL;
            if(x < head->key){
                head->left = deletion(x,head->left);
            }
            else if(x > head->key){
                head->right = deletion(x,head->right);
            }
            
            else{
                node * r = head->right;
                if(head->right==NULL){
                    node * l = head->left;
                    delete(head);
                    head = l;
                    noOfElements--;
                }
                else if(head->left==NULL){
                    delete(head);
                    head = r;
                    noOfElements--;
                }
                else if(head->right!=NULL && head->left!=NULL){
                    //two children
                   // node * temp=head;
                    node * temp=findMin(head->right);
                    head->key=temp->key;
                    head->value=temp->value;
                    head->right=deletion(head->key,head->right);
                    
                    //head=temp;
                }


            }
            
                /*
                node * r = head->right;
                if(head->right==NULL){
                    node * l = head->left;
                    delete(head);
                    head = l;
                }
                else if(head->left==NULL){
                    delete(head);
                    head = r;
                }
                else{
                    while(r.left!=NULL) r = r.left;
                    head->key = r.key;
                    head->right = deletion(head->right, r.key);
                }*/
            if(head==NULL) return head;
            //head->height = 1 + max(Height(head->left), Height(head->right));
            
            return balance(head->key,head);
            //return head;
        }
        bool searchSupplement(node * head, C x){
            if(head == NULL) return false;
           // T k = head->key;
            if(head->key == x) return head;
            if(head->key > x) return searchSupplement(head->left, x);
            if(head->key < x) return searchSupplement(head->right, x);
            return false;
        }
        node *getNode(node * head, C x){
            if(head == NULL) return NULL;
           // T k = head->key;
            if(head->key == x) return head;
            if(head->key > x) return getNode(head->left, x);
            if(head->key < x) return getNode(head->right, x);
            return head;
        }
};
int main(){
    int count=0;
    AVLTree<string,double> Map;
    int Qcount,c;
    string key;
    double val;
    cin>>Qcount;
    while(Qcount>0){
        cin>>c;
        if(c==1){
            cin>>key>>val;
            Map.insert(key,val);
        }
        else if(c==2){
            cin>>key;
            Map.erase(key);
        }
        else if(c==3){
            cin>>key;
            if(Map.find(key)) cout<<"Found\n";
            else cout<<"Not Found\n";
        }
        else if(c==4) {
            cin>>key;
            cout<<Map[key]<<"\n";
        }
        else if(c==5){
            cout<<Map.size()<<"\n";
        }
        else if(c==6){
            Map.clear();
        }
        Qcount--;
    }
    
    return 0;
}
