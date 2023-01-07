#include <iostream>
#include <vector>
#include <list>

void print_list(std::list<int>);
void print_matrix(std::vector<std::vector<int>>);

std::list<int> linkednodes(int,std::vector<std::vector<int>>);
std::vector<int> solve(std::vector<std::vector<int>>);
std::list<int> reconstructpath(int,std::vector<int>);
std::list<int> shortestpath(std::vector<std::vector<int>>,int);