#include <iostream>
#include <Eigen/Dense>
#include <algorithm>

int main(){
    double median;
    
    Eigen::VectorXd v(4);
    v << 4, 7, 1, 12;
    
    //Eigen::VectorXd v(7);
    //v << 5, 2, 4, 3, 7, 8, 1;
    
    std::sort(v.data(), v.data() + v.size());
    
    std::cout << "La mediana es: " << median << std::endl;
    
    return 0;
}
