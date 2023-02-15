#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){
    int number, n = 0;
    double max = 0, mode;
    
    vector<int> numbers;
    
    cin >> number;
    
    while (not cin.eof()){
        numbers.push_back(number);
        cin >> number;
    }
    
    for (int i = 0; i < numbers.size(); i++){
        if (numbers[0] == numbers[i]){
            n++;
        }
    }
    
    cout << numbers[0] << " aparece " << n << " veces" << endl;  
    //cout << "Mode: " << mean << endl;
    
    return 0;
}
