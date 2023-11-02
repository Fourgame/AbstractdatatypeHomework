#include<iostream>
using namespace std;
void Print_from_front(char (&a)[5][5]){
    for(int t=0;t<5;t++){
    for(int i=0;i<=4;i++){
        for(int j=i;j<=4;j++){
            for(int k=i;k<=j;k++){
                cout<<a[t][k];
            }
            cout<<" ";
        }
    }
    cout<<"\n";
    }
}
void Print_from_back(char (&a)[5][5]){
    for(int t=0;t<5;t++){
    for(int i=4;i>=0;i--){
        for(int j=i;j>=0;j--){
            for(int k=i;k>=j;k--){
                cout<<a[t][k];
            }
            cout<<" ";
        }
    }
    cout<<"\n";
    }
}
void Match_data_base(char (&a)[5][5],string *db){
    int found = 1;
    string temp="";
    for(int t=0;t<5;t++){
    for(int i=0;i<=4;i++){
        for(int j=i;j<=4;j++){
            for(int k=i;k<=j;k++){
                cout<<a[t][k];
                temp += a[t][k];
            }
            for(int x=0;x<14;x++){
                if(temp.compare(db[x])==0){
                    cout<<" Found "<<found;
                    found+=1;
                }
                }
            temp="";
            cout<<"\n";
        }
    }
    }

    for(int t1=0;t1<5;t1++){
    for(int i1=4;i1>=0;i1--){
        for(int j1=i1;j1>=0;j1--){
            for(int k1=i1;k1>=j1;k1--){
                cout<<a[t1][k1];
                    temp += a[t1][k1];
            }
            for(int x1=0;x1<14;x1++){
                if(temp.compare(db[x1])==0){
                    found+=1;
                    cout<<" Found "<<found;
                }
                }
            temp="";
            cout<<"\n";
        }
    }
    }
    cout<<"Total="<<found;
}
int main (){
    int i,j,k,choose; 
    string db[14]={"STLY", "THEME ", "THE" , "THEM" , "HE" , "ME" , "AN" , "GO", "AGO", "ROPE", "OPE", "OGA", "CUT", "OR"};
    char a[5][5]={ 
    {'S','T','L','Y','R'}, 
    {'T','H','E','M','E'}, 
    {'A','N','A','G','O'}, 
    {'R','O','P','E','S'},
    {'K','T','T','U','C'}};
    cout<<"===========================\n  MENU\n===========================\n\n1. Print from front\n2. Print from back\n3. Match data base\nPlease choose > ";
    cin>>choose;
    
    switch(choose){
        case 1 : 
        Print_from_front(a);
        break;
        case 2 : 
        Print_from_back(a);
        break;
        case 3 :
        Match_data_base(a,db);
        break;
    } 
    }