#include <iostream>
#include <Eigen/Dense>

int main(){
    int mode, n, max = 0, number;
    Eigen::VectorXd v(0);
    
    std::cin >> number;
    while (not std::cin.eof()){
        v.conservativeResize(v.size() + 1);
        v(v.size() - 1) = number;
        std::cin >> number;
    }
    
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
