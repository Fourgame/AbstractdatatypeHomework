#include <iostream>
using namespace std ;
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int number;

    cout << "Enter: ";
    cin >> number;
    if(number <= 15){
            int result = fibonacci(number);
            cout << "Fibonacci of " << number << " = " << result << "\n";
    }else{
        cout << "Error, more than 15"<<"\n";
    }
}