#include<iostream>
using namespace std;
int main (){
    int i,j,k,input; 
    char a[5][5]={ 
    {'S','T','L','Y','R'}, 
    {'T','H','E','M','E'}, 
    {'A','N','A','G','O'}, 
    {'R','O','P','E','S'},
    {'K','T','T','U','C'}};
    cout<<"Input : ";
    cin>>input;
        for(j=1;j<=5;j++){
            for(k=0;k<j;k++){
                cout<<a[input-1][k];
            }
            cout<<" ";
        }
    }
