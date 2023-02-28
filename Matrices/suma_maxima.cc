#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;

int main(){
    int rows, cols, sum_max = 0,sum_cols = 0, sum_diagonal = 0;
    
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
    
    int sumMaxRow = 0;
    for(int i = 0; i < rows; i++){
        int sum_row = 0;
        for (int j = 0; j < cols; j++){
            sum_row += m(i,j);
            
            if (sum_row > sumMaxRow){
                sumMaxRow = sum_row;
            }
        }
    }
    
    std::cout << "La suma maxima es: " << sum_max << std::endl;
}
