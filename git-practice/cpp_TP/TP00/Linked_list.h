#include <iostream>

/////////////////////////////////////////////////		STRUCTURES 	           //////////////////////////////////////////////////

struct node{
	int content;
	struct node* next;
};
typedef struct node node;
typedef node* linked_list;

/////////////////////////////////////////////////		PROTOTYPES			   //////////////////////////////////////////////////

void push(int , linked_list* );
int pop(linked_list );
void print_linked_list(linked_list );
int list_len(linked_list );
int list_check(int , linked_list );
void list_reverse(linked_list );
void list_kreverse(int , linked_list );
void del_duplicates(linked_list* );