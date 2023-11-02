#include <iostream>
using namespace std;
struct Node {
    char value;
    struct Node* next;
};

char isempty(struct Node *S) {
    return S == nullptr;
}

Stack createstack(void) {
    return nullptr;
}

void makeempty(struct Node S) {
    while (!isempty(S)) {
        Stack temp = S;
        S = S->next;
        delete temp;
    }
}

void push(char X, struct Node *S) {
    Stack newNode = new Node;
    newNode->value = X;
    newNode->next = S;
    S = newNode;
}

void pop(struct Node* S) {
    if (!isempty(S)) {
        Stack temp = S;
        S = S->next;
        delete temp;
    }
}

char Top(struct Node *S){
    if (!isempty(S)) {
        return S->value;
    }else{
        cout<<"Empty stack";
        return 0;
    }
}
int main() {
    struct Node S = createstack();
    char a;

    cout << "Input : ";
    do {
        a = getchar();
        if (a == '.') {
            break;
        }
        if (a == '{' || a == '(' || a == '[' || a == '<') {
            push(a, S);
        } else if (a == '}' || a == ')' || a == ']' || a == '>') {
            if (isempty(S)) {
                cout << "Expected " << a << endl;
                return 0;
            } else {
                char topSymbol = Top(S);
                if ((topSymbol == '{' && a == '}') ||
                    (topSymbol == '(' && a == ')') ||
                    (topSymbol == '[' && a == ']') ||
                    (topSymbol == '<' && a == '>')) {
                    pop(S);
                } else {
                    cout << "Expected " << topSymbol << endl;
                    return 0;
                }
            }
        }
    } while (a != '.');

    if (isempty(S)) {
        cout << "Complete!" << endl;
    } else {
        char topSymbol = Top(S);
        cout << "Expected " << topSymbol << endl;
    }
    makeempty(S);
    return 0;
}