#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;

int main(){
    int rows, cols, sum_tot = 0, sum_row = 0, sum_cols = 0, sum_diagonal1 = 0, sum_diagonal2 = 0;
    
    std::cout << "Columnas: "; std::cin >> cols;
    std::cout << "Filas: "; std::cin >> rows;
    
    if (rows != cols){
        std::cout << "La matriz no es cuadrada. Vuelve a introducir los datos:" << std::endl;
        
        std::cout << "Columnas: "; std::cin >> cols;
        std::cout << "Filas: "; std::cin >> rows;
    }
    
    MatrixXd m(rows, cols);std::cout << "Enter elements (row-wise): " << std::endl;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            std::cin >> m(i,j);
        }
    }
    
    std::cout << "The matrix is: " << std::endl;
    std::cout << m << std::endl;
    
    
    
    std::cout << "La suma de los elementos de la matriz es: " << sum_tot << std::endl;
}
