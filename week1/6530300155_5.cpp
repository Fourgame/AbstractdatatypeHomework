#include<iostream>
using namespace std;
int main (){
    int row[3][3],i,j;
    cout<<"Enter row #0 : ";
    cin>>row[0][0]>>row[0][1]>>row[0][2];
    cout<<"Enter row #1 : ";
    cin>>row[1][0]>>row[1][1]>>row[1][2];
    cout<<"Enter row #2 : ";
    cin>>row[2][0]>>row[2][1]>>row[2][2];
    cout<<"out put\n";
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout<<row[i][j]<<"("<<i<<","<<j<<") ";
        }
        cout<<"\n";
    }

}
