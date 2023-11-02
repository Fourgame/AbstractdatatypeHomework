#include<iostream>
using namespace std;
float celciustofahrenheit(float c){
    float f;
    f=c*9/5+32;
    return f;
}
int main (){
    float c,f;
    cout<<"Enter Celcius : ";
    cin>>c;
    c=celciustofahrenheit(c);
    printf("Fahrenheit = %.1f",c);
}