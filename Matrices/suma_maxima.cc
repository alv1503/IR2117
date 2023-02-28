#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;

int main(){
    int rows, cols, sum_max = 0, sum_diagonal = 0;
    
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
        }
        
        if (sum_row > sumMaxRow){
                sumMaxRow = sum_row;
            }
    }

    int sumMaxCol = 0;
    for(int j = 0; j < cols; j++){
        int sum_cols = 0;
        for (int i = 0; i < rows; i++){
            sum_cols += m(i,j);
        }
        
        if (sum_cols > sumMaxCol){
            sumMaxCol = sum_cols;
        } 
    }
    
    int sumMaxDiag = 0;
    
    int diag_prin = 0;
    int i = 0;
    int j = 0;
    
    while(i < cols){
        diag_prin += m(i,j);
        i++;
        j++;
    }
    
    int diag_sec = 0;
    i = cols - 1;
    j = 0;
    
    while(i >= 0){
        diag_sec += m(i, j);
        i--;
        j++;
    }
    
    if (diag_prin > diag_sec){
        sumMaxDiag = diag_prin;
    }
    
    else{
        sumMaxDiag = diag_sec;
    }
    
    std::cout << sumMaxRow << "\n" << sumMaxCol << "\n" << sumMaxDiag << std::endl;
    std::cout << "La suma maxima es: " << sum_max << std::endl;
}
