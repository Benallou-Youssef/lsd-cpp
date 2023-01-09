#include <iostream>
using namespace std;

template <typename T> T multiply(T x, int y){
    return x*y;
}

int main(){
    cout << multiply(2,3)<<endl;
    cout << multiply(1.2,3)<< endl;
    return 0;
}
