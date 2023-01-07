#include <iostream>
using namespace std;

template <typename T>
T powiter(T a, int n){
	T res=1;
	int neg=0;
	if(n < 0){			//If the power is negative, we inverse its sign and we store the information that it was negative previously
		neg=1;
		n = -n;
	}
	if(a == 0 && (neg || n == 0)){		//Exit when the given number is undefined
		printf("0 to the power of %d is undefined ! ",-n);
		exit(EXIT_FAILURE);
	}
	for(int i = 0 ; i < n ; i++)
		res = res * a;
	if(neg)
		res = 1/res;
	return res;
}

template <typename T2>
T2 powrec(T2 a, int n){
	if(n == 0)
		return 1;
	else
		return a*powrec(a,n-1);
}

int main(){
    cout << powiter(2 ,3) << endl ;
	cout << powiter(1.2 ,3) << endl ;
	cout << powrec(2 ,3) << endl ;
	cout << powrec(1.2 ,3) << endl ;
    return 0;
}