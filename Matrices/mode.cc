#include <iostream>
#include <Eigen/Dense>

int main(){
    int mode, n, max = 0, number;
    Eigen::VectorXd v(7);
    
    v << 1, 2, 2, 6, 4, 2, 9;
    
    for (int i = 0; i < v.size(); i++){
        n = 0;
        for (int j = 0; j < v.size(); j++){
            if (v[i] == v[j]){
                n++;
            }
        }
        
        if (n > max){
            max = n;
            mode = v[i];
        }
    }
    std::cout << "Mode: " << mode << std::endl;
    
    return 0;
}
