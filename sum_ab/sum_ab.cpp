#include <iostream>

using namespace std;

int main(){
    float a = 0, b = 0, sum = 0;
    
    while (a <= 0) {cout << "Dime un número >=1 para a: "; cin >> a;}
        
    while (b <= 0) {cout << "\nDime un número >=1 para b: "; cin >> b;}
    
    for (int i = a; i <= b; i++){
        sum += i;
    }
    
    cout << "\nLa suma de los números entre " << a << " y " << b << " es: " << sum << endl;
}
