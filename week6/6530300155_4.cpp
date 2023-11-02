#include <iostream>
#include <string>
using namespace std;
typedef struct node{
    int value;
    node *next;
}* Stack;
bool isempty(Stack S){
    return S == nullptr;
}
Stack stackcreative(void){
    return nullptr;
}
void push(int x,Stack& S){
    Stack a = new node;
    a->value=x;
    a->next=S;
    S=a;
}
int pop(Stack& S){
    Stack temp=S;
    Stack prev = nullptr;
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
int Top(Stack S){
    if(!isempty(S)){
        return S->value;
    }else{
        return 0;
    }
}
void makeempty(Stack& S){
    while(!isempty(S)){
        Stack temp = S;
        S=S->next;
        delete temp;
    }
}
bool isdigi(char a){
    return a>='0'&&a<='9';
}


typedef struct symbol{
    char value;
    symbol *next;
}* Stacksymbol;
bool isemptysymbol(Stacksymbol S){
    return S == nullptr;
}
Stacksymbol stacksymbolcreative(void){
    return nullptr;
}
void pushsymbol(char x,Stacksymbol& S){
    Stacksymbol a = new symbol;
    a->value=x;
    a->next=S;
    S=a;
}
char popsymbol(Stacksymbol& S){
    char a = S->value;
    Stacksymbol temp=S;
    S=S->next;
    delete temp;
    return a;
}
char Topsymbol(Stacksymbol S){
    if(!isemptysymbol(S)){
        return S->value;
    }else{
        return 0;
    }
}
void makeemptysymbol(Stacksymbol& S){
    while(!isemptysymbol(S)){
        Stacksymbol temp = S;
        S=S->next;
        delete temp;
    }
}
bool issymbol(char a){
    return a=='+'||a=='-'||a=='*'||a=='/';
}
void Postfix(int x){
    if(x!=3){
    cout<<"Infix : ";
    }
    char ch=' ',symbol=' ';
    int temp=0,a=0;
    char tempchar=' ';
    bool count = false ,chack=true;
    Stack S = stackcreative();
    Stacksymbol sym = stacksymbolcreative();
    
    do{
        ch=getchar();
        if(x==2&&ch=='('){
            Postfix(3);
        }
        if(ch!=' '){
        if(isdigi(ch)){
            temp =ch-'0';
            while(isdigi(ch)){
                ch=getchar();
                if(isdigi(ch)){
                temp*=10;
                temp+=(ch-'0');
                }
            }
            push(temp,S);
        }
        if(count){
            if(x!=3&&chack){
                cout<<"Postfix : ";
                chack=false;
            }
                while(!isempty(S)){
                    cout<<pop(S)<<" "; 
                }
                while(!isemptysymbol(sym)){
                    cout<<Topsymbol(sym)<<" ";
                    popsymbol(sym);
                }
                count=false;
            }
        if(issymbol(ch)){
            if(ch=='+'||ch=='-'){
            pushsymbol(ch,sym);
            }
            else {
                pushsymbol(ch,sym);
                count = true;
            }
        }
        }
        if(x==3&&ch==')'){
            break;
        }
    }while(ch!='.');
    if(x!=3&&chack){
                cout<<"Postfix : ";
                chack=false;
            }
    while(!isempty(S)){
                    cout<<pop(S)<<" ";
                }
    while(!isemptysymbol(sym)){
        cout<<popsymbol(sym)<<" ";
    }
    isemptysymbol(sym);
    makeempty(S);
}

int main(){
    int a;
    cout << "=======MENU======\n1. Infix\n2. Infix ()\nPlease choose >";
    cin>>a;
    if(a==1){
        Postfix(a);
    }
    if(a==2){
        Postfix(a);
    }
}