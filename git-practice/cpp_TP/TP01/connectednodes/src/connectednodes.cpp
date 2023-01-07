#include "../include/connectednodes.h"

using namespace std;
using matrix= vector<vector<int>>;

void print_list(list<int> L){				//Simply prints a given list
	for(int i : L)
		cout << i+1 << " ";
	return;
}

void print_matrix(matrix m){				//Simply prints a given matrix
	int n=m.size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
	return;
}

void dfs(int v,matrix& M,vector<bool>& visited){		//Uses a dfs algorithm.Takes a node v as argument and makes visited[i]=true for every node i linked to it, then does the same for each node i
	visited[v] = true;
		for(int i = 0; i < M.size(); i++){
			if(M[v][i] == 1 && !visited[i])
				dfs(i,M,visited);
		}
}

int count_con(matrix M){								//Counts the number of linked nodes.Uses the visited vector to know if a node i is already linked to a node that we used the algorithm on previously
	vector<bool> visited (M.size(),false);
	int count=0;
	for (int i = 0; i < M.size(); i++) {
        if (!visited[i]) {
            count++;
            dfs(i,M,visited);
        }
    }
	return count;
}
	