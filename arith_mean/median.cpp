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
        cin >> number;
    }
    
    sort(numbers.begin(), numbers.end());
    
    if (numbers.size() % 2 == 0) {
        cout << "Even" << endl;
    }
    
    else{
        cout << "Odd" << endl;
    }    
    
    cout << "Median: " << median << endl;
    
    return 0;
}
