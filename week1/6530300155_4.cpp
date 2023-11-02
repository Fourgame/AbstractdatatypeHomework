#include<iostream>
using namespace std;
int main(){
    int i,j,k,input;
    cout<<"Input : ";
    cin>>input;
    for(i=1;i<=input;i++){
        for(j=i;j<=input;j++){
            for(k=i;k<=j;k++){
            cout<<k;
        }
        cout<<" ";
        }
        if(i!=input){
        cout<<"\n";}
        else{
            cout<<input;
        }
        
    }
}