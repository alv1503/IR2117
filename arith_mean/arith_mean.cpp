#include <iostream>

using namespace std;

int main(){
    int number, n;
    double sum, mean;
    
    cout << "Dime un número: "; cin >> number;
    
    while (!cin.eof()){
        cout << "Dime un numero: "; cin >> number;
        sum += number;
        n++;
    }
    
    mean = sum/n;
    
    cout << "Arithmetic mean: " << mean << endl;
    
    return 0;
}
