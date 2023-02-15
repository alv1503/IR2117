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
    
    int middle = numbers.size()/2;
    
    if (numbers.size() % 2 == 0) {
        median = double(numbers[middle] + numbers[middle-1])/2;
    }
    
    else{
        median = numbers[middle];
    }    
    
    cout << "Median: " << median << endl;
    
    return 0;
}
