#include<iostream>
#include<stack>
using namespace std;

int main(){
    int choose,input;
    stack<int> getstack;
    while(choose!=4){
    cout<<"\n=======MENU=======";
    cout<<"\n1) Push\n2) Pop\n3) Top\n4) Exit";
    cout<<"\nPlease choose> ";
    cin>>choose;

    switch (choose){
    case 1 : 
        cout<<"\nPush: ";
        cin>>input;
        getstack.push(input);
        cout<<"Success!\n";
        break;
    case 2 :
        if(!getstack.empty()){
            cout<<"Pop: "<<getstack.top()<<"\n";
            getstack.pop();
        }
        else{
            cout<<"Stack Emtry!\n";
        }
        break;
    case 3 : 
        if(!getstack.empty()){
        cout<<"Top: "<<getstack.top()<<"\n";
        }
        else{
            cout<<"Stack Emtry!\n";
        }
    }
}
}