#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;

int main(){
    int rows, cols, sum = 0;
    
    std::cout << "Columnas: "; std::cin >> cols;
    std::cout << "Filas: "; std::cin >> rows;
    
    MatrixXd m(rows, cols);std::cout << "Enter elements (row-wise): " << std::endl;

    std::cout << "The matrix is: " << std::endl;
    std::cout << m << std::endl;
    
    std::cout << "La suma de los elementos de la matriz es: " << sum << std::endl;
}
