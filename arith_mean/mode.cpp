#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){
    int number, n = 0;
    double sum, mean;
    
    vector<int> numbers;
    
    cin >> number;
    
    while (not cin.eof()){
        numbers.push_back(number);
        n++;
        cin >> number;
    }
    
    
    
    cout << "Mode: " << mean << endl;
    
    return 0;
}
