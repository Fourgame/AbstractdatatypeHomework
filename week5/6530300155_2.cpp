#include<iostream>
using namespace std;

struct node{
    int value;
    struct node *prev;
    struct node *tail;
};

void printall(struct node *head){
    if(head!=nullptr){
    struct node *show = head;
    cout<<"Output : ";
    while(show!=NULL){
        cout<<show->value<<" ";
        show=show->tail;
    }
    //เอาไว้กลับค่าเป็นหลังไปหน้าเช็คความถูกต้อง
    /*
    show = head; 
    cout<<"\nOutput : ";
    while(show->tail!=nullptr){
        show=show->tail;
    }
    while(show!=nullptr){
        cout<<show->value<<" ";
        show=show->prev;
    }
    */
    }else{
    cout<<"empty\n";
    }
}

struct node *insert(struct node *head,int value){
    struct node *p = new node;
    p->value=value;
    p->prev=nullptr;
    p->tail=head;
    if(head!=nullptr){
        head->prev=p;
    }
    head=p;
    return head;
}

struct node *deletes(struct node *head,int a){
    struct node *temp=head;
    struct node *temp2=new struct node;
    if(head==nullptr){
        return nullptr;
    }
    if(temp->value==a){
        head=head->tail;
        if(temp->tail!=nullptr){
            temp->tail->prev=NULL;
        }
        delete temp;
        return head;
    }

    while(temp->tail!=nullptr){
        if(temp->tail->value==a){
            temp2=temp->tail;
            temp->tail=temp->tail->tail;
            if(temp->tail!=NULL){
                temp->tail->prev=temp;
            }
            delete temp2;
            return head;
        }
        temp=temp->tail;
    }
        cout<<"None equel\n";
        return head;
}

void menu(){
    cout<<"\n========MENU=======\n";
    cout<<"1) Insert\n";
    cout<<"2) Delete\n";
    cout<<"3) Print\n";
    cout<<"4) Exit\n";
    cout<<"Please choose > ";
}

int main(){
    int a,b;
    struct node *head = nullptr;
    do {
        menu();
        cin>>a;
        switch(a){
            case 1 :
            cout<<"input : ";
            cin>>b;
            head=insert(head,b);
            cout<<"Success";
            break;
            case 2 :
            cout<<"input : ";
            cin>>b;
            head=deletes(head,b);
            cout<<"Success";
            break;
            case 3 :
            printall(head);
            break; 
        }
        
    } while (a != 4);
}