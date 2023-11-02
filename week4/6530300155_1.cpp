#include<iostream>
using namespace std;

struct record {
    int value;
    struct record* next;
};

struct record* Insert(int a, struct record* head) {
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

struct record* Delate(struct record* head,int a) {
       if (head == nullptr)
        return nullptr;

    if (head->value == a) {
        struct record* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    struct record* current = head;
    while (current->next) {
        if (current->next->value == a) {
            struct record* temp = current->next;
            current->next = current->next->next;
            delete temp;
            break;
        }
        current = current->next;
    }
    return head;
}

void printalldata(struct record* head) {
    struct record* p;
    p = head;
    while (p) {
        cout << p->value << " ";
        p = p->next;
    }

}

struct record* SortAscending(struct record* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    struct record* sortedHead = nullptr;
    struct record* current = head;

    while (current != nullptr) {
        struct record* nextNode = current->next;
        sortedHead = Insert(current->value, sortedHead);
        current = nextNode;
    }

    return sortedHead;
}

struct record* SortDescending(struct record* head) {
     if (head == nullptr || head->next == nullptr)
        return head;

    struct record* sortedHead = nullptr;
    struct record* current = head;

    while (current != nullptr) {
        struct record* nextNode = current->next;
        current->next = sortedHead;
        sortedHead = current;
        current = nextNode;
    }

    return sortedHead;
}

int numberofnode(struct record *head){
    struct record *p;
    int count=0;
    p=head;
    while(p){
        count+=1;
        p=p->next;
    }
    return count;
}

void printoddnode(struct record* head) {
    struct record* p;
    int count=1;
    p=SortAscending(head);
    while (p) {
        if(count%2==1){
        cout << p->value << " ";
        p = p->next;
        }else{
            p = p->next;
        }
        count++;
    }

}

void printfirstandlast(struct record* head) {
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
    cout<<"First : "<<j;
    cout<<"\nLast : "<<i;

}

void menu() {
    cout << "\n========MENU=======\n1) Insert\n2) Delete\n3) Print min to max / max to min\n4) Count node\n5) Print only odd node\n6) Exit\nPlease choose > ";
}

int main() {
    int insert = 0, a;
    struct record* head = NULL;
    while (insert != 6) {
        menu();
        cin >> insert;
        switch (insert) {
        case 1:
            cout << "Insert: ";
            cin >> a;
            head = Insert(a, head);
            cout << "Success! \nList = ";
            head = SortAscending(head);
            printalldata(head);
            break;
        case 2:
            cout << "Insert: ";
            cin >> a;
            head = Delate(head,a);
            cout << "Success! \n";
            cout << "List = ";
            printalldata(head);
            break;
        case 3:
            cout << "Sort Ascending:\n";
            head = SortAscending(head);
            cout << "List = ";
            printalldata(head);
            cout << "\nSort Descending:\n";
            head = SortDescending(head);
            cout << "List = ";
            printalldata(head);
            break;
        case 4:
            cout<<"Number of Node = "<<numberofnode(head);
            break;
        case 5:
            cout<<"Odd node = ";
            printoddnode(head);
            break;
            }
    }
    return 0;
}