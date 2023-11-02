#include<iostream>
using namespace std;
int main (){
    int input[10]={10,2,3,56,41};
    cout<<"Enter : 10 2 3 56 41 ";
    cin>>input[5]>>input[6]>>input[7]>>input[8]>>input[9];
    cout<<"Output : ";
    for(int i=9 ; i>=0 ;i--){
        cout<<input[i]<<" ";
    }

}