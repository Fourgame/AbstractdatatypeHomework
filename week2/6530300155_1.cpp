#include<iostream>
using namespace std;
int main (){
    int a[5],input,chack=0;
    cout<<"Enter : ";
    for(int i=0;i<5;i++){
        cin >> a[i];
    }
    cout<<"(Index) | 0 1 2 3 4\n";
    cout<<"------|--------------------\n";
    cout<<"(value) | "<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4];
    cout<<"\nEnter value : ";
    cin>>input;
    for(int j=0;j<5;j++){
        if(input<a[j]){
            chack=j;
            cout<<"Index = "<< j ;
            break;
        }else if(j==4){
            cout<<"No number";
            break;
        }
    }
    


}