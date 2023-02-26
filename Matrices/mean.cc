#include <iostream>
#include <Eigen/Dense>

int main(){
    Eigen::VectorXd v(5); //vector of size 5
    v << 1, 2, 3, 4, 5;
    
    double mean = v.mean();
    
    std::cout << "Arithmetic mean of the vector is " << mean << std::endl;
    
    return 0;
}
