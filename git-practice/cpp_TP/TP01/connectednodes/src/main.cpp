#include "../include/connectednodes.h"

using namespace std;
using matrix= vector<vector<int>>;

int main(){
	matrix m={{0,1,1,0,0,0},{1,0,1,0,0,0},{1,1,0,0,0,0},{0,0,0,0,1,0},{0,0,0,1,0,0},{0,0,0,0,0,0}};
	print_matrix(m);
	printf("\n\n");
	printf("number of connected nodes : %d",count_con(m));

return 0;
}