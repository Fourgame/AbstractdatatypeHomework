#include <iostream>
using namespace std;
typedef struct Node {
    char value;
    struct Node* next;
} * Stack;

char isempty(Stack S) {
    return S == nullptr;
}

Stack createstack(void) {
    return nullptr;
}

void makeempty(Stack S) {
    while (S != nullptr) {
        Stack temp = S;
        S = S->next;
        delete temp;
    }
}

void push(int X, Stack& S) {
    Stack newNode = new Node;
    newNode->value = X;
    newNode->next = S;
    S = newNode;
}

void pop(Stack& S) {
    if (S != nullptr) {
        Stack temp = S;
        S = S->next;
        delete temp;
    }
}

char Top(Stack& S){
    if (!isempty(S)) {
        return S->value;
    }else{
        cout<<"Empty stack";
        return 0;
    }
}

int main() {
    Stack S = createstack();
    char a;
    int count=0;
    cout <<"Input : ";
    do{
    a=getchar();
    if(a=='.'){break;}
    if(a=='{'||a=='('||a=='['||a=='<'){
    push(a,S);
    cout<<Top(S)<<endl;
    count++;
    }
    }while(a!='.');
    cout<<"Open = "<<count;
    return 0;
}