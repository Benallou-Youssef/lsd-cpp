#include "../include/shortestpath.h"

using namespace std;
using matrix= vector<vector<int>>;

void print_list(list<int> L){					//Simply prints a given list
	for(int i : L)
		cout << i+1 << " ";
	return;
}

void print_matrix(matrix m){					//Simply prints a given matrix
	int n=m.size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
	return;
}

list<int> linkednodes(int n,matrix m){			//Takes an adjencency matrix and an int n as arguments, and returns a list containing all the nodes linked to the node n
	list<int> linked;
	for(int i = 0; i < m.size(); i++){
		if(m[n][i] == 1)
			linked.push_back(i);
	}
	return linked;
}

vector<int> solve(matrix m){					//Returns for each node's i the previous node in the fastest path from beginning to the node i (as a list) using a bfs algorithm
	list<int> queue;		//A queue that is filled with the beginning node, then we add the connected nodes to the beginning one, then the connected ones to the previous and so on
	queue.push_back(0);
	
	vector<bool> visited (m.size(),false);		//A vector with a size equal to the number of nodes.Stores if we already visited the node i during our search
	visited[0]=true;
	
	vector<int> prev (m.size(),-1);				//A vector with a size equal to the number of nodes.For each node i stores the previous node for it in the shortest path.If at the end of the algorithm prev[i]==-1, it means that the node i cannot be accessed by beginning with the node 1
	int node;
	while(!queue.empty()){
		node = queue.front();
		queue.pop_front();
		list<int> linked = linkednodes(node,m);
		for(int i : linked){
			if(!visited[i]){
				queue.push_back(i);
				visited[i]=true;
				prev[i]=node;
			}
		}
	}
	return prev;
}

list<int> reconstructpath(int k,vector<int> prev){		//Uses the list that is returned by the solve function, and construct the path from beginning to k, by beginning with k and going backwards
	list<int> path;
	for(int i=k; i != -1; i=prev[i])
		path.push_front(i);
	if(path.front() == 0)
		return path;
	cout << "No path was found" << endl;
	exit(EXIT_FAILURE);
}

list<int> shortestpath(matrix m,int k){					//Returns the shortest path from the beginning to the node k by using the reconstructpath and solve functions
	return reconstructpath(k,solve(m));
}
