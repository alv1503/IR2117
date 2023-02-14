#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv){
    int number, n = 0;
    double median;
    
    vector<int> numbers;
    
    cin >> number;
    
    while (not cin.eof()){
        numbers.push_back(number);
        n++;
        cin >> number;
    }
    
    sort(numbers.begin(), numbers.end());
    
    for (int i = 0; i < numbers.size(); i++){
        cout << numbers[i] << endl;
    }
    
    cout << "Median: " << median << endl;
    
    return 0;
}
