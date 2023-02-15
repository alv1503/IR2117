#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){
    int number, n;
    double max = 0, mode;
    
    vector<int> numbers;
    
    cin >> number;
    
    while (not cin.eof()){
        numbers.push_back(number);
        cin >> number;
    }
    
    for (int i = 0; i < numbers.size(); i++){
        n = 0;
        for (int j = 0; j < numbers.size(); j++){
            if (numbers[i] == numbers[j]){
                n++;
            }
        }
    }

    cout << "Mode: " << mode << endl;
    
    return 0;
}
