#include <iostream>
#include <string>
using namespace std;
typedef struct node{
    int value;
    node *next;
}* queue;
bool isempty(queue S){
    return S == nullptr;
}
queue queuecreative(void){
    return nullptr;
}
void pushqueue(int x,queue& S){
    queue a = new node;
    a->value=x;
    a->next=S;
    S=a;
}
int dequeue(queue& S){
    queue temp=S;
    queue prev = nullptr;
    while(temp->next!=nullptr){
    prev = temp;
    temp=temp->next;
    }
    if (prev != nullptr) {
        prev->next = nullptr;
    } else {
        S = nullptr;
    }

    int a = temp->value;
    delete temp;
    return a;
}
void makeempty(queue& S){
    while(!isempty(S)){
        queue temp = S;
        S=S->next;
        delete temp;
    }
}

int main(){
    int a,b,check=0;
    queue q = queuecreative();
    do{
    cout << "=======MENU======\n1. Enqueue\n2. Dequeue\n3. Exit\nPlease choose > ";
    cin>>check;
    if(check==1){
    cout<<"Enter Data : ";
    cin>>a;
    pushqueue(a,q);
    cout<<"Success!\n";
    }
    if(check==2){
        if(isempty(q)){cout<<"Empty! Can\'t Dequeue\n";
        }
        else{
        b=dequeue(q);
        cout<<"Dequeue "<<b<<endl;
    }
    }
    }while(check!=3);
    makeempty(q);
    }
