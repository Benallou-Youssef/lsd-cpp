#include "../include/shortestpath.h"

using namespace std;
using matrix= vector<vector<int>>;

int main(){
	matrix m={{0,1,1,1,0,0},{1,0,1,1,1,0},{1,1,0,1,1,0},{1,1,1,0,0,0},{0,1,1,0,0,1},{0,0,0,0,1,0}};
	print_matrix(m);
	printf("\n\n");
	print_list(shortestpath(m,5));

return 0;
}