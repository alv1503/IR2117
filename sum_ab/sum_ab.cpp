#include <iostream>

using namespace std;

int main(){
    float a = 0, b = 0, sum = 0;
    
    while (a <= 0) {cout << "Dime un número >=1: "; cin >> a;}
        
    while (b <= 0) {cout << "\nDime otro número >=1: "; cin >> b;}
    
    if (b < a){
        float aux = a;
        a = b;
        b = aux;
    }
    
    for (int i = a; i <= b; i++){
        sum += i;
    }
    
    cout << "\nLa suma de los números entre " << a << " y " << b << " es: " << sum << endl;
    
    return 0;
}
