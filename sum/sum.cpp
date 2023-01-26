#include <iostream>
using namespace std;

int main(){
    int num;
    
    cout << "Dime un número: "; cin >> num;
    
    int suma = (num * (1 + num))/2;
    
    cout << "\nLa suma entre 1 y " << num << " es: " << suma << endl;
    
}
