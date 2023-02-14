#include <iostream>

using namespace std;

int main(int argc, char** argv){
    double m = 0, s = 0;
    int n = argc - 1;
    
    for (int i = 1; i <= n; i++){
        s += atoi(argv[i]);
    }
    
    m = s/n;
    
    cout << "Arithmetic mean: " << m << endl;
    
    return 0;
}
