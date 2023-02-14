#include <iostream>

using namespace std;

int main(){
    int number, n;
    double sum, mean;
    
    cin >> number;
    
    while (not cin.eof()){
        cin >> number;
        sum += number;
        n++;
    }
    
    mean = sum/n;
    
    cout << "Arithmetic mean: " << mean << endl;
    
    return 0;
}
