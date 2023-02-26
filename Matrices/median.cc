#include <iostream>
#include <Eigen/Dense>
#include <algorithm>

int main(int argc, char** argv){
    double median;
    int number;
    Eigen::VectorXd v(0);
    
    std::cin >> number;
    while (not std::cin.eof()){
        v.conservativeResize(v.size() + 1);
        v(v.size() - 1) = number;
        std::cin >> number;
    }
    
    std::sort(v.data(), v.data() + v.size());
    
    int middle = v.size()/2;
    
    if (v.size() % 2 != 0){
        median = v[middle];
    }
    
    else{
        median = double(v[middle] + v[middle - 1])/2;
    }
    
    std::cout << "La mediana es: " << median << std::endl;
    
    return 0;
}
