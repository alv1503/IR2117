#include <iostream>
#include <Eigen/Dense>

using Eigen::Matrix3d;
using Eigen::Vector3d;

int main(){
    Matrix3d m = Matrix3d::Random(3,3);
    m = (m + Matrix3d::Constant(3,3,1.2)) * 50;
    
    std::cout << "m = " << std::endl << m << std::endl;
    
    Vector3d v(3);
    v << 1, 2, 3;
    
    std::cout << "m * v = " << std::endl << m * v << std::endl;
}
