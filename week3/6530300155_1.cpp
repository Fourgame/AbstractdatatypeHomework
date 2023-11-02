#include <iostream>
using namespace std;

struct record{
    int value ;
    struct record *next;
};
void insert(int a,struct record *p){
    p->value=a;
    p->next=NULL;
}

int main (){
    int a;
    struct record *p = new struct record;
    cout << "Enter : ";
    cin>>a;
    insert(a,p);
    cout <<"Value = "<< p->value;
}