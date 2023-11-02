#include <iostream>
#include <string>
using namespace std;
typedef struct Node {
    int value;
    struct Node* next;
} * Stack;

int isempty(Stack S) {
    return S == nullptr;
}

void makeempty(Stack& S) { 
    while (!isempty(S)) {
        Stack temp = S;
        S = S->next;
        delete temp;
    }
}

Stack createstack(void) {
    return nullptr;
}

void push(int X, Stack& S) {
    Stack newNode = new Node;
    newNode->value = X;
    newNode->next = S;
    S = newNode;
}

int pop(Stack& S) {
    if (!isempty(S)) {
        int a = S->value;
        Stack temp = S;
        S = S->next;
        delete temp;
        return a;
    }
}

int Top(Stack S){
    if (!isempty(S)) {
        return S->value;
    }else{
        cout<<"Empty stack";
        return 0;
    }
}
bool isdigit(char a){
    return a>='0'&& a<='9';
}

int main() {
    Stack S = createstack();
    char a;
    char symbol;
    int value,result=0;
    int temp=0;
    cout << "Input : ";
    do {
        a=getchar();
        if(isdigit(a)){
            temp = a-'0';
            while(isdigit(a)){
            a=getchar();
            if(isdigit(a)){
            temp *= 10;
            temp += (a-'0');
            }
            }
            cout<<temp<<" digit\n";
            push(temp,S);
        }
        if(a=='+'){
            symbol=a;
            cout<<symbol<<" digit\n";
        }
    } while (a != '.');
    if(symbol=='+'){
    while (!isempty(S)) {
        result += Top(S);
        pop(S);
    }
    cout<<"Output = "<<result;
    }
    else{
        cout<<"What Symbol";
    }
    makeempty(S);
    return 0;
}