#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a, b, c;
    float x1, x2;
    
    cout << "Dime el valor del valor a (ax²): "; cin >> a;
    
    cout << "Dime el valor del valor b (bx): "; cin >> b;
    
    cout << "Dime el valor del valor c: "; cin >> c;
    
    double discriminant = (b*b - 4*a*c);
    
    if (discriminant < 0){
        cout << "No hay solución" << endl;
    }
    
    else{
        x1 = (-b + sqrt(discriminant))/(2*a);
        x2 = (-b - sqrt(discriminant))/(2*a);
        
        cout << "Las soluciónes de la equación " << a << "x² + " << b << "x + " << c << " son:\n\tx1 = " << x1 << "\n\tx2 = " << x2 << endl;
    }
    
    
    return 0;
}
