#include <iostream>
#include <Eigen/Dense>

int main(){
    int mode, n, max = 0;
    Eigen::VectorXd v(8);
    v << 2, 4, 5, 2, 2, 6, 7, 2;
    
    for (int i = 0; i < v.size(); i++){
        n = 0;
        for (int j = 0; j < v.size(); j++){
            if (v[i] == v[j]){
                n++;
            }
        }
        
        if (n > max){
            max = n;
            mode = v[0];
        }
    }
    std::cout << "Mode: " << mode << std::endl;
    
    return 0;
}
