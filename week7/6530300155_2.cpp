#include <iostream>
#include <string>
using namespace std;
struct node{
    int value;
    node *next;
};
struct rocation{
    node *tail;
    node *head;
};

bool isempty(struct rocation S){
    return S == nullptr;
}
rocation queuecreative(void){
    return nullptr;
}
void pushqueue(int x,struct rocation S){
    while(i==x){
    queue a = new node;
    a->value=x;
    a->next=S;
    S=a;
    }
    queue temp=S;
    while (temp->next==nullptr){
        temp=temp->next;
    }
    temp->next=S;
}


int dequeue(int x,struct rocation S){
    queue temp=S;
    queue prev = nullptr;
    int i=0;
    int a=0;
    if(x==0){
        while(temp->next!=nullptr){
            queue prevtemp = temp;
            temp=temp->next;
            delete prevtemp;
        }
        int tempp = temp->value;
        return tempp;
    }else{
    while(i==x){
    prev = temp;
    temp=temp->next;
    i++;
    }
    prev=temp->next;
    }
    delete temp;
}
void makeempty(struct rocation S){
    while(!isempty(S)){
        queue temp = S;
        S=S->next;
        delete temp;
    }
}

int main(){
    int a,b,check=0;
    rocation q = queuecreative();
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
