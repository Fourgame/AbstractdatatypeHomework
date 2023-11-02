#include<iostream>
using namespace std ;
struct record{
    int value;
    struct record *next;
};
struct record *Insert(int a,struct record *head){
     struct record* node = new struct record;
    node->value = a;
    node->next = NULL;

    if (head == NULL || a < head->value) {
        node->next = head;
        return node;
    }

    struct record* current = head;
    while (current->next != NULL && a >= current->next->value) {
        current = current->next;
    }

    node->next = current->next;
    current->next = node;
    return head;
}

void printalldata(struct record *head){
    struct record *p;
    p=head;
    int count = 0,i,j,k,temp;
    while(p)
    { 
        cout<<p->value<<" ";
        p=p->next;
        count++;
    }
}

void printfirstandlast(struct record *head){
    struct record *p;
    p=head;
    int count = 0,i,j,k,temp;
    while(p)
    { 
        if(p->next==NULL){i=p->value;}
        if(count==0){j=p->value;}
        p=p->next;
        count++;
    }
    // int *data = new int[count];
    // p=head;
    // for(int k=0;k<count;k++){
    //     data[k]=p->value;
    //     p=p->next;
    // }

    // for (i = 0; i < count - 1; i++) {
    //     for (j = 0; j < count - i - 1; j++) {
    //         if (data[j] > data[j + 1]) {
    //             temp = data[j];
    //             data[j] = data[j + 1];
    //             data[j + 1] = temp;
    //         }
    //     }
    // }
    cout<<"First : "<<j;
    cout<<"\nLast : "<<i;

}
void menu(){
    cout<<"\n========MENU=======\n1) Insert\n2) Print All data\n3) Print first and last\n4) Exit\nPlease choose > ";
}
int main (){
    int insert=0 ,a;
    struct record *head=NULL;
    while(insert != 4){
    menu();
    cin>>insert;
    switch(insert){
        case 1 :
        cout<<"Insert : ";
        cin>>a;
        head=Insert(a,head);
        cout<<"Success! \nList = ";
        printalldata(head);
        break;
        case 2 :
        cout<<"List = ";
        printalldata(head);
        break;
        case 3 :
        printfirstandlast(head);
        break;
    }   
    }
}
