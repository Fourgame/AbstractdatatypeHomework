#include<iostream>
using namespace std ;
void Insert_first(int *parray,int input){
    parray[0]=input;
    cout<<"\nData in list = "<<input;
}

void Insert_front(int *parray,int size,int input){
    cout<<"\nMove = "<<size-1<<" points\nData move = ";
    for (int i=size-1;i>0;i--) {
        parray[i]=parray[i-1];
        cout<<parray[i]<<" ";
    }
    parray[0]=input;
    cout<<"\nData in list : ";
    for (int j=0;j<size;j++) {
        cout<<parray[j]<<" ";
    }
}

void Insert_back(int *parray,int size,int input){
    int round=0;
    for (int j=0;j<size;j++) {
        if(input<parray[j]){
            round=j;
            break;
        }
    }
    cout<<"\nMove = "<<size-round-1<<" points\nData move = ";
    for (int i=size-1;i>round;i--) {
        parray[i]=parray[i-1];
        cout<<parray[i]<<" ";
    }
    parray[round]=input;
    cout<<"\nData in list : ";
    for (int k=0;k<size;k++) {
        cout<<parray[k]<<" ";
    }
}

void Insert_middle(int *parray,int size,int input){
    cout<<"\nMove = "<<int((size)/2)<<" points\nData move = ";
    for(int i=size-1;i>int((size-1)/2);i--){
        parray[i]=parray[i-1];
        cout<<parray[i]<<" ";
    }
    parray[int(size/2)]=input;
    cout<<"\nData in list : ";
    for (int j=0;j<size;j++) {
        cout<<parray[j]<<" ";
    }
}




int main(){
    int choose,array[10],size=0,input;
    while (choose!=5)
    {
    cout<<"\n========MENU======";
    cout<<"\n1) Insert the first value \n2) Insert front \n3) Insert last \n4) Insert middle \n5) Exit\nPlease choose >";
    cin>>choose;

    switch(choose){
        case 1 : 
        cout<<"Enter data : ";
        cin>>input;
        Insert_first(array,input);
        size+=1;
        break;

        case 2 :
        cout<<"Enter data : ";
        cin>>input;
        size+=1;
        Insert_front(array,size,input);
        break;

        case 3 :
        cout<<"Enter data : ";
        cin>>input;
        size+=1;
        Insert_back(array,size,input);
        break;

        case 4 :
        cout<<"Enter data : ";
        cin>>input;
        size+=1;
        Insert_middle(array,size,input);
        break;
        }
    cout<<"\n";
    }

}
