#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define MAXSIZE 104729 //Taking 10 thousandth prime number for now 
#define SIZE_ARRAY 100
#define SEED1 13
#define SEED2 17


template<typename K>

class UmapHash{ 

public:
        string key_table[MAXSIZE];
        K value_table[MAXSIZE];
        string key;
        K value;
        //T dummy;
        int string_flag=0;
        UmapHash(){
            for(int i=0;i<MAXSIZE;i++)
                key_table[i] = "empty";          
        }
        K operator [](string key){
            return Map(key);
        }
        K operator [](double key){
            double k=key;
            return Map(k);
        }
        K operator [](float key){
            float k=key;
            return Map(k);
        }
        K operator [](int key){
            int k=key;
            return Map(k);
        }
        K operator [](char key){
            char k=key;
            return Map(k);
        }
        bool findAsString(string key){
            int i=0;
            unsigned int index1=hash1(key, 991, MAXSIZE);
            unsigned int index2=hash2(key, 991, MAXSIZE);
            while(key_table[index1]!="empty"){
                
                index1=index1+i*index2;
                index1=index1%MAXSIZE;
                i++;
                if(key_table[index1]==key) return true;
            } 
            return false;

        }
        bool find(string  key){
           //return findAsString(string(to_string(key)));
            int i=0;
            unsigned int index1=hash1(key, 991, MAXSIZE);
            unsigned int index2=hash2(key, 991, MAXSIZE);
            while(key_table[index1]!="empty"){
                
                index1=index1+i*index2;
                index1=index1%MAXSIZE;
                i++;
                if(key_table[index1]==key) return true;
            } 
            return false;
        }
        bool find(double key){
           //return findAsString(string(to_string(key)));
           int i=0;
            unsigned int index1=hash1(string(to_string(key)), 991, MAXSIZE);
            unsigned int index2=hash2(string(to_string(key)), 991, MAXSIZE);
            while(key_table[index1]!="empty"){
                
                index1=index1+i*index2;
                index1=index1%MAXSIZE;
                i++;
                if(key_table[index1]==string(to_string(key))) return true;
            } 
            return false;
        }
        bool find(float key){
           //return findAsString(string(to_string(key)));
           int i=0;
            unsigned int index1=hash1(string(to_string(key)), 991, MAXSIZE);
            unsigned int index2=hash2(string(to_string(key)), 991, MAXSIZE);
            while(key_table[index1]!="empty"){
                
                index1=index1+i*index2;
                index1=index1%MAXSIZE;
                i++;
                if(key_table[index1]==string(to_string(key))) return true;
            } 
            return false;
        }
        bool find(int key){
           //return findAsString(string(to_string(key)));
           int i=0;
            unsigned int index1=hash1(string(to_string(key)), 991, MAXSIZE);
            unsigned int index2=hash2(string(to_string(key)), 991, MAXSIZE);
            while(key_table[index1]!="empty"){
                
                index1=index1+i*index2;
                index1=index1%MAXSIZE;
                i++;
                if(key_table[index1]==string(to_string(key))) return true;
            } 
            return false;
        }
        bool find(char key){
           //return findAsString(string(to_string(key)));
           int i=0;
            unsigned int index1=hash1(string(to_string(key)), 991, MAXSIZE);
            unsigned int index2=hash2(string(to_string(key)), 991, MAXSIZE);
            while(key_table[index1]!="empty"){
                
                index1=index1+i*index2;
                index1=index1%MAXSIZE;
                i++;
                if(key_table[index1]==string(to_string(key))) return true;
            } 
            return false;
        }
        void insertAsString(string key,K value){
            if(!find(key)){
                cout<<"entered insert\n";
                int i=0;
                unsigned int index1=hash1(key, 991, MAXSIZE);
                unsigned int index2=hash2(key, 991, MAXSIZE);
                while(key_table[index1]!="empty"){
                    
                    index1=index1+i*index2;
                    index1=index1%MAXSIZE;
                    i++;
                } 
                key_table[index1]=key;
                value_table[index1]=value;
            }
            else{
                cout<<"already key present\n";
            }
        }
        void insert(string key,K value){
            if(!find(key)){
                int i=0;
                unsigned int index1=hash1(key, 991, MAXSIZE);
                unsigned int index2=hash2(key, 991, MAXSIZE);
                while(key_table[index1]!="empty"){
                    
                    index1=index1+i*index2;
                    index1=index1%MAXSIZE;
                    i++;
                } 
                key_table[index1]=key;
                value_table[index1]=value;
            }
            //else cout<<"element already present\n";
        }
        void insert(double key,K value){
            if(!find(key)){
                int i=0;
                unsigned int index1=hash1(string(to_string(key)), 991, MAXSIZE);
                unsigned int index2=hash2(string(to_string(key)), 991, MAXSIZE);
                while(key_table[index1]!="empty"){
                    
                    index1=index1+i*index2;
                    index1=index1%MAXSIZE;
                    i++;
                } 
                key_table[index1]=string(to_string(key));
                value_table[index1]=value;
            }
        }
        void insert(float key,K value){
            if(!find(key)){
                int i=0;
                unsigned int index1=hash1(string(to_string(key)), 991, MAXSIZE);
                unsigned int index2=hash2(string(to_string(key)), 991, MAXSIZE);
                while(key_table[index1]!="empty"){
                    
                    index1=index1+i*index2;
                    index1=index1%MAXSIZE;
                    i++;
                } 
                key_table[index1]=string(to_string(key));
                value_table[index1]=value;
            }
        }
        void insert(int key,K value){
            if(!find(key)){
                int i=0;
                unsigned int index1=hash1(string(to_string(key)), 991, MAXSIZE);
                unsigned int index2=hash2(string(to_string(key)), 991, MAXSIZE);
                while(key_table[index1]!="empty"){
                    
                    index1=index1+i*index2;
                    index1=index1%MAXSIZE;
                    i++;
                } 
                key_table[index1]=string(to_string(key));
                value_table[index1]=value;
            }
        }
        void insert(char key,K value){
            if(!find(key)){
                int i=0;
                unsigned int index1=hash1(string(to_string(key)), 991, MAXSIZE);
                unsigned int index2=hash2(string(to_string(key)), 991, MAXSIZE);
                while(key_table[index1]!="empty"){
                    
                    index1=index1+i*index2;
                    index1=index1%MAXSIZE;
                    i++;
                } 
                key_table[index1]=string(to_string(key));
                value_table[index1]=value;
            }
        }
        void eraseAsString(string key){
            int i=0;
            unsigned int index1=hash1(key, 991, MAXSIZE);
            unsigned int index2=hash2(key, 991, MAXSIZE);
            while(key_table[index1]!="empty"){
                
                index1=index1+i*index2;
                index1=index1%MAXSIZE;
                i++;
                if(key_table[index1]==key) break;
            } 
            key_table[index1]="empty";
            //value_table[index1]=value;
        }
        void erase(string key){
            int i=0;
            unsigned int index1=hash1(key, 991, MAXSIZE);
            unsigned int index2=hash2(key, 991, MAXSIZE);
            while(key_table[index1]!="empty"){
                
                index1=index1+i*index2;
                index1=index1%MAXSIZE;
                i++;
                if(key_table[index1]==key) break;
            } 
            key_table[index1]="empty";

        }
        void erase(double key){
            int i=0;
            unsigned int index1=hash1(string(to_string(key)), 991, MAXSIZE);
            unsigned int index2=hash2(string(to_string(key)), 991, MAXSIZE);
            while(key_table[index1]!="empty"){
                
                index1=index1+i*index2;
                index1=index1%MAXSIZE;
                i++;
                if(key_table[index1]==string(to_string(key))) break;
            } 
            key_table[index1]="empty";

        }
        void erase(float key){
            int i=0;
            unsigned int index1=hash1(string(to_string(key)), 991, MAXSIZE);
            unsigned int index2=hash2(string(to_string(key)), 991, MAXSIZE);
            while(key_table[index1]!="empty"){
                
                index1=index1+i*index2;
                index1=index1%MAXSIZE;
                i++;
                if(key_table[index1]==string(to_string(key))) break;
            } 
            key_table[index1]="empty";

        }
        void erase(int key){
            int i=0;
            unsigned int index1=hash1(string(to_string(key)), 991, MAXSIZE);
            unsigned int index2=hash2(string(to_string(key)), 991, MAXSIZE);
            while(key_table[index1]!="empty"){
                
                index1=index1+i*index2;
                index1=index1%MAXSIZE;
                i++;
                if(key_table[index1]==string(to_string(key))) break;
            } 
            key_table[index1]="empty";

        }
        void erase(char key){
            int i=0;
            unsigned int index1=hash1(string(to_string(key)), 991, MAXSIZE);
            unsigned int index2=hash2(string(to_string(key)), 991, MAXSIZE);
            while(key_table[index1]!="empty"){
                
                index1=index1+i*index2;
                index1=index1%MAXSIZE;
                i++;
                if(key_table[index1]==string(to_string(key))) break;
            } 
            key_table[index1]="empty";

        }

        
        K mapAsString(string key){
            int i=0;
            unsigned int index1=hash1(key, 991, MAXSIZE);
            unsigned int index2=hash2(key, 991, MAXSIZE);
            while(key_table[index1]!="empty"){
                
                index1=index1+i*index2;
                index1=index1%MAXSIZE;
                i++;
                if(key_table[index1]==key) break;
            } 
            return value_table[index1];

        }
        K Map(string key){

           //return mapAsString(string(to_string(key)));
           int i=0;
            unsigned int index1=hash1(key, 991, MAXSIZE);
            unsigned int index2=hash2(key, 991, MAXSIZE);
            while(key_table[index1]!="empty"){
                
                index1=index1+i*index2;
                index1=index1%MAXSIZE;
                i++;
                if(key_table[index1]==key) break;
            } 
            return value_table[index1];
            
        }
        K Map(double key){

           //return mapAsString(string(to_string(key)));
           int i=0;
            unsigned int index1=hash1(string(to_string(key)), 991, MAXSIZE);
            unsigned int index2=hash2(string(to_string(key)), 991, MAXSIZE);
            while(key_table[index1]!="empty"){
                
                index1=index1+i*index2;
                index1=index1%MAXSIZE;
                i++;
                if(key_table[index1]==string(to_string(key))) break;
            } 
            return value_table[index1];
            
        }
        K Map(int key){

           //return mapAsString(string(to_string(key)));
           int i=0;
            unsigned int index1=hash1(string(to_string(key)), 991, MAXSIZE);
            unsigned int index2=hash2(string(to_string(key)), 991, MAXSIZE);
            while(key_table[index1]!="empty"){
                
                index1=index1+i*index2;
                index1=index1%MAXSIZE;
                i++;
                if(key_table[index1]==string(to_string(key))) break;
            } 
            return value_table[index1];
            
        }
        K Map(float key){

           //return mapAsString(string(to_string(key)));
           int i=0;
            unsigned int index1=hash1(string(to_string(key)), 991, MAXSIZE);
            unsigned int index2=hash2(string(to_string(key)), 991, MAXSIZE);
            while(key_table[index1]!="empty"){
                
                index1=index1+i*index2;
                index1=index1%MAXSIZE;
                i++;
                if(key_table[index1]==string(to_string(key))) break;
            } 
            return value_table[index1];
            
        }
        K Map(char key){

           //return mapAsString(string(to_string(key)));
           int i=0;
            unsigned int index1=hash1(string(to_string(key)), 991, MAXSIZE);
            unsigned int index2=hash2(string(to_string(key)), 991, MAXSIZE);
            while(key_table[index1]!="empty"){
                
                index1=index1+i*index2;
                index1=index1%MAXSIZE;
                i++;
                if(key_table[index1]==string(to_string(key))) break;
            } 
            return value_table[index1];
            
        }
        unsigned int hash1(string x, int a, int p){
            unsigned int  h = SEED1;
            for (int  i=0 ; i < x.size() ; ++i)
                h = ((h*a) + x[i])% p;
            return h;
        }
        unsigned int hash2(string y, int b, int m){
            unsigned int  h = SEED2;
            for (int  i=0;i < y.size();++i)
                h = ((h*b) + y[i])%m;
            return h;
        }

};


int main(){
   
    UmapHash<double> st;
    int Qcount,c;
    string str;
    double val;
    cin>>Qcount;
    while(Qcount>0){
        cin>>c;
        if(c==1){
            cin>>str>>val;
            st.insert(str,val);
        }
        else if(c==2){
            cin>>str;
            st.erase(str);
        }
        else if(c==3){
            cin>>str;
            if(st.find(str)) cout<<"Found\n";
            else cout<<"Not Found\n";
        }
        else if(c==4){
            cin>>str;
            cout<<st[str]<<"\n";
        }
        Qcount--;

    }
    return 0;
}