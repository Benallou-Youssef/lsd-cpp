#include <iostream>
#include <vector>

using namespace std;
using matrix= vector<vector<int>>;

void matrix_print(matrix m){		//Simply prints a matrix
	int n=m.size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}
matrix  matrix_new(int n){ 			//Initialise a new matrix.All of the matrix's elements are 0
    matrix a (n);
    for (int i = 0; i<n; i++)
    {
        a[i]= vector <int> (n,0);
    }
    return a;
}

matrix matrix_mult(matrix a, matrix b){		//Return the result of the multiplication between two given matrixes
	int n = a.size();
	matrix res = matrix_new(n);
	for(int i=0; i<n;i++)
	{
		for(int j=0; j<n;j++)
		{
			for(int k=0; k<n ; k++)
			    res[i][j]+= a[i][k] * b[k][j];
		}
	}
	return res;
}

matrix matrix_pownaive(matrix a,int n){		//Returns the result of the matrix a to the power of n by multiplying the matrix a by itself n times
	if(n==1)
		return a;
	return matrix_mult(a,matrix_pownaive(a,n-1));
}

matrix matrix_pow(matrix a, int n){			//Returns the result of the matrix a to the power of n by multiplying a by itself, then multiplying the result by itself recursivly
	if(n==1)
        return a;
    if (n%2 == 0)
        return matrix_mult(matrix_pow(a,n/2),matrix_pow(a,n/2));
    return matrix_mult(a,matrix_mult(matrix_pow(a,n/2),matrix_pow(a,n/2)));
}

int main(){
	matrix m = {{1,2,3},{4,5,6},{7,8,9}};
	printf("used matrix : \n");
	matrix_print(m);
	printf("used matrix to the power of two : \n");
	matrix_print(matrix_pow(m,2));
	
	return 0;
}