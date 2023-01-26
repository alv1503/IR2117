#include <iostream>
using namespace std;

float Suma(float num, float suma);
bool ComprobarNegativo(float num);

int main(){
    float num = 0;
    
    while (ComprobarNegativo(num)){
        cout << "Dime un número: "; cin >> num;
    }
    
    float suma = 0;
    
    suma = Suma(num, suma);
    
    cout << "\nLa suma entre 1 y " << num << " es: " << suma << endl;
}

float Suma(float num, float suma){
    suma += (num * (1 + num))/2;
    return suma;
}

bool ComprobarNegativo(float num){
    if (num < 1){
        return true;
    }
    return false;
}
