#include<iostream>
using namespace std;
int chackprime(int chack){
    int c = chack,i;
    if(chack>=2){
        for(i=2;i<=chack/2;i++){
            if(chack%i==0){
                return 1;
            }
        }
        return 0;
    }
    else{
        return 1;
    }
}
int main(){
    int chack;
    cout<<"input : ";
    cin>>chack;
    
    if(chackprime(chack)){
    cout<<"Not prime";
    }
    else{
    cout<<"prime";
    }
}