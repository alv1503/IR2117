#include <iostream>
#include <Eigen/Dense>

int main(){
    int mode;
    Eigen::VectorXd v(8);
    v << 2, 4, 5, 2, 2, 6, 7, 2;
    
    
    std::cout << "Mode: " << mode << std::endl;
    
    return 0;
}
