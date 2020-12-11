#include<bits/stdc++.h>
using namespace std;
//template<typename T,typename K>
/*
class node{
public:
    string name;
    int roll_no;
    node(string n,int r):name{n},roll_no{r}{}
    node & operator =(node* &nd){
        this->name=nd->name;
        this->roll_no=nd->roll_no;
        return *this;
    }
    bool operator==(node* &nd) const {
        return this->roll_no==nd->roll_no;
    }
    bool operator!=(node* &nd) const {
        return this->roll_no!=nd->roll_no;
    }
    bool operator>=(node* &nd) const {
        return this->roll_no>=nd->roll_no;
    }
    bool operator<=(node* &nd) const {
        return this->roll_no<=nd->roll_no;
    }
    bool operator>(node* &nd) const {
        return this->roll_no>=nd->roll_no;
    }
    bool operator<(node* &nd) const {
        return this->roll_no<=nd->roll_no;
    }
    ostream & operator <<(ostream &out){
        out<<this->name;
        out<<this->roll_no;
        return out;
    }
};*/
template<typename C>
struct AVLTree{
    C element;
    int height;
    AVLTree *left;
    AVLTree *right;
    static const int balance_allowed = 1;
    //AVLTree(){}
    AVLTree(const C &ele,AVLTree *l,AVLTree *r,int h=0): element{ele}, left{l},right{r},height{h}{}
    AVLTree(const C &&ele,AVLTree *l,AVLTree *r,int h=0): element{std::move(ele)}, left{l},right{r},height{h}{}

int Height(AVLTree *t) {
    return t==nullptr?-1:t->height;
}

void insert( const C &x, AVLTree* &t )
{
    if( t == nullptr ) t = new AVLTree{ x, nullptr, nullptr };
    else if( x <= t->element ) insert( x, t->left );
    else if( t->element < x ) insert( x, t->right );
    balance( t );
}
void balance( AVLTree * & t )
{
    if( t == nullptr )
    return;
    if( Height( t->left ) - Height( t->right ) > balance_allowed )
        if( Height( t->left->left ) >= Height( t->left->right ) ) 
            rotateWithLeftChild( t );
        else 
            doubleWithLeftChild( t );
    else
        if( Height( t->right ) - Height( t->left ) > balance_allowed )
            if( Height( t->right->right ) >= Height( t->right->left ) ) 
                rotateWithRightChild( t );
            else 
                doubleWithRightChild( t );
    t->height = max( Height( t->left ), Height( t->right ) ) + 1;
}
void rotateWithLeftChild( AVLTree * & k2 )
{
    AVLTree *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max( Height( k2->left ), Height( k2->right ) ) + 1;
    k1->height = max( Height( k1->left ), k2->height ) + 1;
    k2 = k1;
}
void rotateWithRightChild( AVLTree * & k2 )
{
    AVLTree *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max( Height( k2->left ), Height( k2->right ) ) + 1;
    k1->height = max( Height( k1->left ), k2->height ) + 1;
    k2 = k1;
}
void doubleWithLeftChild( AVLTree * & k3 )
{
    rotateWithRightChild( k3->left );
    rotateWithLeftChild( k3 );
}

void doubleWithRightChild( AVLTree * & k3 )
{
    rotateWithLeftChild( k3->right);
    rotateWithRightChild( k3);
    
}
AVLTree * findMin( AVLTree *t ) const
{
    if( t == nullptr )
    return nullptr;
    if( t->left == nullptr )
    return t;
    return findMin( t->left );
}
AVLTree * findMax( AVLTree *t ) const
{
    if( t == nullptr )
    return nullptr;
    if( t->right == nullptr )
    return t;
    return findMax (t->right);
}
void deletion( const C & x, AVLTree * & t )
{
    if( t == nullptr )
    return;
    if( x < t->element )
    deletion( x, t->left );
    else if( t->element < x )
    deletion( x, t->right );
    else if( t->left != nullptr && t->right != nullptr ) // Two children
    {
        t->element = findMin( t->right )->element;
        deletion( t->element, t->right );
    }
    else
    {
    AVLTree* oldNode = t;
        t = ( t->left != nullptr ) ? t->left : t->right;
        delete oldNode;
    }
    balance( t );
}
bool search( const C & x, AVLTree * & t )
{
    if( t == nullptr ) return false;
    if(t->element==x) return true;
    if( x < t->element ) return search( x, t->left );
    else if( t->element <x ) return search( x, t->right );
    return false;
}

void inorderTraversal(AVLTree* &head){
    if(head==NULL) return ;
    inorderTraversal(head->left);
    cout<<head->element<<",height="<<head->height<<" --> ";
    inorderTraversal(head->right);
}

void reverseInOrder(int k,AVLTree* &head,int &count){
    if(head==NULL) return ;
    reverseInOrder(k,head->right,count);
    count++;
    if(count==k) {
        cout<<head->element<<"\n";
    }
    reverseInOrder(k,head->left,count);
}
void kthLargest(int k,AVLTree* &head){
    int count=0;
    reverseInOrder(k,head,count);
    
}
int countHelper(const C & x, AVLTree * & t ){
    if( t == nullptr ) return 0;
    if(t->element==x) return 1+count_Occurences( x, t->left )+count_Occurences( x, t->right );
    else if( x <= t->element ) return count_Occurences( x, t->left );
    else if( t->element <x ) return count_Occurences( x, t->right );
    return 0;

}
int count_Occurences(const C & x, AVLTree * & t ){
    if( t == nullptr ) return 0;
    else return countHelper(x,t);
    
}


C lowerBound(const C & x, AVLTree * & t ){
    //static C min_element=x;
    if(t==nullptr){
        cout<<"Not present\n";
        exit(0);
    };
    if(t->element==x) return x;
    if( (t->element > x && t->left==nullptr) || (t->element>x && t->left->element<x)) return t->element;
    if(t->element<x){
        return lowerBound(x,t->right);  
    }
    else{
        return lowerBound(x,t->left);
    }
}

C upperBound(const C & x, AVLTree * & t ){
    //static C min_greater=x;
    if(t==nullptr){
        cout<<"Not present\n";
        exit(0);
    };
    if(t->element==x) return upperBound(x,t->right);
    if( (t->element > x && t->left==nullptr) || (t->element>x && t->left->element<x)) return t->element;
    if(t->element<x){
        //cout<<t->element<<"-->";
        return upperBound(x,t->right);  
    }
    else{
       // cout<<t->element<<"-->";
        return upperBound(x,t->left);
    }
}
void closestElementHelper(const C &x,AVLTree * &t,C& minDist,C & minDistKey,C & prevDistKey){
    //cout<<"entering  "<<x;
    if(t==nullptr) return;
    if(t->element==x){ minDistKey=x;return;}    
    if(minDist>=fabs(x-t->element)){
        minDist=fabs(x-t->element);
       // cout<<x<<"  "<<t->elementai<<" "<<fabs(x-t->element);
        //cout<<" prevDistKey "<<prevDistKey<<"  \n";
        minDistKey=t->element;
        //cout<<"minDistKey "<<minDistKey<<"  ";
        if((fabs(prevDistKey-x)==fabs(minDistKey-x)) && minDistKey > prevDistKey) minDistKey=prevDistKey;
        prevDistKey=minDistKey;
    }

    if(x < t->element) {
        //cout<<"entered left side\n";
        closestElementHelper(x,t->left,minDist,minDistKey,prevDistKey);
    }
    else{
        //cout<<"entered right side\n";
        closestElementHelper(x,t->right,minDist,minDistKey,prevDistKey);
    }

}

C closestElement(const C & x,AVLTree * & t){
    C minDist=std::numeric_limits<C>::max();
    C minDistKey=std::numeric_limits<C>::min();
    C prevDistKey=std::numeric_limits<C>::min();;
    closestElementHelper(x,t,minDist,minDistKey,prevDistKey);
    return (C)minDistKey;
    // return (C)minDistKey;
}
int rangeCount(const C &low, const C &high,AVLTree* &t){
    static int count=0;
    if(t==nullptr) return 0;
    if(t->element>=low && t->element<=high )  return 1+rangeCount(low,high,t->left)+rangeCount(low,high,t->right) ;
    else if(t->element< low) return rangeCount(low,high,t->right);
    else return rangeCount(low,high,t->left);
}

};

