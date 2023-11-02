#include<iostream>
using namespace std;
struct record{
    char value;
    struct record *next;
};

void printall(struct record *head){
    cout << "List : ";
    
    struct record* current = head;
    while (current != nullptr) {
        if(current->value!='\n'){
        cout << current->value;
        }
        current = current->next;
    }
}

void odd(struct record *head){
    struct record* current = head->next;
    cout << "You odd: ";
    while (current != nullptr) {
        if (current->value != '\n') {
            cout << current->value;
        }
        if (current->next != nullptr && current->next->next != nullptr) {
            current = current->next->next;
        } else {
            break;
        }
    }

}

void even(struct record* head) {
    struct record* current = head;
    cout << "\nYou even: ";
    while (current != nullptr) {
        if (current->value != '\n') {
            cout << current->value;
        }
        if (current->next != nullptr && current->next->next != nullptr) {
            current = current->next->next;
        } else {
            break;
        }
    }
}
struct record *insert(struct record *head,char c){
    
            struct record* newNode = new struct record;
            newNode->value = c;
            newNode->next = nullptr;

            if (head == nullptr) {
                head = newNode;
            } else {
                struct record* current = head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }
        
    return head;
}


int main (){
    struct record *head=nullptr;
    int a;
    while(a!=4){
    cout <<"\n========MENU=======\n1) Insert\n2) Odd, even\n3) Decode\n4) Exit\nPlease choose >";
    cin>>a;
    switch(a){
    case 1:
    char c;
    cout << "Enter text('.' to exit) :";
    do {
        c = getchar();
        if (c == '.'){break;}
        head=insert(head,c);
    } while (c != '.');

    printall(head);
        
        break;
    case 2:
        odd(head);
        even(head);
        break;
    case 3:
        cout<<"Decode : pass";
        break;
    }
    }
    return 0;
}