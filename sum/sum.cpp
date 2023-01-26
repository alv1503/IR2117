#include <iostream>
using namespace std;

float Suma(float num, float suma);

int main(){
    float num = 0;
    float suma = 0;
    cout << "Dime un número: "; cin >> num;
    
    suma = Suma(num, suma);
    
    cout << "\nLa suma entre 1 y " << num << " es: " << suma << endl;
    
}

float Suma(float num, float suma){
    suma += (num * (1 + num))/2;
    return suma;
}