int main(){
    int count=0;
    AVLTree<int>* root=nullptr;
    //node<string,int> nd;
    //root->insert("chaitu",root);
    int Qcount,c,kthlarge;
    int str,high,low;
    cin>>Qcount;
    while(Qcount>0){
        cin>>c;
        if(c==1){
            cin>>str;
            root->insert(str,root);
        }
        else if(c==2){
            cin>>str;
            root->deletion(str,root);
        }
        else if(c==3){
            cin>>str;
            if(root->search(str,root)) cout<<"Found\n";
            else cout<<"Not Found\n";
        }
        else if(c==4){
            cin>>str;
            cout<<root->count_Occurences(str,root)<<"\n";
        }
        else if(c==5){
            cin>>str;
            cout<<root->lowerBound(str,root)<<"\n";
        }
        else if(c==6){
            cin>>str;
            cout<<root->upperBound(str,root)<<"\n";

        }
        else if(c==7){
            cin>>str;
            cout<<root->closestElement(str,root)<<"\n";
        }
        else if(c==8){
            cin>>kthlarge;
            root->kthLargest(kthlarge,root);
        }
        else if(c==9){
            cin>>low>>high;
            cout<<root->rangeCount(low,high,root)<<"\n";

        }
        else if(c==10){
            root->inorderTraversal(root);
        }
        Qcount--;
    }
    delete root;
    return 0;
}
