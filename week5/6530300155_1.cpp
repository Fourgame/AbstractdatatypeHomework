#include<iostream>
using namespace std;

struct node{
    int value;
    int pow;
    struct node *link;
    struct node *next;
};

void printall(struct node *head){
    struct node *show = head;
    cout<<"Output : ";
    while(show){
            struct node *showmore = show->link;
            if(show->link!=NULL){
            while(showmore){
                show->value=show->value+showmore->value;
                showmore=showmore->link;
            }
            }
        
        if(show->pow==1){
        cout<<show->value<<"x";
        }
        else if(show->pow==0){
        cout<<show->value;
        }
        else{
        cout<<show->value<<"x^"<<show->pow;
        }
        if(show->next!=NULL){
        cout<<"+";}
        show=show->next;
    }

}

struct node *insert(struct node *head,int value,int pow){
    struct node *p = new struct node;
    int count = 0;
    p->value=value;
        p->pow=pow;
        p->link=NULL;
        p->next=NULL;
    if(head==nullptr){
        head=p;
        return head;
    }
    struct node *check = head;
    while(check!=nullptr){
        if(check->pow==p->pow){
        count+=1;
        if(check->link==NULL){
        check->link=p;
        check=check->next;
        continue;
        }
        
        struct node *taillink=check;
        while(taillink->link!=NULL){
        taillink=taillink->link;
        }
        taillink->link=p;
        
        }
        check=check->next;
    }
    if(count==0){
    struct node *tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=p;
    }
    return head;
}

int main(){
    int a,b;
    struct node *head = nullptr;
    cout<<"Input P1 : ";
    do {
        cin>>a;
        if (a == -99){break;}
        cin>>b;
        head=insert(head,a,b);
    } while (a != -99);
    cout<<"Input P2 : ";
    do {
        cin>>a;
        if (a == -99){break;}
        cin>>b;
        head=insert(head,a,b);
    } while (a != -99);

    printall(head);

    while (head) {
        struct node *temp = head;
        head = head->next;
        delete temp;
    }
}